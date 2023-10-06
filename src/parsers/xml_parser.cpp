#include "parsers/xml_parser.hpp"
#include "domain/museum.hpp"
#include "domain/node.hpp"
#include "domain/node_type.hpp"
#include "domain/edge.hpp"
#include <iostream>
#include <sstream>

std::shared_ptr<Museum> XMLParser::parse(const std::string& xmlData) {
    int numRows = -1;
    int numCols = -1;
    std::vector<std::shared_ptr<NodeType>> nodeTypes;
    std::vector<std::shared_ptr<Node>> nodes;

    try {
        std::istringstream xmlStream(xmlData);

        // Temporary variables to store parsing state
        bool insideNodeTypes = false;
        bool insideNodes = false;
        char currentTag = '\0';

        std::string line;
        while (std::getline(xmlStream, line)) {
            // Remove leading and trailing whitespaces from the line
            line = trim(line);

            if (line.empty()) {
                continue;
            }

            if (line.find("<canvas rows=") != std::string::npos) {
                // Parse numRows and numCols from the canvas tag
                std::vector<int> rowsCols = parseDimensions(line);
                numRows = rowsCols[0];
                numCols = rowsCols[1];
            }
            else if (line.find("<nodeTypes>") != std::string::npos) {
                // Start parsing node types
                insideNodeTypes = true;
            }
            else if (line.find("</nodeTypes>") != std::string::npos) {
                // End of nodeTypes section
                insideNodeTypes = false;
            }
            else if (line.find("<nodes>") != std::string::npos) {
                // Start parsing nodes
                insideNodes = true;
            }
            else if (line.find("</nodes>") != std::string::npos) {
                // End of nodes section
                insideNodes = false;
            }
            else if (insideNodeTypes) {
                // Parse node type information
                std::shared_ptr<NodeType> nodeType = parseNodeType(line);
                nodeTypes.push_back(nodeType);
            }
            else if (insideNodes) {
                // Parse node information and add to the museum
                if (line.find("<") != std::string::npos && line.find(">") != std::string::npos) {
                    size_t tagStart = line.find("<") + 1;
                    size_t tagEnd = line.find(">");
                    if (tagStart != std::string::npos && tagEnd != std::string::npos) {
                        char nodeTag = line[tagStart];

                        for (const auto& nodeType : nodeTypes) {
                            if (nodeType->tag == nodeTag) {
                                std::vector<std::string> edgesStrings;

                                std::string xml_line;
                                while (std::getline(xmlStream, xml_line)) {
                                    xml_line = trim(xml_line);
                                    if (xml_line.empty()) {
                                        continue;
                                    }
                                    if (xml_line.find("<edges>") != std::string::npos) {
                                        continue;
                                    }
                                    else if (xml_line.find("</edges>") != std::string::npos) {
                                        break;
                                    }
                                    edgesStrings.push_back(xml_line);
                                }
                                std::shared_ptr<Node> node = parseNode(line, nodeTag, edgesStrings);
                                nodes.push_back(node);
                                break;
                            }
                        }
                    }
                }
            }

        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing XML: " << e.what() << std::endl;
    }

    return MuseumFactory::createMuseum(numRows, numCols, nodeTypes, nodes);
}

// Helper function to trim leading and trailing whitespace
std::string XMLParser::trim(const std::string& str) {
    std::string result = str;
    size_t start = result.find_first_not_of(" \t\r\n");
    size_t end = result.find_last_not_of(" \t\r\n");
    if (start != std::string::npos && end != std::string::npos) {
        result = result.substr(start, end - start + 1);
    }
    else {
        result.clear();
    }
    return result;
}

// Helper function to parse numRows and numCols from the canvas tag
std::vector<int> XMLParser::parseDimensions(const std::string& line) {
    std::vector<int> res;

    size_t rowsPos = line.find("rows=\"") + 6;
    size_t colsPos = line.find("cols=\"") + 6;
    size_t rowsEnd = line.find("\"", rowsPos);
    size_t colsEnd = line.find("\"", colsPos);

    if (rowsPos != std::string::npos && colsPos != std::string::npos &&
        rowsEnd != std::string::npos && colsEnd != std::string::npos) {
        int numRows = std::stoi(line.substr(rowsPos, rowsEnd - rowsPos));
        int numCols = std::stoi(line.substr(colsPos, colsEnd - colsPos));

        res.push_back(numRows);
        res.push_back(numCols);
    }
    return res;
}

// Helper function to parse node type information
std::shared_ptr<NodeType> XMLParser::parseNodeType(const std::string& line) {
    std::shared_ptr<NodeType> nodeType = std::make_shared<NodeType>();

    size_t tagPos = line.find("tag=\"") + 5;
    size_t redPos = line.find("red=\"") + 5;
    size_t greenPos = line.find("green=\"") + 7;
    size_t bluePos = line.find("blue=\"") + 6;
    size_t weightPos = line.find("weight=\"") + 8;

    size_t tagEnd = line.find("\"", tagPos);
    size_t redEnd = line.find("\"", redPos);
    size_t greenEnd = line.find("\"", greenPos);
    size_t blueEnd = line.find("\"", bluePos);
    size_t weightEnd = line.find("\"", weightPos);

    if (tagPos != std::string::npos && tagEnd != std::string::npos &&
        redPos != std::string::npos && redEnd != std::string::npos &&
        greenPos != std::string::npos && greenEnd != std::string::npos &&
        bluePos != std::string::npos && blueEnd != std::string::npos &&
        weightPos != std::string::npos && weightEnd != std::string::npos) {

        nodeType->tag = (line[tagPos]);
        nodeType->red = (std::stoi(line.substr(redPos, redEnd - redPos)));
        nodeType->green = (std::stoi(line.substr(greenPos, greenEnd - greenPos)));
        nodeType->blue = (std::stoi(line.substr(bluePos, blueEnd - bluePos)));
        nodeType->weight = (std::stoi(line.substr(weightPos, weightEnd - weightPos)));
    }

    return nodeType;
}

// Helper function to parse node information including edges
std::shared_ptr<Node> XMLParser::parseNode(const std::string& line, char tag, std::vector<std::string> edgesStrings) {
    std::shared_ptr<Node> node = std::make_shared<Node>();
    node->tag = tag;

    size_t xPos = line.find("x=\"") + 3;
    size_t yPos = line.find("y=\"") + 3;
    size_t xEnd = line.find("\"", xPos);
    size_t yEnd = line.find("\"", yPos);

    if (xPos != std::string::npos && xEnd != std::string::npos &&
        yPos != std::string::npos && yEnd != std::string::npos) {

        node->x = (std::stoi(line.substr(xPos, xEnd - xPos)));
        node->y = (std::stoi(line.substr(yPos, yEnd - yPos)));
    }

    // Process edges
    for (const std::string& edgeLine : edgesStrings) {
        size_t edgeXPos = edgeLine.find("x=\"") + 3;
        size_t edgeYPos = edgeLine.find("y=\"") + 3;
        size_t edgeXEnd = edgeLine.find("\"", edgeXPos);
        size_t edgeYEnd = edgeLine.find("\"", edgeYPos);

        if (edgeXPos != std::string::npos && edgeXEnd != std::string::npos &&
            edgeYPos != std::string::npos && edgeYEnd != std::string::npos) {
            int edgeX = std::stoi(edgeLine.substr(edgeXPos, edgeXEnd - edgeXPos));
            int edgeY = std::stoi(edgeLine.substr(edgeYPos, edgeYEnd - edgeYPos));
            std::shared_ptr<Edge> edge = std::make_shared<Edge>();
            edge->x = edgeX;
            edge->y = edgeY;
            node->edges.push_back(edge);
        }
    }

    return node;
}

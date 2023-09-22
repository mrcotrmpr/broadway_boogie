#include "parsers/xml_parser.hpp"
#include "parsers/visitors/visitor.hpp"
#include "parsers/visitors/canvas_visitor.hpp"
#include "parsers/visitors/nodes_visitor.hpp"
#include "parsers/visitors/node_visitor.hpp"
#include "parsers/visitors/edge_visitor.hpp"
#include <iostream>
#include <sstream>

std::shared_ptr<Museum> XMLParser::parse(const std::string& xmlData) {

    std::shared_ptr<Museum> museum = std::make_shared<Museum>();
    std::shared_ptr<Visitor> currentVisitor;

    std::istringstream xmlStream(xmlData);
    std::string line;
    while (std::getline(xmlStream, line)) {
        line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](int ch) {
            return !std::isspace(ch);
            }));

        if (line.find("<canvas") != std::string::npos) {
            currentVisitor = std::make_shared<CanvasVisitor>();
        }
        else if (line.find("<nodeTypes>") != std::string::npos) {
            // Nodetype logic
        }
        else if (line.find("<nodes>") != std::string::npos) {
            currentVisitor = std::make_shared<NodesVisitor>();
        }
        else if (line.find("Check hier voor de nodeTypes die eerder gevonden zijn") != std::string::npos) {
            currentVisitor = std::make_shared<NodeVisitor>();
        }
        else if (line.find("<edge") != std::string::npos) {
            currentVisitor = std::make_shared<EdgeVisitor>();
        }

        if (currentVisitor) {
            currentVisitor->visit(museum);
        }
    }

    return museum;
}

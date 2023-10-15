#include "managers/museum_manager.hpp"
#include "domain/states/blue_state.hpp"
#include "domain/states/red_state.hpp"
#include "domain/states/yellow_state.hpp"
#include "domain/states/gray_state.hpp"

std::shared_ptr<Museum> MuseumManager::loadMuseum()
{
    const std::string xml_filename = "C:\\Users\\marco\\source\\repos\\test\\data\\graph.xml";
    const std::string xml_url = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/graph.xml?alt=media";

    std::string xml_content = webReader.read(xml_url);
    return xmlParser.parse(xml_content);
}

void MuseumManager::renderMuseum(SDL_Renderer* renderer, std::shared_ptr<Museum> museum, float scaleX, float scaleY) {
    std::unordered_map<char, std::shared_ptr<NodeType>> nodeTypeMap;
    for (auto type : museum->nodeTypes) {
        nodeTypeMap[type->tag] = type;
    }

    for (const auto& node : museum->nodes) {
        auto nodeTypeIt = nodeTypeMap.find(node->tag);

        if (nodeTypeIt != nodeTypeMap.end()) {
            SDL_SetRenderDrawColor(renderer, nodeTypeIt->second->red, nodeTypeIt->second->green, nodeTypeIt->second->blue, 255);
            if (node->tag == 'R') {
                node->state = std::make_unique<RedState>();
            }
            else if (node->tag == 'B') {
                node->state = std::make_unique<BlueState>();
            }
            else if (node->tag == 'Y') {
                node->state = std::make_unique<YellowState>();
            }
            else if (node->tag == 'G') {
                node->state = std::make_unique<GrayState>();
            }
        }
        else {
            SDL_SetRenderDrawColor(renderer, 128, 0, 128, 255);
        }

        // Calculate the screen coordinates of the node
        SDL_Rect nodeRect;
        nodeRect.x = static_cast<int>(node->x * scaleX);
        nodeRect.y = static_cast<int>(node->y * scaleY);
        nodeRect.w = 14;
        nodeRect.h = 14;
        SDL_RenderFillRect(renderer, &nodeRect);

        // Pathfinding shortest path
        if (node->visited == 'S') {
            // white square
            SDL_Rect whiteSquare;
            whiteSquare.w = 4;
            whiteSquare.h = 4;
            whiteSquare.x = static_cast<int>(node->x * scaleX) + 6;
            whiteSquare.y = static_cast<int>(node->y * scaleY) + 6;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &whiteSquare);
        }
        else if (node->visited == 'P') {
            // black square
            SDL_Rect blackSquare;
            blackSquare.w = 4;
            blackSquare.h = 4;
            blackSquare.x = static_cast<int>(node->x * scaleX) + 6;
            blackSquare.y = static_cast<int>(node->y * scaleY) + 6;
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &blackSquare);
        }
        else if (node->visited == 'V') {
            // black edges
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_Rect outlineRect;
            outlineRect.x = static_cast<int>(node->x * scaleX);
            outlineRect.y = static_cast<int>(node->y * scaleY);
            outlineRect.w = 14;
            outlineRect.h = 14;
            SDL_RenderDrawRect(renderer, &outlineRect);
        }

        // Draw edges
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (const auto& edge : node->edges) {
            SDL_RenderDrawLine(renderer,
                static_cast<int>(node->x * scaleX),
                static_cast<int>(node->y * scaleY),
                static_cast<int>(edge->x * scaleX),
                static_cast<int>(edge->y * scaleY)
            );
        }
    }
}

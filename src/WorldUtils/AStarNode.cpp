//
// Created by benjamin on 05.07.22.
//

#include "AStarNode.h"

namespace RobbyTheRobot{

    AStarNode::AStarNode(Vector2i coordinates, std::shared_ptr<AStarNode> parent, double gCost, double hCost) {

        this->coordinates = coordinates;
        this->parent = parent;
        this->gCost = gCost;
        this->hCost = hCost;
        this->fCost = this->gCost + this->hCost;
        this->name = "Node-"+ std::to_string(coordinates.getX()) + std::to_string(coordinates.getY());

    }

    void AStarNode::setHCost(double hCostP) {
        this->hCost = hCostP;
        this->fCost = this->hCost + this->gCost;
    }

    void AStarNode::setGCost(double gCostP) {
        this->gCost = gCostP;
        this->fCost = this->hCost + this->gCost;
    }

    bool operator<(const AStarNode &a, const AStarNode &b) {
        return (a.getFCost() < b.getFCost());
    }

}
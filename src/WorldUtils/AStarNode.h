//
// Created by benjamin on 05.07.22.
//

#ifndef ROBOT_ASTARNODE_H
#define ROBOT_ASTARNODE_H

#include <string>
#include <memory>
#include "Vector2i.h"

namespace RobbyTheRobot {

    class AStarNode {

    public:

        AStarNode(Vector2i coordinates, std::shared_ptr<AStarNode> parent, double gCost, double hCost);

        std::string getName() const { return name; }

        void setHCost(double hCostP);

        void setGCost(double gCostP);

        void setParent(std::shared_ptr<AStarNode> p) { this->parent = p; }

        std::shared_ptr<AStarNode> getParent() { return this->parent; }

        double getFCost() const { return fCost; }

        double getGCost() const { return gCost; }

        double getHCost() const { return hCost; }

        Vector2i getCoordinates() const { return coordinates; }

        void setInOpenList(bool inList) { this->inOpenList = inList; }

        void setInClosedList(bool inList) { this->inClosedList = inList; }

        bool isInOpenList () const { return this->inOpenList; }

        bool isInClosedList() const { return this->inClosedList; }

        friend bool operator<(const AStarNode& a, const AStarNode& b);

    private:

        std::string name;

        std::shared_ptr<AStarNode> parent;

        Vector2i coordinates;

        bool inOpenList;

        bool inClosedList;

        double gCost;

        double hCost;

        double fCost;

    };

}

#endif //ROBOT_ASTARNODE_H

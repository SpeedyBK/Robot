//
// Created by benjamin on 05.07.22.
//

#ifndef ROBOT_ASTARNODE_H
#define ROBOT_ASTARNODE_H

#include <string>
#include "Vector2i.h"

namespace RobbyTheRobot {

    class AStarNode {

    public:

        AStarNode(Vector2i coordinates, AStarNode* parent, double gCost, double hCost);

        std::string getName() const { return name; }

        void setHCost(double hCostP);

        void setGCost(double gCostP);

        double getFCost() const { return fCost; }

        double getGCost() const { return gCost; }

        double getHCost() const { return hCost; }

        Vector2i getCoordinates() const { return coordinates; }

        friend bool operator<(const AStarNode& a, const AStarNode& b);

        friend bool operator>(const AStarNode& a, const AStarNode& b);

    private:

        std::string name;

        AStarNode* parent;

        Vector2i coordinates;

        double gCost;

        double hCost;

        double fCost;

    };

}

#endif //ROBOT_ASTARNODE_H

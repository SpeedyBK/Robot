//
// Created by benjamin on 05.07.22.
//

#ifndef ROBOT_ASTARSEARCH_H
#define ROBOT_ASTARSEARCH_H

#include <queue>
#include <set>
#include <memory>
#include "AStarNode.h"
#include "Vector2i.h"
#include "../Display.h"

namespace RobbyTheRobot {

    using namespace std;

    class AStarSearch {

    public:

        AStarSearch(Display* dp, Vector2i start, Vector2i end);

        ~AStarSearch() = default;

        void visitTest();

    private:

        Vector2i start;

        Vector2i end;

        Display* d;

        queue<AStarNode> openList;

        set<AStarNode> closedList;

    };
}

#endif //ROBOT_ASTARSEARCH_H

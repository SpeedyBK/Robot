//
// Created by benjamin on 05.07.22.
//

#ifndef ROBOT_ASTARSEARCH_H
#define ROBOT_ASTARSEARCH_H

#include <deque>
#include "AStarNode.h"
#include "Vector2i.h"
#include "../Display.h"
#include <functional>
#include <queue>

namespace RobbyTheRobot {

    using namespace std;

    class lesscmp
    {
    public:
        bool operator()(const shared_ptr<AStarNode>& x, const shared_ptr<AStarNode>& y) const { return *y < *x; }
    };

    class AStarSearch {

    public:

        AStarSearch(Display* dp, shared_ptr<World> wp);

        ~AStarSearch() = default;

        void startEndTest(Vector2i& start, Vector2i& end);

        void findPath(Vector2i start, Vector2i end);

        void findPathPQ(Vector2i start, Vector2i end);

        void setHeuristicFactor(double hF) { this->heuristicFactor = hF; }

        void createAllNodes();

        void resetAllNodes();

    private:

        shared_ptr<AStarNode> getNodeByVec(Vector2i pos);

        static bool isInList(Vector2i& coordinates, deque<shared_ptr<AStarNode>>& L);

        void expandNode(const shared_ptr<AStarNode>& currentNode, Vector2i& end);

        void expandNodePQ(const shared_ptr<AStarNode>& currentNode, Vector2i& end);

        void visDistance(Vector2i& start, Vector2i& end);

        void visualize(Vector2i coordinates, int blue, int green);

        static double getDistance(Vector2i& a, Vector2i& b);

        double heuristicFactor;

        Display* d;

        shared_ptr<World> wp;

        deque<deque<shared_ptr<AStarNode>>> allNodes;

        deque<shared_ptr<AStarNode>> openList;
        priority_queue<shared_ptr<AStarNode>, deque<shared_ptr<AStarNode>>, lesscmp> openListPQ;

        deque<shared_ptr<AStarNode>> closedList;
        set<shared_ptr<AStarNode>>closedListPQ;

    };
}

#endif //ROBOT_ASTARSEARCH_H

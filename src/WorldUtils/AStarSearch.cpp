//
// Created by benjamin on 05.07.22.
//

#include <unistd.h>
#include <cmath>
#include "AStarSearch.h"
#include "../Exception.h"

namespace RobbyTheRobot {

    AStarSearch::AStarSearch(Display *dp, shared_ptr<World> wp, Vector2i start, Vector2i end) {
        this->d = dp;
        this->start = start;
        this->end = end;
        this->wp = wp;
    }

    void AStarSearch::findPath() {
        cout << "Searching Path" << endl;
        FibonacciHeap<AStarNode> openList;
        set<AStarNode> closedList;

        AStarNode currentNode(start, nullptr, 0, getDistance(start, end));
        visDistance(start, end);
        openList.push(currentNode);
        int i = 0;
        while (!openList.empty()){
            currentNode = openList.get_extract_min();
            cout << "Current Node: " << currentNode.getName() << endl;
            cout << currentNode.getName() << "-" << currentNode.getGCost() << "-" << currentNode.getHCost() << endl;
            if (currentNode.getCoordinates() == end){
                cout << i << ". End reached ..." << endl;
                throw (RobbyTheRobot::Exception("Stop"));
                return;
            }
            closedList.insert(currentNode);
            expandNode(currentNode, openList, closedList);
            i++;
        }
    }

    void AStarSearch::expandNode (AStarNode node, FibonacciHeap<AStarNode>& oL, set<AStarNode>& cL){
        bool validField[9] = {false, true, false,
                              true, false, true,
                              false, true, false};
        for (int i = 0; i < 9; i++){
            //When it is not a valid move -> skip
            if (!validField[i]){
                continue;
            }
            //Creating nextNodes Coordinates.
            int x = node.getCoordinates().getX();
            int y = node.getCoordinates().getY();
            int dx = i % 3 - 1;
            int dy = i / 3 - 1;
            Vector2i coordinatesOfNewNode = {x+dx, y+dy};
            //When out of bounds -> skip
            if (coordinatesOfNewNode.getX() >= wp->get_n() or
                coordinatesOfNewNode.getX() < 0 or
                coordinatesOfNewNode.getY() >= wp->get_n() or
                coordinatesOfNewNode.getY() < 0){
                continue;
            }
            Vector2i coordinatesOfOldNode = node.getCoordinates();
            double gCost = node.getGCost() + getDistance(coordinatesOfOldNode, coordinatesOfNewNode);
            double hCost = getDistance(coordinatesOfNewNode, end);
            AStarNode newNode(coordinatesOfNewNode, &node, gCost, hCost);
            //When on closed list -> skip
            for (auto &it : cL) {
            }
            oL.push(newNode);
            cout << "Expand Node:" << newNode.getName() << "-" << newNode.getGCost() << "-" << newNode.getHCost() << endl;
        }
    }

    double AStarSearch::getDistance(Vector2i& a, Vector2i& b) {
        int dx = a.getX() - b.getX();
        int dy = a.getY() - b.getY();
        return sqrt((dx*dx + dy*dy));
    }

    void AStarSearch::visualize(Vector2i coordinates, int blue, int green) {
        auto winPtr = d->getWindowPtr();
        d->drawVisitedFields(winPtr, coordinates, green, blue);
    }

    void AStarSearch::startEndTest() {
        auto winPtr = d->getWindowPtr();
        d->drawVisitedFields(winPtr, start, 0, 124);
        d->drawVisitedFields(winPtr, end, 0, 124);
    }

    void AStarSearch::visDistance(Vector2i& s, Vector2i& e) {
        d->calc_line(s, e);
        d->getWindowPtr()->display();
    }
}
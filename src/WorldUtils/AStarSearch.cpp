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
        this->heuristicFactor = 3;
    }

    void AStarSearch::findPath() {
        //Create Start-Node:
        auto currentNode = make_shared<AStarNode>(start,
                                                                          nullptr,
                                                                          0,
                                                                          heuristicFactor * getDistance(start, end));
        openList.push_back(currentNode);
        int i = 0;
        while (!openList.empty()){
            currentNode = openList.front();
            openList.pop_front();
            visualize(currentNode->getCoordinates(), 255, 0);
            if (currentNode->getCoordinates() == end){
                cout << "Goal reached!" << endl;
                usleep(100000);
                while(currentNode->getParent() != nullptr){
                    visualize(currentNode->getCoordinates(), 0, 255);
                    currentNode = currentNode->getParent();
                    cout << currentNode->getName() << endl;
                }
                visualize(currentNode->getCoordinates(), 0, 255);
                usleep(10000000);
                throw (RobbyTheRobot::Exception("Goal reached!"));
                return;
            }
            closedList.push_back(currentNode);
            expandNode(currentNode);
            i++;
        }
    }

    void AStarSearch::expandNode (const shared_ptr<AStarNode>& currentNode){
        cout << "Expanding " << currentNode->getName() << endl;
        //We can only move left, right, up and down.
        std::array<bool, 9> validFields = { false, true, false,
                                            true, false, true,
                                            false, true, false};
        for (int i = 0; i < 9; i++){
            if (!validFields[i]){
                continue;
            }
            int x = currentNode->getCoordinates().getX();
            int y = currentNode->getCoordinates().getY();
            int xi = (i % 3) - 1;
            int yi = (i / 3) - 1;
            Vector2i nextPosition(x+xi, y+yi);
            if ((nextPosition.getX() < 0 or nextPosition.getY() < 0) or
                (nextPosition.getX() >= wp->get_n() or nextPosition.getY() >= wp->get_n())){
                continue;
            }
            Vector2i currPosition(currentNode->getCoordinates().getX(), currentNode->getCoordinates().getY());
            double gCost = currentNode->getGCost()
                         + getDistance(currPosition, nextPosition)
                         * wp->get_field_time(nextPosition.getX(), nextPosition.getY());
            double hCost = heuristicFactor * getDistance(nextPosition, end);
            shared_ptr<AStarNode>newNode = make_shared<AStarNode>(nextPosition, currentNode, gCost, hCost);
            if (isInList(nextPosition, closedList) and gCost >= newNode->getGCost()){
                continue;
            }
            if (!isInList(nextPosition, openList) or gCost < newNode->getGCost()){
                openList.push_front(newNode);
                sort(openList.begin(), openList.end(), [](shared_ptr<AStarNode>& a, shared_ptr<AStarNode>& b){
                    return *a < *b;
                });
            }
        }
        for (auto &it : openList){
            cout << it->getName() << "-" << it->getFCost() << "-" << it->getHCost() << endl;
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
        winPtr->display();
        usleep(50000);
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

    bool AStarSearch::isInList(Vector2i& coordinates, deque<shared_ptr<AStarNode>>& L) {
        return std::any_of(L.begin(), L.end(),
               [coordinates](shared_ptr<AStarNode>& y) { return coordinates == y->getCoordinates(); });
    }
}
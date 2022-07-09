//
// Created by benjamin on 05.07.22.
//

#include <unistd.h>
#include <cmath>
#include "AStarSearch.h"
#include "../Exception.h"

namespace RobbyTheRobot {

    AStarSearch::AStarSearch(Display *dp, shared_ptr<World> wp) {
        this->d = dp;
        this->wp = wp;
        this->heuristicFactor = 2.5;
    }

    void AStarSearch::createAllNodes() {
        for (int y = 0; y < wp->get_n(); y++){
            deque<shared_ptr<AStarNode>> line;
            for (int x = 0; x < wp->get_n(); x++){
                auto node = make_shared<AStarNode>(Vector2i(x, y), nullptr, 0, 0);
                line.push_back(node);
            }
            allNodes.push_back(line);
            line.clear();
        }
    }

    void AStarSearch::findPathPQ(Vector2i start, Vector2i end) {
        //Set Start Node
        auto currentNode = allNodes.at(start.getY()).at(start.getX());
        Vector2i currCoordinates = currentNode->getCoordinates();
        currentNode->setHCost(getDistance(currCoordinates, end));
        currentNode->setInOpenList(true);
        openListPQ.push(currentNode);
        int i = 0;
        while (!openListPQ.empty()){
            currentNode = openListPQ.top();
            openListPQ.pop();
            currentNode->setInOpenList(false);
            //visualize(currentNode->getCoordinates(), 255, 0);
            double g;
            if (currentNode->getCoordinates() == end){
                //cout << "Goal reached!" << endl;
                g = currentNode->getGCost();
                //usleep(100000);
                while(currentNode->getParent() != nullptr){
                    //visualize(currentNode->getCoordinates(), 0, 255);
                    //cout << currentNode->getName() << endl;
                    currentNode = currentNode->getParent();
                }
                //visualize(currentNode->getCoordinates(), 0, 255);
                cout << "Path Total Cost: " << g << endl;
                //usleep(10000000);
                return;
            }
            currentNode->setInClosedList(true);
            closedListPQ.insert(currentNode);
            expandNodePQ(currentNode, end);
            i++;
        }

        throw (RobbyTheRobot::Exception("Stop Here!"));
    }

    void AStarSearch::expandNodePQ(const shared_ptr<AStarNode> &currentNode, Vector2i &end) {
        //cout << "Expanding " << currentNode->getName() << endl;
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
            Vector2i currPosition(x, y);
            double gCost = currentNode->getGCost()
                           + getDistance(currPosition, nextPosition)
                           * wp->get_field_time(nextPosition.getX(), nextPosition.getY());
            double hCost = heuristicFactor * getDistance(nextPosition, end);
            auto newNode = getNodeByVec(nextPosition);
            if (newNode->isInClosedList() and gCost >= newNode->getGCost()){
                continue;
            }
            if (!newNode->isInOpenList() or gCost < newNode->getGCost()){
                newNode->setGCost(gCost);
                newNode->setHCost(hCost);
                newNode->setParent(currentNode);
                openListPQ.push(newNode);
                newNode->setInOpenList(true);
            }
        }
    }

    void AStarSearch::findPath(Vector2i start, Vector2i end) {
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
            //visualize(currentNode->getCoordinates(), 255, 0);
            double g;
            if (currentNode->getCoordinates() == end){
                //cout << "Goal reached!" << endl;
                g = currentNode->getGCost();
                //usleep(100000);
                while(currentNode->getParent() != nullptr){
                    //visualize(currentNode->getCoordinates(), 0, 255);
                    currentNode = currentNode->getParent();
                    //cout << currentNode->getName() << endl;
                }
                //visualize(currentNode->getCoordinates(), 0, 255);
                cout << "Path Total Cost: " << g << endl;
                //usleep(10000000);
                //throw (RobbyTheRobot::Exception("Goal reached!"));
                return;
            }
            closedList.push_back(currentNode);
            expandNode(currentNode, end);
            i++;
        }
    }

    void AStarSearch::expandNode (const shared_ptr<AStarNode>& currentNode, Vector2i& end){
        //cout << "Expanding " << currentNode->getName() << endl;
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
        //for (auto &it : openList){
        //    cout << it->getName() << "-" << it->getFCost() << "-" << it->getHCost() << endl;
        //}
    }

    double AStarSearch::getDistance(Vector2i& a, Vector2i& b) {
        int dx = a.getX() - b.getX();
        int dy = a.getY() - b.getY();
        //return sqrt((dx*dx + dy*dy));
        return abs(dx) + abs(dy);
    }

    void AStarSearch::visualize(Vector2i coordinates, int blue, int green) {
        if (d == nullptr){
            throw (RobbyTheRobot::Exception("No Display given to aStar!"));
        }
        auto winPtr = d->getWindowPtr();
        d->drawVisitedFields(winPtr, coordinates, green, blue);
        winPtr->display();
        usleep(50000);
    }

    void AStarSearch::startEndTest(Vector2i& start, Vector2i& end) {
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

    void AStarSearch::resetAllNodes() {
        for (auto &y_it : allNodes){
            for (auto &x_it : y_it){
                x_it->setInClosedList(false);
                x_it->setInOpenList(false);
            }
        }
    }

    shared_ptr<AStarNode> AStarSearch::getNodeByVec(Vector2i pos) {
        return allNodes.at(pos.getY()).at(pos.getX());
    }
}
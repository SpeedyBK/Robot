//
// Created by benjamin on 05.07.22.
//

#include <unistd.h>
#include <cmath>
#include "AStarSearch.h"
#include "../Exception.h"

namespace RobbyTheRobot {

    AStarSearch::AStarSearch(Display* dp, World* wp) {
        this->d = dp;
        this->wp = wp;
        this->heuristicFactor = 2.5;
        pathTotalTime = 0;
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
            if (d != nullptr){ visualize(currentNode->getCoordinates(), 255, 0); }
            if (currentNode->getCoordinates() == end){
                //cout << "Goal reached!" << endl;
                pathTotalTime = currentNode->getGCost();
                if (d != nullptr) { usleep(100000); }
                while(currentNode->getParent() != nullptr){
                    if (d != nullptr) { visualize(currentNode->getCoordinates(), 0, 255); }
                    // cout << currentNode->getName() << endl;
                    path.push_front(currentNode->getCoordinates());
                    currentNode = currentNode->getParent();
                }
                if (d != nullptr) { visualize(currentNode->getCoordinates(), 0, 255); }
                if (d != nullptr) { usleep(1000000); }
                return;
            }
            currentNode->setInClosedList(true);
            closedListPQ.insert(currentNode);
            expandNodePQ(currentNode, end);
            i++;
        }

        //throw (RobbyTheRobot::Exception("Stop Here!"));
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

    bool AStarSearch::isInList(Vector2i& coordinates, deque<shared_ptr<AStarNode>>& L) {
        return std::any_of(L.begin(), L.end(),
               [coordinates](shared_ptr<AStarNode>& y) { return coordinates == y->getCoordinates(); });
    }

    void AStarSearch::resetAll() {
        for (auto &y_it : allNodes){
            for (auto &x_it : y_it){
                x_it->setInClosedList(false);
                x_it->setInOpenList(false);
                x_it->setHCost(0);
                x_it->setGCost(0);
                x_it->setParent(nullptr);
            }
        }
        priority_queue<shared_ptr<AStarNode>, deque<shared_ptr<AStarNode>>, lesscmp> newOpenListPQ;
        openListPQ = newOpenListPQ;
        closedListPQ.clear();
    }

    shared_ptr<AStarNode> AStarSearch::getNodeByVec(Vector2i pos) {
        return allNodes.at(pos.getY()).at(pos.getX());
    }

    pair<deque<Vector2i>, double> AStarSearch::getPathAndTime() {
        return std::make_pair(path, pathTotalTime);
    }

}
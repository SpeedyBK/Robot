//
// Created by benjamin on 05.07.22.
//

#include <unistd.h>
#include "AStarSearch.h"

namespace RobbyTheRobot {

    AStarSearch::AStarSearch(Display *dp, Vector2i start, Vector2i end) {
        this->d = dp;
        this->start = start;
        this->end = end;
    }

    void AStarSearch::visitTest() {
        auto winPtr = d->getWindowPtr();
        for (int i = 0; i < 16; i++){
            for (int j = 0; j < 16; j++){
                d->drawVisitedFields(winPtr, {j,i});
                winPtr->display();
                usleep(100000);
            }
        }
    }
}
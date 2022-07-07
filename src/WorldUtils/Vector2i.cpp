//
// Created by benjamin on 05.07.22.
//

#include "Vector2i.h"

namespace RobbyTheRobot {

    Vector2i::Vector2i(int x, int y) {

        this->x = x;
        this->y = y;

    }

    Vector2i::Vector2i() {
        this->x = 0;
        this->y = 0;
    }

    bool operator==(const Vector2i &a, const Vector2i &b) {
        if (a.getX() == b.getX() and a.getY() == b.getY()) {
            return true;
        }
        return false;
    }

}

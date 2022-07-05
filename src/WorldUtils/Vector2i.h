//
// Created by benjamin on 05.07.22.
//

#ifndef ROBOT_VECTOR2I_H
#define ROBOT_VECTOR2I_H

namespace RobbyTheRobot {

    class Vector2i {

    public:

        Vector2i();

        Vector2i(int x, int y);

        void setX(int xCoord) { this->x = xCoord; }

        void setY(int xCoord) { this->x = xCoord; }

        int getX() const { return this->x; }

        int getY() const { return this->y; }

    private:

        int x;
        int y;

    };

}


#endif //ROBOT_VECTOR2I_H

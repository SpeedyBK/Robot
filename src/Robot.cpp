//
// Created by Benja on 6/22/2022.
//

#include "iostream"
#include "Robot.h"

Robot::Robot(int x, int y, World *w) {
    this->materials = 0;
    this->x = x;
    this->y = y;
    this->w = w;
    this->n = w->get_n();
}

Robot::~Robot() {
    std::cout << "Robot destroyed!" << std::endl;
}

RobbyTheRobot::Vector2i Robot::get_position() const {
    return {x, y};
}

bool Robot::move_left() {
    if ( x > 0 ){
        x--;
        return true;
    }
    return false;
}

bool Robot::move_right() {
    if ( x < n - 1){
        x++;
        return true;
    }
    return false;
}

bool Robot::move_up() {
    if ( y > 0 ){
        y--;
        return true;
    }
    return false;
}

bool Robot::move_down() {
    if ( y < n - 1 ){
        y++;
        return true;
    }
    return false;
}

void Robot::gather_materials() {
    if (materials < MAX_CAPACITY){
        int gathered = w->gather_materials(x, y, MAX_CAPACITY - materials);
        materials += gathered;
    }else{
        std::cout << "Robot: 'No space left!'" << std::endl;
    }
}

void Robot::unload_materials() {
    auto F = w->get_factory_ptr();
    if ( x == F->get_position().getX() && y == F->get_position().getY()){
        F->process(materials);
        materials = 0;
    }else{
        std::cout << "Robot: 'No factory here to unload!'" << std::endl;
    }
}

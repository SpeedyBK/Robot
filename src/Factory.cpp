//
// Created by Benja on 6/21/2022.
//

#include <iostream>
#include "Factory.h"

Factory::Factory(int x, int y, World *w) {

    time_started_processing = 0;
    this->w = w;
    this->x = x;
    this->y = y;
    PROCESSING_DURATION = (const int) w->get_n() / 2;

}

RobbyTheRobot::Vector2i Factory::get_position() const {
    return {x, y};
}

void Factory::process(double materials) {
    wait_till_finished();
    time_started_processing = w->get_time_passed();
}

void Factory::wait_till_finished() const {
    long int time_processing = w->get_time_passed() - time_started_processing;
    if (time_processing < PROCESSING_DURATION) {
        w->increase_time_passed(PROCESSING_DURATION - time_processing);
    }
}

Factory::~Factory() {

    std::cout << "Factory Destroyed!" << std::endl;

}

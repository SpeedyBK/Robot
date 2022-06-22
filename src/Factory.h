//
// Created by Benja on 6/21/2022.
//

#ifndef ROBOT_FACTORY_H
#define ROBOT_FACTORY_H

#include "World.h"

class World;

class Factory {

public:

    Factory(int x, int y, World* w);

    ~Factory();

    void set_world_pointer (World* W) {w = W;};

    /*!
     * Gets Position of Factory as a Pair.
     * @return first = x, second = y.
     */
    std::pair<int, int> get_position();

    void wait_till_finished() const;

    void process(double materials);

private:

    World* w;

    int x;
    int y;

    int time_started_processing;

    int PROCESSING_DURATION;

};


#endif //ROBOT_FACTORY_H

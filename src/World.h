//
// Created by Benja on 6/21/2022.
//

#ifndef ROBOT_WORLD_H
#define ROBOT_WORLD_H

#include <vector>
#include <memory>
#include "Factory.h"
#include "Robot.h"

class Factory;
class Robot;

class World {

public:

    explicit World(int n);

    ~World();

    void print_times();

    void print_materials();

    int get_total_materials();

    int gather_materials(int x, int y, int amount);

    int get_field_time(int x, int y);

    int get_field_materials(int x, int y);

    int get_n();

    int get_time_passed() const;

    void increase_time_passed(long int time);

    std::shared_ptr<Factory> get_factory_ptr();

private:

    void travel_to_field(int x, int y);

    std::vector<std::vector<int>> field_materials;

    std::vector<std::vector<int>> field_times;

    long int time_passed;

    std::shared_ptr<Factory> F;
    std::shared_ptr<Robot> R;

};


#endif //ROBOT_WORLD_H
//
// Created by Benja on 6/21/2022.
//

#include "World.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>

World::World(int n) {

    time_passed = 0;

    field_materials.reserve(n);
    field_times.reserve(n);
    for(int i = 0; i < n; i++){
        std::vector<int>line;
        line.reserve(n);
        for (int j = 0; j < n; j++){
            line.push_back(0);
        }
        field_materials.push_back(line);
        field_times.push_back(line);
    }

    srand(time(nullptr));

    for (int i = 0; i < 4*n*n; i++){
        int x = rand() % n;
        int y = rand() % n;
        field_times.at(y).at(x)++;
    }

    for (int i = 0; i < 2*n; i++){
        int x = rand() % n;
        int y = rand() % n;
        field_materials.at(y).at(x)++;
    }

    F = std::make_shared<Factory>(n/2, n-1, this);
    R = std::make_shared<Robot>(F->get_position().first, F->get_position().second, this);

    field_times.at(F->get_position().second).at(F->get_position().first) = 0;
    field_materials.at(F->get_position().second).at(F->get_position().first) = 0;
}

World::~World(){
    std::cout << "World destroyed!" << std::endl;
}

int World::get_total_materials() {
    int total_materials = 0;
    for (auto &y_it : field_materials){
        for(auto &x_it : y_it){
            total_materials += x_it;
        }
    }
    return total_materials;
}

int World::gather_materials(int x, int y, int amount) {
    int gathered = std::min(field_materials.at(y).at(x), amount);
    field_materials.at(y).at(x) -= gathered; //ToDo: Kann das negativ werden?
    return gathered;
}

int World::get_field_time(int x, int y) {
    return field_times.at(y).at(x);
}

int World::get_field_materials(int x, int y) {
    return field_materials.at(y).at(x);
}

void World::travel_to_field(int x, int y) {
    time_passed += field_times.at(y).at(x);
}

int World::get_n() {
    return (int)field_materials.size();
}

void World::increase_time_passed(long time) {
    time_passed += time;
}

int World::get_time_passed() const {
    return time_passed;
}

void World::print_times() {
    for(auto &y_it : field_times){
        for (auto &x_it : y_it){
            std::cout << std::setw(2) << x_it << " ";
        }
        std::cout << std::endl;
    }
}

void World::print_materials() {
    for(auto &y_it : field_materials){
        for (auto &x_it : y_it){
            std::cout << std::setw(2) << x_it << " ";
        }
        std::cout << std::endl;
    }
}

std::shared_ptr<Factory> World::get_factory_ptr() {
    return F;
}



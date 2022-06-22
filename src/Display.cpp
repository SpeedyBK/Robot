//
// Created by Benja on 6/21/2022.
//

#include <iostream>
#include <cmath>
#include "Display.h"

using namespace std;

Display::Display(World *w) {

    cout << "Drawing Class generated..." << endl;

    this->W = w;

    scaling_factor = 50;

    width = w->get_n() * scaling_factor;
    heigt = w->get_n() * scaling_factor;

}

void Display::draw() {

    cout << "Drawing" << endl;
    sf::RenderWindow window(sf::VideoMode(width, heigt), "Robot!");

    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        draw_times(&window);
        draw_minerals(&window);
        draw_factory(&window);
        draw_robot(&window);
        window.display();
    }

}

void Display::draw_times(sf::RenderWindow* win_ptr) {
    for (int x = 0; x < W->get_n(); x++){
        for(int y = 0; y < W->get_n(); y++){
            sf::RectangleShape rect(sf::Vector2f((float)scaling_factor, (float)scaling_factor));
            int color_step = floor(255 / W->get_max_field_time());
            rect.setFillColor(sf::Color(color_step*W->get_field_time(x, y), 0, 0));
            rect.setPosition(sf::Vector2f(x*scaling_factor, y*scaling_factor));
            win_ptr->draw(rect);
        }
    }
}

void Display::draw_minerals(sf::RenderWindow *win_ptr) {
    for (int x = 0; x < W->get_n(); x++){
        for(int y = 0; y < W->get_n(); y++){
            int color = W->get_field_materials(x, y);
            if (color > 0) {
                sf::CircleShape triangle((float )scaling_factor/2, 3);
                int color_step = floor(255 / W->get_max_field_minerals());
                triangle.setFillColor(sf::Color(0, (color * color_step), 0));
                triangle.setPosition(sf::Vector2f((float) x * (float) scaling_factor,
                                                         (float) y * (float) scaling_factor + (float)scaling_factor/10));
                win_ptr->draw(triangle);
            }
        }
    }
}

void Display::draw_robot(sf::RenderWindow *win_ptr) {
    int shrink_value = 14;
    sf::CircleShape robbi((float)(scaling_factor-shrink_value)/2);
    robbi.setFillColor(sf::Color::Cyan);
    robbi.setPosition((float)W->get_robot_position().first * (float)scaling_factor + (float)shrink_value/2,
                      (float)W->get_robot_position().second * (float)scaling_factor + (float)shrink_value/2);
    win_ptr->draw(robbi);
}

void Display::draw_factory(sf::RenderWindow *win_ptr) {
    sf::CircleShape factory((float )scaling_factor/2, 8);
    factory.setFillColor(sf::Color::Blue);
    factory.setPosition((float)W->get_factory_position().first * (float)scaling_factor,
                      (float)W->get_factory_position().second * (float)scaling_factor);
    win_ptr->draw(factory);
}

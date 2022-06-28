//
// Created by Benja on 6/21/2022.
//

#include <iostream>
#include <cmath>
#include "Display.h"

using namespace std;

namespace RobbyTheRobot {

    Display::Display(World *w, Graph* g) {

        cout << "Drawing Class generated..." << endl;

        this->W = w;
        this->G = g;

        scaling_factor = 64;

        width = w->get_n() * scaling_factor;
        heigt = w->get_n() * scaling_factor;

        this->window_ptr = new sf::RenderWindow(sf::VideoMode(width, heigt), "Robot!");;

    }

    void Display::draw() {

        cout << "Drawing" << endl;

        while (window_ptr->isOpen()) {
            sf::Event event;
            while (window_ptr->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window_ptr->close();
                }
            }
            window_ptr->clear(sf::Color::Black);
            draw_times();
            draw_minerals();
            draw_factory();
            draw_robot();
            for (auto &e: G->Edges()) {
                vector<int> lin;
                for (auto &v: e->get_vertices_of_edge()) {
                    lin.push_back(v->get_position().first);
                    lin.push_back(v->get_position().second);
                }
                calc_line(lin);
                lin.clear();
            }
            window_ptr->display();
        }

    }

    void Display::draw_times() {
        for (int x = 0; x < W->get_n(); x++) {
            for (int y = 0; y < W->get_n(); y++) {
                sf::RectangleShape rect(sf::Vector2f((float)scaling_factor,(float)
                scaling_factor));
                int color_step = floor(255 / W->get_max_field_time());
                rect.setFillColor(sf::Color(color_step * W->get_field_time(x, y), 0, 0));
                rect.setPosition(sf::Vector2f(x * scaling_factor, y * scaling_factor));
                window_ptr->draw(rect);
            }
        }
    }

    void Display::draw_minerals() {
        for (int x = 0; x < W->get_n(); x++) {
            for (int y = 0; y < W->get_n(); y++) {
                int color = W->get_field_materials(x, y);
                if (color > 0) {
                    sf::CircleShape triangle((float) scaling_factor / 2, 3);
                    int color_step = floor(255 / W->get_max_field_minerals());
                    triangle.setFillColor(sf::Color(0, (color * color_step), 0));
                    triangle.setPosition(sf::Vector2f((float) x * (float) scaling_factor,
                                                      (float) y * (float) scaling_factor +
                                                      (float) scaling_factor / 10));
                    window_ptr->draw(triangle);
                }
            }
        }
    }

    void Display::draw_robot() {
        int shrink_value = 14;
        sf::CircleShape robbi((float) (scaling_factor - shrink_value) / 2);
        robbi.setFillColor(sf::Color::Cyan);
        robbi.setPosition((float) W->get_robot_position().first * (float) scaling_factor + (float) shrink_value / 2,
                          (float) W->get_robot_position().second * (float) scaling_factor + (float) shrink_value / 2);
        window_ptr->draw(robbi);
    }

    void Display::draw_factory() {
        sf::CircleShape factory((float) scaling_factor / 2, 8);
        factory.setFillColor(sf::Color::Blue);
        factory.setPosition((float) W->get_factory_position().first * (float) scaling_factor,
                            (float) W->get_factory_position().second * (float) scaling_factor);
        window_ptr->draw(factory);
    }

    void Display::draw_line(int start_x, int start_y, int end_x, int end_y) {
        sf::Vertex l[] = {
                sf::Vertex(sf::Vector2f((float) start_x, (float) start_y)),
                sf::Vertex(sf::Vector2f((float) end_x, (float) end_y))
        };
        window_ptr->draw(l, 2, sf::Lines);
    }

    void Display::calc_line(vector<int> &start_end) {
        int start_x = start_end.at(0) * scaling_factor + (scaling_factor >> 1);
        int start_y = start_end.at(1) * scaling_factor + (scaling_factor >> 1);
        int end_x = start_end.at(2) * scaling_factor + (scaling_factor >> 1);
        int end_y = start_end.at(3) * scaling_factor + (scaling_factor >> 1);
        draw_line(start_x, start_y, end_x, end_y);
    }

}
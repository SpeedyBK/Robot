//
// Created by Benja on 6/21/2022.
//

#include <unistd.h>
#include <iostream>
#include <cmath>
#include <utility>
#include "Display.h"
#include "WorldUtils/AStarSearch.h"

using namespace std;

namespace RobbyTheRobot {

    Display::Display(World* wp) {

        cout << "Drawing Class generated..." << endl;

        int n = 15;
        this->wp = wp;
        this->G = std::make_shared<Graph>();

        scaling_factor = 64;

        width = wp->get_n() * scaling_factor;
        heigth = wp->get_n() * scaling_factor;

        this->window_ptr = new sf::RenderWindow(sf::VideoMode(width, heigth), "Robot!");;

    }

    void Display::draw() {

        cout << "Drawing" << endl;

        auto aStar = new AStarSearch(this, wp, 2.5);

        bool doOnce = true;

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
            if (doOnce) {
                for (int i = 0; i < 2; i++) {
                    if (i == 0) {
                        aStar->createAllNodes();
                        aStar->findPathPQ({1, 1}, {wp->get_n() - 2, wp->get_n() - 2});
                        aStar->resetAll();
                    }else{
                        aStar->createAllNodes();
                        aStar->findPathPQ({1, wp->get_n() - 2}, {wp->get_n() - 2, 1});
                        aStar->resetAll();
                    }
                }
                doOnce = false;
            }
            window_ptr->display();
        }
        delete aStar;
    }

    void Display::draw_times() {
        for (int x = 0; x < wp->get_n(); x++) {
            for (int y = 0; y < wp->get_n(); y++) {
                sf::RectangleShape rect(sf::Vector2f((float)scaling_factor,(float)
                scaling_factor));
                int color_step = floor(255 / wp->get_max_field_time());
                rect.setFillColor(sf::Color(color_step * wp->get_field_time(x, y), 0, 0));
                rect.setPosition(sf::Vector2f(x * scaling_factor, y * scaling_factor));
                window_ptr->draw(rect);
            }
        }
    }

    void Display::draw_minerals() {
        for (int x = 0; x < wp->get_n(); x++) {
            for (int y = 0; y < wp->get_n(); y++) {
                int color = wp->get_field_materials(x, y);
                if (color > 0) {
                    sf::CircleShape triangle((float) scaling_factor / 2, 3);
                    int color_step = floor(255 / wp->get_max_field_minerals());
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
        robbi.setPosition((float) wp->get_robot_position().getX() * (float) scaling_factor + (float) shrink_value / 2,
                          (float) wp->get_robot_position().getY() * (float) scaling_factor + (float) shrink_value / 2);
        window_ptr->draw(robbi);
    }

    void Display::draw_factory() {
        sf::CircleShape factory((float) scaling_factor / 2, 8);
        factory.setFillColor(sf::Color::Blue);
        factory.setPosition((float) wp->get_factory_position().getX() * (float) scaling_factor,
                            (float) wp->get_factory_position().getY() * (float) scaling_factor);
        window_ptr->draw(factory);
    }

    void Display::draw_line(Vector2i start, Vector2i end) {
        sf::Vertex l[] = {
                sf::Vertex(sf::Vector2f((float) start.getX(), (float) start.getY())),
                sf::Vertex(sf::Vector2f((float) end.getX(), (float) end.getY()))
        };
        window_ptr->draw(l, 2, sf::Lines);
    }

    void Display::calc_line(Vector2i& start, Vector2i& end) {
        Vector2i st(start.getX() * scaling_factor + (scaling_factor >> 1),
                       start.getY() * scaling_factor + (scaling_factor >> 1));
        Vector2i en(end.getX() * scaling_factor + (scaling_factor >> 1),
                     end.getY() * scaling_factor + (scaling_factor >> 1));
        draw_line(st, en);
    }

    sf::RenderWindow *Display::getWindowPtr() const {
        return this->window_ptr;
    }

    void Display::drawVisitedFields(sf::RenderWindow *win_ptr, Vector2i fieldVector, int green, int blue) {
        sf::RectangleShape rect(sf::Vector2f((float)scaling_factor,(float)scaling_factor));
        rect.setFillColor(sf::Color(0, green, blue));
        rect.setPosition(sf::Vector2f((float)(fieldVector.getX() * scaling_factor), (float)(fieldVector.getY() * scaling_factor)));
        window_ptr->draw(rect);
    }

}
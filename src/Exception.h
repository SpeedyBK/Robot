//
// Created by Benja on 6/24/2022.
//

#ifndef ROBOT_EXCEPTION_H
#define ROBOT_EXCEPTION_H

#pragma once

#include <exception>
#include <ostream>
#include <utility>

namespace RobbyTheRobot {

    /*!
     * \brief The Exception class implements exceptions thrown by RobbyTheRobot
     */
    class Exception : public std::exception {
    public:
        std::string msg;

        explicit Exception(std::string s) : msg(std::move(s)) {
        }

        const char *what() const noexcept override;
    };

    std::ostream &operator<<(std::ostream &oss, RobbyTheRobot::Exception &e);


}


#endif //ROBOT_EXCEPTION_H

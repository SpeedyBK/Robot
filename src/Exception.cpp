//
// Created by Benja on 6/24/2022.
//

#include "Exception.h"

namespace RobbyTheRobot {

    const char *Exception::what() const noexcept {
        return msg.c_str();
    }

    std::ostream &operator<<(std::ostream &oss, RobbyTheRobot::Exception &e) {
        return oss << e.msg;
    }
}
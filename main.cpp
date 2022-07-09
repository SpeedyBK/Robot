#include "src/Display.h"
#include "src/Tests/Tests.h"
#include "src/Exception.h"

using namespace RobbyTheRobot;

bool debug = true;

int main() {

    if (debug) {
        if (!Tests::fibTest()){
            throw (Exception("Fibtest failed!"));
        }else {
            cout << "Fibtest success..." << endl;
        }
        if (!Tests::aStarTest()){
            throw (Exception("AStar Test failed!"));
        }else {
            cout << "AStar Test success..." << endl;
        }
    }

    return 0;

    Display D;

    D.draw(); //Strange Name for a Programm-Loop.

    return 0;
}


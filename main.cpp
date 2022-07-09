#include "src/Display.h"
#include "src/Tests/Tests.h"
#include "src/Exception.h"
#include "src/Dispatcher/Dispatcher.h"

using namespace RobbyTheRobot;

enum class Mode {Test, Run, Visual};

int main(int argc, char *argv[]) {

    std::string s(argv[1]);
    Mode mode = Mode::Run;

    if (s == "-test") {
        mode = Mode::Test;
    }else if ( s == "-visual"){
        mode = Mode::Visual;
    } else if (s == "-run"){
        mode = Mode::Run;
    }

    if (mode == Mode::Test) {
        if (!Tests::aStarTest()){
            throw (Exception("AStar Test failed!"));
        }else {
            cout << "AStar Test success..." << endl << endl;
        }
        if (!Tests::graphTest()){
            throw (Exception("Graph Test failed!"));
        }else {
            cout << "Graph Test success..." << endl << endl;
        }
        if (!Tests::dispatchTest()){
            throw (Exception("Graph Test failed!"));
        }else {
            cout << "Dispatch Test success..." << endl << endl;
        }
        return 0;
    }

    if (mode == Mode::Run){
        int n = 200;
        World w(n);
        Dispatcher dis(&w);
        dis.createFactoryToMinsPaths();
        dis.printPathCosts();
        return 0;
    }

    if (mode == Mode::Visual) {
        World w(15);
        Display d(&w);
        d.draw(); //Strange Name for a Programm-Loop.
        return 0;
    }
}


//
// Created by benjamin on 07.07.22.
//

#include <vector>
#include <ctime>
#include <iomanip>

#include "../WorldUtils/FibonacciHeap.h"
#include "../World.h"
#include "../WorldUtils/AStarSearch.h"
#include "Tests.h"

namespace RobbyTheRobot {

    bool Tests::fibTest() {

        FibonacciHeap<double> fib;
        std::vector<double> vec;

        for (int i = 0; i < 100; i++){
            fib.push((double)(100-i)/i);
            vec.push_back((double)(100-i)/i);
        }

        std::sort(vec.begin(), vec.end());

        for (double i : vec){
            if (i != fib.get_extract_min()){
                return false;
            }
        }
        return true;
    }

    bool Tests::aStarTest() {
        try {
            int n = 1000;
            auto W = std::make_shared<World>(n);
            AStarSearch aStar(nullptr, W);
            clock_t start, end;

            cout << "Creating all Nodes.." << endl;
            start = clock();
            aStar.createAllNodes();
            end = clock();
            cout << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec "
                 << endl << endl;
            cout << "Searching path with PQ from 1/1 to " << n - 1 << "/" << n - 1 << ".." << endl;
            start = clock();
            aStar.findPathPQ({1, 1}, {n - 1, n - 1});
            end = clock();
            cout << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec "
                 << endl << endl;
            cout << "Resetting all Nodes.." << endl;
            start = clock();
            aStar.resetAllNodes();
            end = clock();
            cout << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec "
                 << endl << endl;
            cout << "Searching path with sorted deque from 1/1 to " << n - 1 << "/" << n - 1 << ".." << endl;
            start = clock();
            aStar.findPath({1, 1}, {n - 1, n - 1});
            end = clock();
            cout << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec "
                 << endl << endl;
        } catch (...) {
            return false;
        }
        return true;
    }
}

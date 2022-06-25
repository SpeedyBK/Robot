#include <iostream>
#include "src/World.h"
#include "src/Display.h"
#include "src/graph/Graph.h"

using namespace RobbyTheRobot;

int main() {
    std::cout << "Hello, World!" << std::endl;

    int n = 15;

    World w(n);

    w.print_materials();
    std::cout << std::endl;
    w.print_times();

    Graph g;

    g.create_vertices_from_map(w.get_material_map());

    g.create_complete_graph_test();

    cout << g;

    std::cout << "Total Materials: " << w.get_total_materials() << std::endl;

    Display D(&w);

    D.draw();

    return 0;
}


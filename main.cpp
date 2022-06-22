#include <iostream>
#include "src\World.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    int n = 11;

    World w(n);

    w.print_materials();
    std::cout << std::endl;
    w.print_times();

    std::cout << "Total Materials: " << w.get_total_materials() << std::endl;

    return 0;
}



#include "ConwayGameOfLife.hpp"
#include "Grid.hpp"

#include <iostream>
#include <unistd.h>

namespace Conway{
void runConwayGame()
{
    std::cout << "Conway's game of life\n";
    std::cout << "Press the return key to display each generation\n";

    // std::cin.get();

    Grid currentGeneration;
    currentGeneration.randomize();

    while(true)
    {
        sleep(3);
        currentGeneration.drawCells();
        // std::cout << "Current Generation: " << currentGeneration;
        // std::cin.get();

        Grid nextGeneration;

        calculate(currentGeneration, nextGeneration);
        currentGeneration.updateToNextGen(nextGeneration);
    }
}
}
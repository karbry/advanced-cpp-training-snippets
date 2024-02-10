#include "Grid.hpp"


namespace Conway
{

void Grid::createAt(const int row, const int col) {
    cells[row][col].create();
}

void Grid::drawCells() {
    // ANSI control command
    // \x1b means "escape"
    // Escape[2J clears the screen and returns the cursor to the "home" position
    std::cout << "\x1b[2J";

    for (int row = 0; row < rowMax; ++row) {
        for (int col = 0; col < colMax; ++col) {
            cells[row][col].drawOnGrid(row, col);
        }
    }
}

// Populate the grid with cells, at random
void Grid::randomize() {
    const int factor = 5; // * one in 5 probability of the cells to be populated:20% will be populated, 80% will be empty
    const int cutoff = RAND_MAX/factor;
    time_t now;
    time(&now);
    //srand(now);

    for (int row = 1; row < rowMax; ++row) {
        for (int col = 1; col < colMax; ++col) {
            if (rand()/cutoff == 0) {
                createAt(row, col);
            }
        }
    }
}

// Will the cell at (row, col) survive to the next generation?
bool Grid::willSurviveAt(const int row, const int col) {
    if (!cells[row][col].isAlive()) {
        // There is no cell at this position!
        return false;
    }

    // Find the number of live neighbours for this cell
    //
    //   x x x
    //   x o x
    //   x x x
    int neighbours = cells[row-1][col-1].isAlive() +
        cells[row-1][col].isAlive() +
        cells[row-1][col+1].isAlive() +
        cells[row][col-1].isAlive() +
        cells[row][col+1].isAlive() +
        cells[row+1][col-1].isAlive() +
        cells[row+1][col].isAlive() +
        cells[row+1][col+1].isAlive();

    if (neighbours < minNeighbours || neighbours > maxNeighbours) {
        // Cell has died
        return false;
    }

    // If we get here, the cell has survived
    return true;
}

// Will a cell be born at (row, col) in the next generation?
bool Grid::willCreateAt(const int row, const int col) {
    if (cells[row][col].isAlive()) {
        // There already is a cell at this position!
        return false;
    }

    // Find the number of parents for this cell
    //
    //   x x x
    //   x o x
    //   x x x
    int parents = cells[row-1][col-1].isAlive() +
        cells[row-1][col].isAlive() +
        cells[row-1][col+1].isAlive() +
        cells[row][col-1].isAlive() +
        cells[row][col+1].isAlive() +
        cells[row+1][col-1].isAlive() +
        cells[row+1][col].isAlive() +
        cells[row+1][col+1].isAlive();

    if (parents < minParents || parents > maxParents) {
        // Cannot create a cell here
        return false;
    }

    // If we get here, a new cell can be born
    return true;
}

// Update to the next generation
void Grid::updateToNextGen(const Grid& nextGen) {
    for (int row = 1; row < rowMax; ++row) {
        for (int col = 1; col < colMax; ++col) {
            cells[row][col] = nextGen.cells[row][col];
        }
    }
}

// By default, all cells in the next generation are initially unpopulated
// Calculate which live cells survive to the next generation
// and unpopulated cells are populated in the next generation
void calculate(Grid& old_generation, Grid& new_generation) {
    for (int row = 1; row < rowMax; ++row) {
        for (int col = 1; col < colMax; ++col) {
            // Will this live cell survive to the next generation?
            if (old_generation.willSurviveAt(row, col)) {
                new_generation.createAt(row, col);
            }
            // Will this unpopulated cell be populated in the next generation?
            else if (old_generation.willCreateAt(row, col)) {
                new_generation.createAt(row, col);
            }
        }
    }
}
}
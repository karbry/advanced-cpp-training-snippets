#include "Cell.hpp"
#include "ConwayConsts.hpp"

namespace Conway
{
void Cell::drawOnGrid(const int row, const int col)
{
    // std::cout << "draw on grid " << row+1 << " " << col+1 <<"\n";
    this->location.update(row+1, col+1);
    std::cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
    std::cout << (alive ? static_cast<char>(CellStatus::alive) : static_cast<char>(CellStatus::dead));
}

}

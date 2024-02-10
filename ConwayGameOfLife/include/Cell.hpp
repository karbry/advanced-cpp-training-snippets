#include <iostream>
#include <cstdint>

namespace Conway
{

struct CellLocation
{
    int cellRow, cellCol;
    void update(const int row, const int col)
    {
        cellRow = row;
        cellCol = col;
    }
};


class Cell
{
    bool alive;

public:

    Cell(): alive(false) {}
    CellLocation location;

    void drawOnGrid(const int row, const int col);
    void create()
    {
        alive = true;
    }

    void erase()
    {
        alive = false;
    }

    bool isAlive() const {return alive;}

    friend std::ostream& operator<<(std::ostream& os, const Cell& obj) {
        os << obj.location.cellRow << ", " << obj.location.cellCol;
        return os;
    }

};
}
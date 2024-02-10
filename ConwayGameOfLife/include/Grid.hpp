#include "Cell.hpp"
#include "ConwayConsts.hpp"

#include <iostream>

namespace Conway
{
class Grid {

  Cell cells[rowMax+2][colMax+2];

 public:
 
  void createAt(const int row, const int col);

  void drawCells();
  
  void randomize();

  bool willSurviveAt(const int row, const int col);
  
  bool willCreateAt(const int row, const int col);

  void updateToNextGen(const Grid& nextGen);

  friend std::ostream& operator<<(std::ostream& os, const Grid& obj) {
    for (int i = 0; i < rowMax+2; ++i) {
        for (int j = 0; j < colMax+2; ++j) {
            os << obj.cells[i][j] << " ";
        }
        os << std::endl; // Move to the next line after printing each row
    }
    return os;
  }
};

void calculate(Grid& old_generation, Grid& new_generation);
}
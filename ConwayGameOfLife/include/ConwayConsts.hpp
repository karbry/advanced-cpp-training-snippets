#include <cstdint>

namespace Conway
{
constexpr int rowMax = 23;
constexpr int colMax = 79;

constexpr int minNeighbours = 2;
constexpr int maxNeighbours = 3;

constexpr int minParents = 3;
constexpr int maxParents = 3;

enum CellStatus {dead = ' ', alive = 'X'};
}
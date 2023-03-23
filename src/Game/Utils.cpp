#include "Utils.h"
#include "Sudoku.h"

namespace Utils {

int getSquareNumber(int row, int col) {
    return col / 3 + row / 3 * 3;
}

}


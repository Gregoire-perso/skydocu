#ifndef UTILS_H
#define UTILS_H
#include "Sudoku.h"

namespace Utils {

/**
 * @brief Get the row from the row major notation
 */
inline int getRowFromRowM(int i) {
    return i % Sudoku::BoardSize;
}

/**
 * @brief Get the column from the row major notation
 */
inline int getColFromRowM(int i) {
    return i / Sudoku::BoardSize;
}

/**
 * @brief Get the row major notation from row and column numbers
 */
inline int toRowMajor(int row, int col) {
    return row * Sudoku::BoardSize + col;
}

/**
 * @brief Get the number of the square from row and column numbers
 *
 * Here is how the squares are numbered:
 * 0 | 1 | 2
 * 3 | 4 | 5
 * 6 | 7 | 8
 */
inline int getSquareNumber(int row, int col) {
    return col / 3 + row / 3 * 3;
}

/**
 * @brief Get the number of the square from the row major notation
 *
 * Here is how the squares are numbered:
 * 0 | 1 | 2
 * 3 | 4 | 5
 * 6 | 7 | 8
 */
inline int getSquareNumber(int i) {
    return getColFromRowM(i) / 3 + getRowFromRowM(i) / 3 * 3;
}

/**
 * @class NotValidEntryException
 * @brief The error thrown when an entry is not valid
 */
class NotValidEntryException : public std::exception {
public:
    char * what () {
        return "Not valid entry";
    }
};

}

#endif



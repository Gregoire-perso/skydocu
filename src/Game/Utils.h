#ifndef UTILS_H
#define UTILS_H
#include "Sudoku.h"

namespace Utils {

inline int getRowFromRowM(int i) {
    return i % Sudoku::BoardSize;
}

inline int getColFromRowM(int i) {
    return i / Sudoku::BoardSize;
}


inline int toRowMajor(int row, int col) {
    return row * Sudoku::BoardSize + col;
}

inline int getSquareNumber(int row, int col) {
    return col / 3 + row / 3 * 3;
}

inline int getSquareNumber(int i) {
    return getColFromRowM(i) / 3 + getRowFromRowM(i) / 3 * 3;
}

class NotValidEntryException : public std::exception {
public:
    char * what () {
        return "Not valid entry";
    }
};

}

#endif



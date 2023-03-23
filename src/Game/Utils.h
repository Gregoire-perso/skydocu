#ifndef UTILS_H
#define UTILS_H
#include "Sudoku.h"

namespace Utils {

inline int toRowMajor(int row, int col) {
    return row * Sudoku::BoardSize + col;
}

inline int getSquareNumber(int row, int col);

class NotValidEntryException : public std::exception {
public:
    char * what () {
        return "Not valid entry";
    }
};

}

#endif



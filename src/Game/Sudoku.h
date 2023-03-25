#ifndef SUDOKU_H
#define SUDOKU_H
#include "Cell.h"
#include <vector>
#include <QTableWidget>

using namespace std;

enum Difficulty { Easy = 45, Medium = 30, Hard = 20 };

class Sudoku {
private:
    Cell *cells[81] = { NULL };
    int m_board[81] = { 0 };
    QTableWidget *m_grid;

    void CreateRandomSolved();
    void clearCells(int number);
    void initCells();

    bool IsValidRow(int row);
    bool IsValidCol(int col);
    bool IsValidSquare(int sq);
    bool IsSolved();

public:
    static const int BoardSize = 9;
    Sudoku(QTableWidget *widget, Difficulty d);
    Sudoku(QTableWidget *widget, int custom = 0);
    ~Sudoku();
    bool checkCell(int row, int col);
    bool IsValidBoard();
    bool Solve(int pos = 0);
    void printBoard();
};

#endif

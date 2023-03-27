#ifndef SUDOKU_H
#define SUDOKU_H
#include "Cell.h"
#include <vector>
#include <QTableWidget>

using namespace std;

enum Difficulty { Easy = 45, Medium = 30, Hard = 20 };

class SudokuWindow;

class Sudoku {
private:
    Cell *cells[81] = { NULL };
    int m_board[81] = { 0 };
    QTableWidget *m_grid;
    SudokuWindow *m_sudokuWindow;

    void CreateRandomSolved();
    void clearCells(int number);
    void initCells();

public:
    static const int BoardSize = 9;
    Sudoku(SudokuWindow *s, Difficulty d);
    Sudoku(SudokuWindow *s, int custom = 0);
    ~Sudoku();
    bool IsValidRow(int row);
    bool IsValidCol(int col);
    bool IsValidSquare(int row, int col);
    bool IsValidSquare(int sq);
    bool IsSolved();
    bool checkCell(int row, int col);
    void changeCell(int row, int col, int val);
    void resetCell(int row, int col);
    void updateBoard(int row, int col);
    void updateAllCells();
    void resetAllCells();
    bool IsValidBoard();
    bool Solve(int pos = 0);
    void printBoard();
};

#endif

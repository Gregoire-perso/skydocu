#include "Sudoku.h"
#include "Cell.h"
#include "Utils.h"
#include <iterator>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

/*
 * PRIVATE FUNCTIONS
 */

void Sudoku::CreateRandomSolved() {
    // init first line randomly
    Solve();
}

void Sudoku::clearCells(int number) {
    vector<int> shuffled_positions;
    for (int i = 0; i < BoardSize * BoardSize; i++)
        shuffled_positions.push_back(i);

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(shuffled_positions), 
                 std::end(shuffled_positions),
                 rng);

    for (int i = 0; i < number; i++)
        m_board[i] = 0;
}

void Sudoku::initCells() {
    for (int i = 0; i < BoardSize * BoardSize; i++)
        cells[i] = new Cell(m_grid, i / BoardSize, i % BoardSize, m_board[i]);
}

bool Sudoku::IsValidRow(int row) {
    int tmp[BoardSize + 1] = {0};
    for (int i = 0; i < BoardSize; i++) {
        int val = m_board[Utils::toRowMajor(row, i)]; 
        if (val != 0) {
            tmp[val]++;
            if (tmp[val] > 1)
                return false;
        }
    }

    return true;
}

bool Sudoku::IsValidCol(int col) {
    int tmp[BoardSize + 1] = {0};
    for (int i = 0; i < BoardSize; i++) {
        int val = m_board[Utils::toRowMajor(i, col)]; 
        if (val != 0) {
            tmp[val]++;
            if (tmp[val] > 1)
                return false;
        }
    }

    return true;
}

bool Sudoku::IsValidSquare(int sq) {
    int col = (sq % 3) * 3;
    int row = (sq / 3) * 3;

    int tmp[BoardSize + 1] = {0};

    for (int i = col; i < col + 3; i++) {
        for (int j = row; j < row + 3; j++) {
            int val = m_board[Utils::toRowMajor(j, i)]; 
            if (val != 0) {
                tmp[val]++;
                if (tmp[val] > 1)
                    return false;
            }
        }
    }
    
    return true;
}

/*
 * PUBLIC FUNCTIONS
 */

Sudoku::Sudoku(QTableWidget *widget, Difficulty d) : m_grid(widget) {
    CreateRandomSolved();
    clearCells(BoardSize - (int) d);
    initCells();
}

Sudoku::Sudoku(QTableWidget *widget, int custom) : m_grid(widget)  {
    CreateRandomSolved();
    clearCells(custom);
    initCells();
}

bool Sudoku::checkCell(int row, int col) {
    return cells[Utils::toRowMajor(row, col)].checkValue();
}

bool Sudoku::IsValidBoard() {
    for (int i = 0; i < BoardSize; i++)
    {
        if (!IsValidRow(i))
            return false;
        if (!IsValidCol(i))
            return false;
        if (!IsValidSquare(i))
            return false;
    }

    return true;
}


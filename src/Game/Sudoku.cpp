#include "Sudoku.h"
#include "Cell.h"
#include "Utils.h"
#include <iterator>
#include <vector>
#include <random>
#include <algorithm>

#include <iostream>

using namespace std;

/*
 * PRIVATE FUNCTIONS
 */

void Sudoku::CreateRandomSolved() {
    // init first line randomly
    vector<int> shuffled_positions;
    for (int i = 1; i < BoardSize + 1; i++)
        shuffled_positions.push_back(i);

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(shuffled_positions), 
                 std::end(shuffled_positions),
                 rng);

    
    for (int i = 0; i < BoardSize; i++)
        m_board[i] = shuffled_positions[i];

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
        m_board[shuffled_positions[i]] = 0;
}

void Sudoku::initCells() {
    for (int i = 0; i < BoardSize * BoardSize; i++)
        cells[i] = new Cell(m_grid, i / BoardSize, i % BoardSize, m_board[i]);
}

bool Sudoku::IsValidRow(int row) {
    int numbers[BoardSize] = {0};

    for (size_t column = 0; column < BoardSize; column++) {
        if (m_board[row * BoardSize + column] != 0) {
            if (numbers[m_board[row * BoardSize + column] - 1] == 1) {
                return false;
            }
            else { 
                numbers[m_board[row * BoardSize + column] - 1] = 1;
            }
        }
    }

    return true;
}

bool Sudoku::IsValidCol(int col) {
    int numbers[BoardSize] = {0};

    for (size_t line = 0; line < BoardSize; line++) {
        if (m_board[line * BoardSize + col] != 0) {
            if (numbers[m_board[line * BoardSize + col] - 1] == 1) {
                return false;
            }
            else {
                numbers[m_board[line * BoardSize + col] - 1] = 1;
            }
        }         
    }

    return true;
}

bool Sudoku::IsValidSquare(int sq) {
    int col = (sq % 3) * 3;
    int row = (sq / 3) * 3;

    int numbers[BoardSize] = {0};

    for (int i = row; i < row + 3; i ++) {
        for (int j = col; j < col + 3; j ++) {
            if (m_board[i * BoardSize + j] != 0) {
                 if (numbers[m_board[i * BoardSize + j] - 1] == 1) {
                     return false;
                 }
                 else {
                     numbers[m_board[i * BoardSize + j] - 1] = 1;
                 }
             }        
        }
    }

    return true;
}

bool Sudoku::IsSolved() {
    for (int i = 0; i < BoardSize * BoardSize; i++)
        if (m_board[i] == 0)
            return false;

    return IsValidBoard();
}

/*
 * PUBLIC FUNCTIONS
 */

Sudoku::Sudoku(QTableWidget *widget, Difficulty d) : m_grid(widget) {
    std::cout << "Start Sudoku creation" << std::endl;
    CreateRandomSolved();
    std::cout << "Random Sudoku created" << std::endl;
    clearCells((int) d);
    std::cout << "Cells cleared" << std::endl;
    initCells();
    std::cout << "Cells init" << std::endl;
}

Sudoku::Sudoku(QTableWidget *widget, int custom) : m_grid(widget)  {
    std::cout << "Start Sudoku creation" << std::endl;
    CreateRandomSolved();
    std::cout << "Random Sudoku created" << std::endl;
    clearCells(custom);
    std::cout << "Cells cleared" << std::endl;
    initCells();
    std::cout << "Cells init" << std::endl;
}

bool Sudoku::checkCell(int row, int col) {
    return cells[Utils::toRowMajor(row, col)]->checkValue();
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

bool Sudoku::Solve(int pos) {
    for (size_t i = 0; i < BoardSize; i++) {
        for (size_t j = 0; j < BoardSize; j++) {
            if (m_board[i * BoardSize + j] == 0) {
                int num = 1;
                for (; num <= BoardSize; num++) {
                    m_board[i * BoardSize + j] = num;
                    if (IsValidRow(i) && 
                        IsValidCol(j) && 
                        IsValidSquare(Utils::getSquareNumber(i, j)) &&
                        Solve() == 1)
                            break;
                }
 
                if (num == BoardSize + 1) {
                    m_board[i * BoardSize + j] = 0;
                    return false;
                }
            }
        }
    }

    return true;
}

void Sudoku::printBoard() {
    for (int i = 0; i < BoardSize * BoardSize; i++) {
        std::cout << m_board[i] << " ";
        if ((i + 1) % 9 == 0)
            std::cout << std::endl;
    }
}

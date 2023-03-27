#include "Sudoku.h"
#include "../sudokuwindow.h"
#include "../../ui_sudokuwindow.h"
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
    m_sudokuWindow->cellChangeAllowed = false;
    for (int i = 0; i < BoardSize * BoardSize; i++)
        cells[i] = new Cell(m_grid, i / BoardSize, i % BoardSize, m_board[i]);
    m_sudokuWindow->cellChangeAllowed = true;
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

bool Sudoku::IsValidSquare(int row, int col) {
    return IsValidSquare(Utils::getSquareNumber(row, col));
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

Sudoku::Sudoku(SudokuWindow *s, Difficulty d) : m_sudokuWindow(s) {
    m_grid = m_sudokuWindow->ui->sudokuWidget;
    std::cout << "Start Sudoku creation" << std::endl;
    CreateRandomSolved();
    std::cout << "Random Sudoku created" << std::endl;
    clearCells((int) d);
    std::cout << "Cells cleared" << std::endl;
    initCells();
    std::cout << "Cells init" << std::endl;
}

Sudoku::Sudoku(SudokuWindow *s, int custom) : m_sudokuWindow(s) {
    m_grid = m_sudokuWindow->ui->sudokuWidget;
    std::cout << "Start Sudoku creation" << std::endl;
    CreateRandomSolved();
    std::cout << "Random Sudoku created" << std::endl;
    clearCells(custom);
    std::cout << "Cells cleared" << std::endl;
    initCells();
    std::cout << "Cells init" << std::endl;
}

Sudoku::~Sudoku() {
    //delete [] cells;
    //delete [] m_board;
}

bool Sudoku::checkCell(int row, int col) {
    m_sudokuWindow->cellChangeAllowed = false;
    bool tmp = cells[Utils::toRowMajor(row, col)]->checkValue();
    m_sudokuWindow->cellChangeAllowed = true;
    return tmp;
}

void Sudoku::changeCell(int row, int col, int val) {
    m_sudokuWindow->cellChangeAllowed = false;
    cells[Utils::toRowMajor(row, col)]->changeValue(val);
    m_sudokuWindow->cellChangeAllowed = true;
}

void Sudoku::resetCell(int row, int col) {
    m_sudokuWindow->cellChangeAllowed = false;
    cells[Utils::toRowMajor(row, col)]->resetValue();
    m_sudokuWindow->cellChangeAllowed = true;
    m_board[Utils::toRowMajor(row, col)] = cells[Utils::toRowMajor(row, col)]->m_defaultValue;
}

void Sudoku::updateBoard(int row, int col) {
    m_board[Utils::toRowMajor(row, col)] = cells[Utils::toRowMajor(row, col)]->getValue();
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

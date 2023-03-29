#ifndef SUDOKU_H
#define SUDOKU_H
#include "Cell.h"
#include "Utils.h"
#include <vector>
#include <QTableWidget>

using namespace std;

class SudokuWindow;

/**
 * @class Sudoku
 * @brief The class that to the backend of the sudoku game
 */
class Sudoku {
private:
    /// Pointer list to all the cells
    Cell *cells[81] = { NULL };

    /// List of the values of the cell
    int m_board[81] = { 0 };

    /// The sudoku grid itself
    QTableWidget *m_grid;

    /// The SudokuWindow window
    SudokuWindow *m_sudokuWindow;

    /**
     * @brief Create a solved random grid
     *
     * It uses a random generator based on the current time to randomize the
     * first line of the grid. Then it calls Solve() to solve the generated grid
     */
    void CreateRandomSolved();

    /**
     * @brief Set @p number of cells to 0 (choosed randomly)
     * @param number The number of cells to clear
     * @warning No verification are made on @p number
     */
    void clearCells(int number);

    /**
     * @brief Display the cells on m_grid
     */
    void initCells();

public:
    /// The size of one side of the board
    static const int BoardSize = 9;

    /**
     * @brief Constructor of the sudoku based on a cutom number of empty cells
     */
    Sudoku(SudokuWindow *s, int custom = 0);

    /**
     * @brief Constructor of the sudoku based on a preset Difficulty
     */
    Sudoku(SudokuWindow *s, Utils::Difficulty d);

    /**
     * @brief Check if the given row is valid or not
     *
     * A row is valid when the numbers between 1 and 9 appear at most one time
     * (the row can contain empty cells)
     *
     * @param row The row number
     *
     * @warning No verification is made on @p row
     */
    bool IsValidRow(int row);

    /**
     * @brief Check if the given column is valid or not
     *
     * A column is valid when the numbers between 1 and 9 appear at most one time
     * (the column can contain empty cells)
     *
     * @param column The column number
     *
     * @warning No verification is made on @p column
     */
    bool IsValidCol(int col);

    /**
     * @brief Check if the given square is valid or not
     *
     * A square is valid when the numbers between 1 and 9 appear at most one time
     * (the square can contain empty cells)
     *
     * @param row The row number of one of the rows of the square
     * @param col The col number of one of the columns of the square
     *
     * @warning No verification is made on @p row and @p col
     * @remark Call IsValidSquare() using Utils::toRowMajor(@p row, @p col)
     */
    bool IsValidSquare(int row, int col);

    /**
     * @brief Check if the given square is valid or not
     *
     * A square is valid when the numbers between 1 and 9 appear at most one time
     * (the square can contain empty cells)
     *
     * @param sq The square number
     *
     * @warning No verification is made on @p sq
     */
    bool IsValidSquare(int sq);

    /**
     * @brief Check if the grid is solved
     *
     * A grid is solved when the board is valid (using IsValidBoard() ) and it
     * does not contain any empty cell (0)
     */
    bool IsSolved();

    /**
     * @brief Check the value in m_grid of the given cell
     * @param row The row number of the cell
     * @param col The column number of the cell
     *
     * @warning No verification is made on @p row and @p col
     */
    bool checkCell(int row, int col);

    /**
     * @brief Change the value in m_grid of the given cell
     * @param row The row number of the cell
     * @param col The column number of the cell
     * @param val The new value of the cell
     *
     * @warning No verification is made on none of the parameters
     */
    void changeCell(int row, int col, int val);

    /**
     * @brief Reset the item in m_grid of the given cell
     * @param row The row number of the cell
     * @param col The column number of the cell
     *
     * @warning No verification is made on @p row and @p col
     */
    void resetCell(int row, int col);

    /**
     * @brief Get the value of the wanted cell and update m_board
     *
     * @warning No verification is made on @p row and @p col
     */
    void updateBoard(int row, int col);

    /**
     * @brief Update all cells value according to the values in m_board
     */
    void updateAllCells();

    /**
     * @brief Change the color of the non-valid cells to the given color
     *
     * @remark Default value means a reset of the background color
     */
    void toogleBackground(QColor color = Qt::color0);

    /**
     * @brief Reset all cells based on their default values (store in the Cell properties)
     */
    void resetAllCells();

    /**
     * @brief Check if a board is valid or not
     *
     * A valid board is a board where all rows, columns and sqares are valid
     */
    bool IsValidBoard();

    /**
     * @brief Solve the m_board board
     * @return True if the board is solved, false if it is not solvable
     */
    bool Solve(int pos = 0);

    /**
     * @brief Print the board on the std::cout stream
     */
    void printBoard();
};

#endif

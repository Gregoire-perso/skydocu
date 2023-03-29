#ifndef SUDOKUWINDOW_H
#define SUDOKUWINDOW_H

#include "Game/Sudoku.h"
#include <QMainWindow>

class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class SudokuWindow; }
QT_END_NAMESPACE

class SudokuWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Initialize the sudoku window
     *
     * Based on the given Utils::Difficulty, create a sudoku and display it
     *
     * @param *main  A pointer to the MainWindow
     * @param d      The difficulty of the sudoku
     */
    SudokuWindow(MainWindow *main, Difficulty d, QWidget *parent = nullptr);

    /**
     * @brief Initialize the sudoku window
     *
     * Based on the given custom number of empty cells, create a sudoku and display it
     *
     * @param *main   A pointer to the MainWindow
     * @param custom  The number of empty cells in the sudoku
     */
    SudokuWindow(MainWindow *main, int custom, QWidget *parent = nullptr);
    ~SudokuWindow();

private slots:
    /**
     * @brief Make some verifications when a cell is changed
     *
     * @remark It uses the cellChangeAllowed variable to differenciate the
     * changes made by the user and the one made by the program itself
     */
    void on_sudokuWidget_cellChanged(int row, int column);

    /**
     * @brief Check the grid and display a pop up depending to the state of the grid
     */
    void on_validateButton_clicked();

    /**
     * @brief Destroy this window and go back to the MainWindow
     */
    void on_backButton_clicked();

    /**
     * @brief Solve the sudoku grid, show a pop up if not possible
     */
    void on_solveButton_clicked();

    /**
     * @brief Reset the sudoku grid to its default values
     */
    void on_resetButton_clicked();

    /**
     * @brief Toogle all the cell's backgrounds when the check button is checked
     *
     * It will check all the cells and:
     *   - remove the red backgrounds if the button is unchecked
     *   - add red backgrounds where cells are not valid if the button is checked
     */
    void on_checkGrid_stateChanged(int arg1);

private:
    /// Make the Sudoku class friend of this one to allow easy modifications
    friend class Sudoku;

    /// Link to to UI elements
    Ui::SudokuWindow *ui;

    /// The sudoku backend
    Sudoku *sudoku;

    /// Link to the MainWindow to go back to it
    MainWindow *m_main;

    /// Tells if the cells are modified by user or program
    bool cellChangeAllowed = false;
};

#endif // SUDOKUWINDOW_H

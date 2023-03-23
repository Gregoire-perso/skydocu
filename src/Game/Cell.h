#ifndef CELL_H
#define CELL_H

#include <QTableWidget>

class Cell {

friend class Sudoku;

private:
    /// The widget where the cells are
    QTableWidget *m_widget;
    int m_defaultValue;

    /// Row of the cell
    int m_row;

    /// Column of the cell
    int m_col;

    /// Check if the value is a number between 1 and 9
    bool checkValue();

    /// Check if the number inside the cell if coherent with the other cells
    int getValue();

    Cell(QTableWidget *widget, int row, int col, int default_value = 0);
};


#endif



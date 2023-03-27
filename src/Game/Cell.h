#ifndef CELL_H
#define CELL_H

#include <QTableWidget>
#include <QColor>

class Cell {

friend class Sudoku;

private:
    /// The widget where the cells are
    QTableWidget *m_widget;
    QColor m_backColor;
    QColor m_fontColor;
    int m_defaultValue;

    /// Row of the cell
    int m_row;

    /// Column of the cell
    int m_col;

    void setItem(QString str = "");

    /*
     * @brief Check if the text inside the cell is a number between 1 and 9
     *
     * @exception Throw Utils::NotValidEntryException if the text is not correct
     */
    int getValue();

    bool checkValue();

    void changeValue(int val);

    void resetValue();

    Cell(QTableWidget *widget, int row, int col, int default_value = 0);
};


#endif



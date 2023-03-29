#ifndef CELL_H
#define CELL_H

#include <QTableWidget>
#include <QColor>

/**
 * @class Cell
 * @brief The class that represent a cell of the sudoku grid
 */
class Cell {

/// Make the Sudoku class friend of this one so it is the only class that can
/// modify cells
friend class Sudoku;

private:
    /// The widget where the cells are
    QTableWidget *m_widget;
    
    /// The default background color of the cell
    QColor m_backColor;

    /// The font color of the cell
    QColor m_fontColor;

    /// The default value of the cell
    /// 0 stands for empty cell
    int m_defaultValue;

    /// Row of the cell
    int m_row;

    /// Column of the cell
    int m_col;

    /**
     * @brief Template for this cell
     *
     * This function will create a new QTableWidgetItem with the given QString
     * and attach ot to the grid represented by m_widget
     */
    void setItem(QString str = "");

    /**
     * @brief Check if the text inside the cell is a number between 1 and 9
     *
     * @exception Throw Utils::NotValidEntryException if the text is not correct
     */
    int getValue();

    /**
     * @brief Check if the value of the cell entered by the user is valid (ie between 1 and 9)
     *
     * It will call getValue() and catch the potential thrown exception
     */
    bool checkValue();

    /**
     * @brief Change the value of this cell
     *
     * @param val The new value of the cell
     *
     * @remark It does check if the m_defaultValue is set to 0 (to reset the cell)
     * @warning It does not check if the value @p val is valid or not 
     */
    void changeValue(int val);

    /**
     * @brief Reset the cell to its m_defaultValue and default colors (m_backColor and m_fontColor)
     */
    void resetValue();

    /**
     * @brief Change the background color
     *
     * @param color The color of the background
     * @remark Give the Qt::color0 to reset the background to its default value (m_backColor)
     * @remark It does check if the m_defaultValue is set to 0 (to reset the cell)
     */
    void changeBackground(QColor color);

    /**
     * @brief Constructor of a cell
     *
     * @param *widget       The widget to which the QTableWidgetItem must be attached
     * @param row           The row number of the cell
     * @param col           The column number of the cell
     * @param default_value The default value of the cell (0 means empty cell)
     */
    Cell(QTableWidget *widget, int row, int col, int default_value = 0);
};


#endif



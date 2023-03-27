#include "Cell.h"
#include "Utils.h"
#include <asm-generic/errno.h>
#include <cstdlib>
#include <string>
#include <algorithm>

Cell::Cell(QTableWidget *widget, int row, int col, int default_value) 
    : m_row(row), m_col(col), m_defaultValue(default_value), m_widget(widget) {
    
    if (Utils::getSquareNumber(m_row, m_col) % 2 == 0)
        m_color = Qt::lightGray;

    else
        m_color = Qt::transparent;

    resetValue();
}

int Cell::getValue() {
    std::string str = m_widget->item(m_row, m_col)->text().toStdString();
    if (str.length() != 1 || !std::all_of(str.begin(), str.end(), ::isdigit) || atoi(str.c_str()) == 0)
        throw Utils::NotValidEntryException();

    else
        return atoi(str.c_str());
}

bool Cell::checkValue() {
    if (m_defaultValue != 0)
        return false;

    try {
        getValue();
    } catch (Utils::NotValidEntryException) {
        return false;
    }
    
    return true;
}

void Cell::changeValue(int val) {
    if (m_defaultValue != 0)
        resetValue();

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setBackground(m_color);
    item->setText(QString::number(val));
    m_widget->setItem(m_row, m_col, item);
}

void Cell::resetValue() {
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setBackground(m_color);
    if (m_defaultValue == 0)
        item->setText("");
    else
        item->setText(QString::number(m_defaultValue));
    m_widget->setItem(m_row, m_col, item);
}

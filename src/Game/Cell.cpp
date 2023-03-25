#include "Cell.h"
#include "Utils.h"
#include <asm-generic/errno.h>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>

Cell::Cell(QTableWidget *widget, int row, int col, int default_value) 
    : m_row(row), m_col(col), m_defaultValue(default_value), m_widget(widget) {
    
    std::cout << "Cell construct at row: " << row << ", col: " << col << std::endl;
    if (m_defaultValue != 0) {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(m_defaultValue));
        m_widget->setItem(m_row, m_col, item);
    }
}

int Cell::getValue() {
    std::string str = m_widget->item(m_row, m_col)->text().toStdString();
    if (str.length() != 1 || !std::all_of(str.begin(), str.end(), ::isdigit) || atoi(str.c_str()) == 0)
        throw Utils::NotValidEntryException();

    else
        return atoi(str.c_str());
}

bool Cell::checkValue() {
    try {
        getValue();
    } catch (Utils::NotValidEntryException) {
        return false;
    }
    
    return true;
}

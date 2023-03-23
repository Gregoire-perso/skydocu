#include "Cell.h"
#include "Utils.h"
#include <asm-generic/errno.h>
#include <cstdlib>
#include <string>
#include <algorithm>

Cell::Cell(QTableWidget *widget, int row, int col, int default_value = 0) 
    : m_row(row), m_col(col), m_defaultValue(default_value), m_widget(widget) {
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText(m_defaultValue);
    m_widget->setItem(m_row, m_col, item);
}

int Cell::getValue() {
    std::string str = m_widget->item(m_row, m_col)->text().toStdString();
    if (str.length() != 1 || !std::all_of(str, str.end(), ::isdigit))
        throw Utils::NotValidEntryException;

    else
        return atoi(str);
}

bool Cell::checkValue() {
    
}



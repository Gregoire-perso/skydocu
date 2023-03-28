#include "Cell.h"
#include "Utils.h"
#include <asm-generic/errno.h>
#include <cstdlib>
#include <string>
#include <algorithm>

Cell::Cell(QTableWidget *widget, int row, int col, int default_value) 
    : m_row(row), m_col(col), m_defaultValue(default_value), m_widget(widget) {
    
    if (Utils::getSquareNumber(m_row, m_col) % 2 == 0)
        m_backColor = Qt::lightGray;

    else
        m_backColor = Qt::transparent;

    if (m_defaultValue != 0)
        m_fontColor = Qt::black;

    else
        m_fontColor = Qt::blue;

    resetValue();
}

void Cell::setItem(QString str) {
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setBackground(m_backColor);
    item->setForeground(m_fontColor);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(str);
    m_widget->setItem(m_row, m_col, item);
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

    setItem(QString::number(val));
}

void Cell::resetValue() {
    if (m_defaultValue == 0)
        setItem();
    else
        setItem(QString::number(m_defaultValue));
}

void Cell::changeBackground(QColor color) {
    if (m_defaultValue != 0)
        resetValue();

    else if (color == NULL)
        m_widget->item(m_row, m_col)->setBackground(m_backColor);
    
    else
        m_widget->item(m_row, m_col)->setBackground(color);
}

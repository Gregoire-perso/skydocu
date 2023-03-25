#include "sudokuwindow.h"
#include "Game/Sudoku.h"
#include "ui_sudokuwindow.h"
#include <iostream>

SudokuWindow::SudokuWindow(Difficulty d, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuWindow)
{
    ui->setupUi(this);
    sudoku = new Sudoku(ui->sudokuWidget, d);
    m_initFinished = true;
}

SudokuWindow::SudokuWindow(int custom, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuWindow)
{
    ui->setupUi(this);
    sudoku = new Sudoku(ui->sudokuWidget, custom);
}

SudokuWindow::~SudokuWindow()
{
    delete ui;
}

void SudokuWindow::on_sudokuWidget_cellChanged(int row, int column)
{
    if (m_initFinished) {
        ui->sudokuWidget->item(row, column)->setBackgroundColor(Qt::transparent);
        if (!sudoku->checkCell(row, column)) {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText("");
            ui->sudokuWidget->setItem(row, column, item);
        }

        if (ui->checkGrid->isChecked()) {
            if (!sudoku->IsValidBoard()) {
                QTableWidgetItem *item = new QTableWidgetItem;
                item->setText(ui->sudokuWidget->item(row, column)->text());
                item->setBackground(Qt::red);
                ui->sudokuWidget->setItem(row, column, item);
            }
        }
    }
}


void SudokuWindow::on_validateButton_clicked()
{

}


void SudokuWindow::on_backButton_clicked()
{

}


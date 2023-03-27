#include "sudokuwindow.h"
#include "mainwindow.h"
#include "Game/Sudoku.h"
#include "ui_sudokuwindow.h"
#include <iostream>

SudokuWindow::SudokuWindow(MainWindow *main, Difficulty d, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuWindow),
    m_main(main)
{
    ui->setupUi(this);
    sudoku = new Sudoku(this, d);
    cellChangeAllowed = true;
}

SudokuWindow::SudokuWindow(MainWindow *main, int custom, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuWindow),
    m_main(main)
{
    ui->setupUi(this);
    sudoku = new Sudoku(this, custom);
    cellChangeAllowed = true;
}

SudokuWindow::~SudokuWindow()
{
    delete sudoku;
    delete ui;
}

void SudokuWindow::on_sudokuWidget_cellChanged(int row, int column)
{
    if (cellChangeAllowed) {
        cellChangeAllowed = false;
        //ui->sudokuWidget->item(row, column)->setBackgroundColor(Qt::transparent);
        cellChangeAllowed = true;
        if (!sudoku->checkCell(row, column)) {
            sudoku->resetCell(row, column);
            return;
        }

        sudoku->updateBoard(row, column);
        sudoku->printBoard();

        if (ui->checkGrid->isChecked()) {
            std::cout << "Check cell value" << std::endl;
            if (!(sudoku->IsValidSquare(row, column) ||
                  sudoku->IsValidCol(column) ||
                  sudoku->IsValidRow(row))) {
                std::cout << "Not valid value" << std::endl;
                cellChangeAllowed = false;
                ui->sudokuWidget->item(row, column)->setBackgroundColor(Qt::red);
                cellChangeAllowed = true;
            }
        }
    }
}


void SudokuWindow::on_validateButton_clicked()
{

}


void SudokuWindow::on_backButton_clicked()
{
    this->hide();
    m_main->show();
    delete this;
}


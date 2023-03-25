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
    if (sudoku->checkCell(row, column)
}


void SudokuWindow::on_validateButton_clicked()
{

}


void SudokuWindow::on_backButton_clicked()
{

}


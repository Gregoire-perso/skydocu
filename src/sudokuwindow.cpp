#include "sudokuwindow.h"
#include "Game/Sudoku.h"
#include "ui_sudokuwindow.h"
#include <iostream>

SudokuWindow::SudokuWindow(Difficulty d, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuWindow)
{
    std::cout << "Diff " << (int) d << std::endl;
    sudoku = new Sudoku(ui->sudokuWidget, d);
    ui->setupUi(this);
}

SudokuWindow::SudokuWindow(int custom, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuWindow)
{
    std::cout << "Cust " << custom << std::endl;
    sudoku = new Sudoku(ui->sudokuWidget, custom);
    ui->setupUi(this);
}

SudokuWindow::~SudokuWindow()
{
    delete ui;
}

void SudokuWindow::on_sudokuWidget_cellChanged(int row, int column)
{

}


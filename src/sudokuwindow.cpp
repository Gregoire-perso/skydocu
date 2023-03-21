#include "sudokuwindow.h"
#include "ui_sudokuwindow.h"

SudokuWindow::SudokuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuWindow)
{
    ui->setupUi(this);
}

SudokuWindow::~SudokuWindow()
{
    delete ui;
}

void SudokuWindow::on_sudokuWidget_cellChanged(int row, int column)
{

}


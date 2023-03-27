#include "sudokuwindow.h"
#include "mainwindow.h"
#include "Game/Sudoku.h"
#include "ui_sudokuwindow.h"
#include <QMessageBox>
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
        if (!sudoku->checkCell(row, column)) {
            sudoku->resetCell(row, column);
            return;
        }

        sudoku->updateBoard(row, column);
        sudoku->printBoard();

        if (ui->checkGrid->isChecked()) {
            if (!(sudoku->IsValidSquare(row, column) ||
                  sudoku->IsValidCol(column) ||
                  sudoku->IsValidRow(row))) {
                cellChangeAllowed = false;
                ui->sudokuWidget->item(row, column)->setBackground(Qt::red);
                cellChangeAllowed = true;
            }
        }
    }
}


void SudokuWindow::on_validateButton_clicked()
{
    if (!sudoku->IsValidBoard()) {
        QMessageBox::warning(
                this, 
                tr("Skydocu"),
                tr("The sudoku grid is not valid!\nClick on the check box to highlight wrong cells") );
    }

    else if (!sudoku->IsSolved()) {
        QMessageBox::warning(
                this, 
                tr("Skydocu"),
                tr("The sudoku grid is not solved!"));
    }

    else {
        QMessageBox::information(
                this, 
                tr("Skydocu"),
                tr("Congrats! The sudoku is solved!"));
    }
}


void SudokuWindow::on_backButton_clicked()
{
    this->hide();
    m_main->show();
    delete this;
}

void SudokuWindow::on_solveButton_clicked()
{
    if (!sudoku->Solve())
        QMessageBox::warning(
                this, 
                tr("Skydocu"),
                tr("The sudoku grid is not solvable!"));
    
    else
        sudoku->updateAllCells();
}


void SudokuWindow::on_resetButton_clicked()
{
    sudoku->resetAllCells();
}


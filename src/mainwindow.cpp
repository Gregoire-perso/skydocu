#include "mainwindow.h"
#include "Game/Sudoku.h"
#include "ui_mainwindow.h"
#include "sudokuwindow.h"
#include <iostream>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customEmptyCells->setVisible(false);
    ui->verticalLayout->setAlignment(ui->sliderValue, Qt::AlignCenter);
    ui->sliderValue->setVisible(false);
    ui->customEmptyCells->setRange(10, 70);
}

MainWindow::~MainWindow()
{
    delete sudoku;
    delete ui;
}


void MainWindow::on_customButton_toggled(bool checked)
{
    if (ui->customEmptyCells->isVisible()) {
        ui->customEmptyCells->setVisible(false);
        ui->sliderValue->setVisible(false);
    }

    else {
        ui->customEmptyCells->setVisible(true);
        ui->sliderValue->setVisible(true);
    }
}


void MainWindow::on_customEmptyCells_valueChanged(int value)
{
    ui->sliderValue->setText(QString::number(ui->customEmptyCells->value()));
}


void MainWindow::on_startButton_clicked()
{
    // Get the radio button selected
    if (ui->easyButton->isChecked())
        sudoku = new SudokuWindow(this, Difficulty::Easy);

    else if (ui->intermediateButton->isChecked())
        sudoku = new SudokuWindow(this, Difficulty::Medium);

    else if (ui->hardButton->isChecked())
        sudoku = new SudokuWindow(this, Difficulty::Hard);

    else if (ui->customButton->isChecked())
        sudoku = new SudokuWindow(this, ui->customEmptyCells->value());
    
    else
        return;

    this->hide();
    sudoku->show();
}


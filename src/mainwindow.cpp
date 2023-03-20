#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customEmptyCells->setVisible(false);
    ui->sliderValue->setVisible(false);

    ui->customEmptyCells->setRange(10, 70);
}

MainWindow::~MainWindow()
{
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


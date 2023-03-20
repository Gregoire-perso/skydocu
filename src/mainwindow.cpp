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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_customButton_toggled(bool checked)
{
    if (ui->customEmptyCells->isVisible())
        ui->customEmptyCells->setVisible(false);

    else
        ui->customEmptyCells->setVisible(true);
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sudokuwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_customButton_toggled(bool checked);
    void on_customEmptyCells_valueChanged(int value);
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    Ui::SudokuWindow *sudoku;
};
#endif // MAINWINDOW_H

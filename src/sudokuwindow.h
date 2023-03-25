#ifndef SUDOKUWINDOW_H
#define SUDOKUWINDOW_H

#include "Game/Sudoku.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SudokuWindow; }
QT_END_NAMESPACE

class SudokuWindow : public QMainWindow
{
    Q_OBJECT

public:
    SudokuWindow(Difficulty d, QWidget *parent = nullptr);
    SudokuWindow(int custom, QWidget *parent = nullptr);
    ~SudokuWindow();

private slots:
    void on_sudokuWidget_cellChanged(int row, int column);

    void on_validateButton_clicked();

    void on_backButton_clicked();

private:
    Ui::SudokuWindow *ui;
    Sudoku *sudoku;
};

#endif // SUDOKUWINDOW_H

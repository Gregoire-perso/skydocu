#ifndef SUDOKUWINDOW_H
#define SUDOKUWINDOW_H

#include "Game/Sudoku.h"
#include <QMainWindow>

class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class SudokuWindow; }
QT_END_NAMESPACE

class SudokuWindow : public QMainWindow
{
    Q_OBJECT

public:
    SudokuWindow(MainWindow *main, Difficulty d, QWidget *parent = nullptr);
    SudokuWindow(MainWindow *main, int custom, QWidget *parent = nullptr);
    ~SudokuWindow();

private slots:
    void on_sudokuWidget_cellChanged(int row, int column);

    void on_validateButton_clicked();

    void on_backButton_clicked();

private:
    friend class Sudoku;
    Ui::SudokuWindow *ui;
    Sudoku *sudoku;
    MainWindow *m_main;
    bool cellChangeAllowed = false;
};

#endif // SUDOKUWINDOW_H

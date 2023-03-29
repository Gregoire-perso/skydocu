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
    /**
     * @brief Toogle the state of the custom slider
     *
     * This check if the slider is already shown and toogle its state
     */
    void on_customButton_toggled(bool checked);

    /**
     * @brief Change the text that show the value of the slider
     */
    void on_customEmptyCells_valueChanged(int value);

    /**
     * @brief Create the SudokuWindow and shows it
     */
    void on_startButton_clicked();

private:
    /// Pointer to the elements of the MainWindow
    Ui::MainWindow *ui;

    /// Pointer to the SudokuWindow object
    SudokuWindow *sudoku;
};
#endif // MAINWINDOW_H

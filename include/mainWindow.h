#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "board.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onColumnClicked(int col);

private:
    QPushButton *columnButtons[COLS];
    QLabel *cellLabels[ROWS][COLS];
    QLabel *statusLabel;
    char currentTurn;
    bool gameOver;

    void refreshBoard();
    void playerMove(int col);
    void computerMove();
    void endGame(const QString &message);
};

#endif
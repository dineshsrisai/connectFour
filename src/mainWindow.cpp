#include "mainwindow.h"
#include "ai.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initBoard();
    currentTurn = 'X';
    gameOver = false;

    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    statusLabel = new QLabel("Your turn (X)", this);
    mainLayout->addWidget(statusLabel);

    QHBoxLayout *buttonRow = new QHBoxLayout();
    for (int c = 0; c < COLS; c++)
    {
        columnButtons[c] = new QPushButton(QString::number(c + 1), this);
        int col = c;
        connect(columnButtons[c], &QPushButton::clicked, this, [this, col]()
                { onColumnClicked(col); });
        buttonRow->addWidget(columnButtons[c]);
    }
    mainLayout->addLayout(buttonRow);

    QGridLayout *grid = new QGridLayout();
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            cellLabels[r][c] = new QLabel(this);
            cellLabels[r][c]->setFixedSize(50, 50);
            cellLabels[r][c]->setAlignment(Qt::AlignCenter);
            cellLabels[r][c]->setStyleSheet("background-color: white; border: 1px solid black; border-radius: 25px;");
            grid->addWidget(cellLabels[r][c], r, c);
        }
    }
    mainLayout->addLayout(grid);

    setWindowTitle("Connect Four");
}

void MainWindow::refreshBoard()
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            QString color = "white";
            if (grid[r][c] == 'X')
                color = "red";
            else if (grid[r][c] == 'O')
                color = "yellow";
            cellLabels[r][c]->setStyleSheet(
                QString("background-color: %1; border: 1px solid black; border-radius: 25px;").arg(color));
        }
    }
}

void MainWindow::onColumnClicked(int col)
{
    if (gameOver || currentTurn != 'X')
        return;
    playerMove(col);
}

void MainWindow::playerMove(int col)
{
    int r = dropPiece(col, 'X');
    if (r == -1)
        return;

    refreshBoard();

    if (checkWin(r, col, 'X'))
    {
        endGame("You win!");
        return;
    }
    if (isDraw())
    {
        endGame("Draw!");
        return;
    }

    currentTurn = 'O';
    statusLabel->setText("Computer thinking...");
    QApplication::processEvents();
    computerMove();
}

void MainWindow::computerMove()
{
    int col = getBestMove();
    int r = dropPiece(col, 'O');

    refreshBoard();

    if (checkWin(r, col, 'O'))
    {
        endGame("Computer wins!");
        return;
    }
    if (isDraw())
    {
        endGame("Draw!");
        return;
    }

    currentTurn = 'X';
    statusLabel->setText("Your turn (X)");
}

void MainWindow::endGame(const QString &message)
{
    gameOver = true;
    statusLabel->setText(message);
    QMessageBox::information(this, "Game Over", message);
}
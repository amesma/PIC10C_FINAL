#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include "minesweeper.h"
#include "minebutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    void changeButton(mineButton* button, int row, int col);
    ~MainWindow();
    void win_game();
    void lose_game();
    void reset_game();
    int num_mines = 9;

private:
    Ui::MainWindow *ui;
    Minesweeper *m;
    QSignalMapper *mapper;

    bool game_start;
    bool game_done;
    int times_played;
    int cells_flagged;
    int bombs_found;
    int cells_left;
    int hasFlag[9][9];

protected slots:
    /**
      Slots needed:
      void reset() to reset the game
      void button_pressed(); reacts when user clicks on a tile/other buttons
    */
    void reset();
    void button_pressed(mineButton* button);

public slots:
    void showTiles(QString);

};

#endif // MAINWINDOW_H

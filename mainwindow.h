#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QSignalMapper>
#include "minesweeper.h"
#include "minebutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = 0);
    void change_button(int row, int col, mineButton* button);//should change to correspond to which icons are available
    ~MainWindow();
    void win_game();
    void lose_game();
    void reset_game();
    void recurse_clear( bool can_clear, int row, int col);
    int num_mines = 9;

private:
    Ui::MainWindow *ui;
    Minesweeper *m;
    QSignalMapper *mapper;

    bool game_done;
    int cells_flagged;
    int bombs_found;
    int cells_left;
    int hasFlag[9][9];
    int mines = 9;
    int button_size = 100;
    bool flag_on = false;

protected slots:
    /**
      Slots needed:
      void reset() to reset the game when new game is pushed
      void flag_mines() to flag mines
      void button_pressed(); reacts when user clicks on a tile/other buttons
    */
    void reset();
    void flag_mines();
    //void button_pressed(mineButton* button, int row, int col);//add additional functions

public slots:

    void show_tile(QString);

};

#endif // MAINWINDOW_H

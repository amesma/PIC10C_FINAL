#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include "minesweeper.h"
#include "minebutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
=======
    MainWindow(QWidget* parent = 0);
    void change_button(int row, int col, mineButton* button);//should change to correspond to which icons are available
    ~MainWindow();
    void win_game();
    void lose_game();
    void reset_game();
    void recurse_clear( bool can_clear, int row, int col);
    int num_mines = 9;
>>>>>>> 57ba17f1bcd65f64ccdd5d1cdc8f329f58da0ba0

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
<<<<<<< HEAD
    int hasMine[9][9];
    void changeButton(mineButton* button);
=======
    int hasFlag[9][9];
    int mines = 9;
    int button_size = 100;
>>>>>>> 57ba17f1bcd65f64ccdd5d1cdc8f329f58da0ba0

protected slots:
    /**
      Slots needed:
      void reset() to reset the game when new game is pushed
      void flag_mines() to flag mines
      void button_pressed(); reacts when user clicks on a tile/other buttons
    */
    void reset();
<<<<<<< HEAD
    void button_pressed();

public slots:
    void showCell();

public:
    void win_game();
    void lose_game();
    void reset_game();

    int num_mines = 9;
=======
    void flag_mines();
    //void button_pressed(mineButton* button, int row, int col);//add additional functions

public slots:

    void show_tile(QString);
>>>>>>> 57ba17f1bcd65f64ccdd5d1cdc8f329f58da0ba0

};

#endif // MAINWINDOW_H

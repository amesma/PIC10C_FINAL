#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
    int hasMine[9][9];
    void changeButton(mineButton* button);

protected slots:
    /**
      Slots needed:
      void reset() to reset the game
      void button_pressed(); reacts when user clicks on a tile/other buttons
    */
    void reset();
    void button_pressed();

public slots:
    void showCell();

public:
    void win_game();
    void lose_game();
    void reset_game();

    int num_mines = 9;

};

#endif // MAINWINDOW_H

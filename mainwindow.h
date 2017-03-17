#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    bool game_start;
    bool game_done;
    int times_played;
    int cells_flagged;
    int bombs_found;
    int cells_left;

protected slots:
    /**
      Slots needed:
      void reset();
      void buttonReleased();
      void buttonPressed();
    */
    void reset();
    void button_pressed();

public slots:
    void showCell();

public:
    void win_game();
    void lose_game();
    void reset_game();

};

#endif // MAINWINDOW_H

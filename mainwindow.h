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
    bool game_start;
    bool game_done;
    int times_played;
    int cells_flagged;
    int bombs_found;
    int cells_left;
};

#endif // MAINWINDOW_H

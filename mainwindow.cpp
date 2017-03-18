#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //sets up the UI
    ui->setupUi(this);

    //initialize some play variables
    game_start = false;
    game_done = false;
    times_played = 0;
    cells_flagged = 0;
    bombs_found = 0;
    cells_left = 0;

    connect(ui->newGame, SIGNAL(clicked()), this, SLOT(reset()));

    //game begins here
    game = new Minesweeper();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset() {
    game_start = false;
    game_done = false;
    times_played = 0;
    cells_flagged = 0;
    bombs_found = 0;
    cells_left = 0;

    //displays the current score, reset to 0.
   // ui->userScore->display(num_mines - cells_flagged);

    //start new game
    //game = new Minesweeper();
    //reset the board
    //make board elements
}

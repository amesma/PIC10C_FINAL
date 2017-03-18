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

    //in the beginning no mines are flagged
    for (size_t i = 0; i < 9; ++i){
        for (size_t j = 0; j < 9; ++j)
        {
            hasFlag[i][j] = 0;
        }
    }
    ui->gameLayout->setSpacing(1);
    int button_size = 50;
    //set up minebuttons
    for (size_t row = 0; row < 9; ++row)
    {
        for (size_t col = 0; col < 9; ++col){
            mineButton* new_button = new mineButton();
            QPixmap pix(":/norm_button.png");
            QIcon icon(pix);
            new_button->setIcon(icon);
            new_button->setIconSize(QSize(button_size,button_size));
            ui->gameLayout->addWidget(new_button, row, col);
        }
    }
    connect(ui->newGame, SIGNAL(clicked()), this, SLOT(reset()));

    //game begins here
    m = new Minesweeper();
    //set all flags/bombs in correct places

    //sets up spacing for game


}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
resets game for if the player wins or loses
*/
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

/**
  check to see the value of the minesweeper object
  if button is zero, use the regular button

  if value is 1, change value to one
  if value is 2, change value to 2
  etc
*/
void MainWindow::changeButton(mineButton* button, int row, int col){

}

void MainWindow::win_game(){
//should display second window that says congrats and ask them to play again
    //record number of times played
}

void MainWindow::lose_game(){
//should lose the game and display second window
    //record losses
}

void MainWindow::showTiles(QString){

}

void MainWindow::button_pressed(mineButton *button){

}

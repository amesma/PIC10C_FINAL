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
    cells_left = 81 - 9;

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
            //map to signal so you connect each button to a click
            QString location = QString::number(row) + " " + QString::number(col);
            mapper->setMapping(new_button, location);
            connect(new_button, SIGNAL(pressed()), this, SLOT(button_pressed()));
        }
    }
    connect(ui->newGame, SIGNAL(clicked()), this, SLOT(reset()));
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(show_tile(QString)));
   // connect(ui->flag_box, SIGNAL(stateChanged(int)), this, SLOT(flag_mines()));

    //game begins here
    m = new Minesweeper();
    //set all flags/bombs in correct places

    //sets up spacing for game
    //set up win state
    //set up lose state
    //keep track of bombs
    //update images (recursively?)



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

    //start new game
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
void MainWindow::changeButton(int row, int col, mineButton* button){

}

void MainWindow::win_game(){
//should display second window that says congrats and ask them to play again
    //record number of times played
}

void MainWindow::lose_game(){
//should lose the game and display second window
    //record losses
}

//should change the tile depending on what is under the button
void MainWindow::show_tile(QString q){
//get coordinates
  /**  QStringList result = q.split(" ");

    int row = result[0].toInt();
    int col = result[1].toInt();

    mineButton *push = reinterpret_cast<mineButton *>(mapper->mapping(q));
//get button pressed

    //check to see if button already pressed (not implemented)

    //check if win/lose (not implemented)

    //recursively call to clear board
    if ( m->getTile(row, col) == 0 ) {
        --cells_left;
        recurse_clear(true, row, col);
    }

    //Set the image according to the value of the cell
    changeButton(row, col, push);

    push->setFlat(true);

    //If we reveal a mine, we just lost :(
    if ( m->isMine(row,col))
    {
        lose_game();
    }*/
}

//void MainWindow::button_pressed(mineButton *button){
//for any potential special actions
//}

void MainWindow::recurse_clear(bool can_clear, int row, int col){

}

void MainWindow::flag_mines(){

}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSignalMapper>
#include <QDebug>

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
    cells_left = 72;

    m = new Minesweeper();
    mapper = new QSignalMapper(this);

    //in the beginning no mines are flagged
    for (size_t i = 0; i < 9; ++i){
        for (size_t j = 0; j < 9; ++j)
        {
            hasFlag[i][j] = 0;
        }
    }
    ui->gameLayout->setSpacing(3);
    int button_size = 100;
    //set up minebuttons
    for (size_t row = 0; row < 9; ++row)
    {
        for (size_t col = 0; col < 9; ++col){
            mineButton* new_button = new mineButton();
            QPixmap pix(":/normal.png");
            QIcon icon(pix);
            new_button->setIcon(icon);
            new_button->setIconSize(QSize(button_size,button_size));
            new_button->setFlat(false);
            ui->gameLayout->addWidget(new_button, row, col);
            //map to signal so you connect each button to a click
            QString location = QString::number(row) + "," + QString::number(col);

            mapper->setMapping(new_button, location);
            //Connections for the buttons
            connect(new_button, SIGNAL(clicked()), mapper, SLOT(map()));

            //connect(new_button, SIGNAL(pressed()), this, SLOT(button_pressed()));
       }
  }
    connect(ui->newGame, SIGNAL(clicked()), this, SLOT(reset()));
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(show_tile(QString)));
    connect(ui->flag_box, SIGNAL(stateChanged()), this, SLOT(flag_mines()));

    //game begins here
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
void MainWindow::change_button(int row, int col, mineButton* button){
    //Set the image according to the value of the cell
    switch(m->getTile(row, col)){
    case 0: button->setIcon(QIcon(QString(":/images/empty.png")));
    case 1: button->setIcon(QIcon(QString(":/images/button_1.png")));
    case 2: button->setIcon(QIcon(QString(":/images/button_2.png")));
    case 3: button->setIcon(QIcon(QString(":/images/button_3.png")));
    case 4: button->setIcon(QIcon(QString(":/images/button_4.png")));
    case 5: button->setIcon(QIcon(QString(":/images/button_5.png")));
    case 6: button->setIcon(QIcon(QString(":/images/button_6.png")));
    case 7: button->setIcon(QIcon(QString(":/images/button_7.png")));
    case 8: button->setIcon(QIcon(QString(":/images/button_8.png")));
    case 9: button->setIcon(QIcon(QString(":/images/mine.png")));
    }
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
  QStringList result = q.split(",");

    int row = result.at(0).toInt();
    int col = result.at(1).toInt();

    mineButton *push = qobject_cast<mineButton *>(mapper->mapping(q));
//get button pressed

    if (push->isFlat())
    {
            --cells_left;
    }

    //check to see if button already pressed (not implemented)

    //check if win/lose (not implemented)

    //recursively call to clear board
    if ( m->getTile(row, col) == 0 ) {
        --cells_left;
        recurse_clear(true, row, col);
    }
    //set a signal
    change_button(row, col, push);
    push->setFlat(true);
    //lose state
    if ( m->isMine(row,col))
    {
        lose_game();
    }
}

//void MainWindow::button_pressed(mineButton *button){
//for any potential special actions
//}

void MainWindow::recurse_clear(bool can_clear, int row, int col){

}

void MainWindow::flag_mines(){

}

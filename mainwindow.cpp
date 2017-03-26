#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "minesweeper.h"

#include <QSignalMapper>
#include <QDebug>
#include <QMessageBox>

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

    ui->gameLayout->setSpacing(3);
    m = new Minesweeper();
    mapper = new QSignalMapper(this);

    //in the beginning no mines are flagged
    for (size_t i = 0; i < mines; ++i){
        for (size_t j = 0; j < mines; ++j)
        {
            hasFlag[i][j] = 0;
        }
    }
    //set up minebuttons
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col){
            mineButton* new_button = new mineButton();
            QPixmap pix(":/normal.png");
            QIcon icon(pix);
            new_button->setIcon(icon);
            new_button->setIconSize(QSize(button_size,button_size));

            //map to signal so you connect each button to a click
            QString location = QString::number(row) + "," + QString::number(col);

            connect(new_button, SIGNAL(clicked()), mapper, SLOT(map()));

            mapper->setMapping(new_button, location);

            ui->gameLayout->addWidget(new_button, row, col);

            //connect(new_button, SIGNAL(pressed()), this, SLOT(button_pressed()));
       }
  }

    connect(ui->newGame, SIGNAL(clicked()), this, SLOT(reset()));
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(show_tile(QString)) );
    connect(ui->flag_box, SIGNAL(stateChanged(int)), this, SLOT(flag_mines()));

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

    m = new Minesweeper();

    for( int i = 0; i < 9; i++)
    {
        for( int j = 0; j < 9; j++ )
        {
            QString coord = QString::number(i)+","+QString::number(j);
            mineButton *push = qobject_cast<mineButton *>(mapper->mapping(coord));

            push->setIcon (QIcon(":/images/norm.png"));
            push->setIconSize (QSize(button_size,button_size));
            push->set_pushed(false);
            hasFlag[i][j] = 0;
        }
    }
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

    if( m->getTile(row, col) == 0)
       { button->setIcon(QIcon(QString(":/empty.png")));}
    if( m->getTile(row, col) == 1)
    { button->setIcon(QIcon(QString(":/button_1.png")));}
    if( m->getTile(row, col) == 2)
      {  button->setIcon(QIcon(QString(":/button_2.png")));}
    if( m->getTile(row, col) == 3){
        button->setIcon(QIcon(QString(":/button_3.png")));}
    if( m->getTile(row, col) == 4){
        button->setIcon(QIcon(QString(":/button_4.png")));}
    if( m->getTile(row, col) == 5){
        button->setIcon(QIcon(QString(":/button_5.png")));}
    if( m->getTile(row, col) == 6){
        button->setIcon(QIcon(QString(":/button_6.png")));}
    if( m->getTile(row, col) == 7){
        button->setIcon(QIcon(QString(":/button_7.png")));}
    if( m->getTile(row, col) == 8){
        button->setIcon(QIcon(QString(":/button_8.png")));}
    if( m->getTile(row, col) == 9){
        button->setIcon(QIcon(QString(":/mine.png")));
    }
}

void MainWindow::win_game(){
//should display second window that says congrats and ask them to play again
    //record number of times played
}

void MainWindow::lose_game(){
//should lose the game and display second window
    //record losses
    QMessageBox messageBox;
    messageBox.critical(0,"UH OH","You Lost!");
    messageBox.setFixedSize(500,200);
    game_done = true;

    //should show board
    for ( int i = 0; i < 9; ++i)
    {
        for ( int j = 0; j < 9; ++j)
        {
            QString coord = QString::number(i)+","+QString::number(j);
            mineButton *push = qobject_cast<mineButton *>(mapper->mapping(coord));

            if (m->isMine(i,j) == true )
            {
                push->set_pushed(true);

                if ( hasFlag[i][j] == 1) {
                    push->setIcon (QIcon(QString(":/flat.png")));
                }
                else {

                    push->setIcon (QIcon(QString(":/mine.png")));
                }
            }

        }
    }
}

//should change the tile depending on what is under the button
void MainWindow::show_tile(QString q){

//get coordinates
  QStringList result = q.split(",");

    int row = result[0].toInt();
    int col = result[1].toInt();

    mineButton *push = qobject_cast<mineButton *>(mapper->mapping(q));
//get button pressed

    if (push->is_pushed() == false)
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

    push->set_pushed(true);
    //lose state
    if ( m->isMine(row,col))
    {
        lose_game();
    }
}

void MainWindow::recurse_clear(bool can_clear, int row, int col){

}

void MainWindow::flag_mines(){


}

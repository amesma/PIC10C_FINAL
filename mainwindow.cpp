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
    game_done = false;
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

    game_done = false;
    cells_flagged = 0;
    bombs_found = 0;
    cells_left = 0;

    m = new Minesweeper();

    for( int i = 0; i < 9; i++)
    {
        for( int j = 0; j < 9; j++ )
        {
            QString coord = QString::number(i)+","+QString::number(j);
            mineButton *push = qobject_cast<mineButton*>(mapper->mapping(coord));
            QPixmap pix(":/normal.png");
            QIcon icon(pix);
            push->setIcon(icon);

            push->setIconSize(QSize(button_size,button_size));
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

    if (flag_on == true && cells_left > 0 && ((9 - cells_flagged) > 0) && button->is_pushed() == false)
    {
        button->setIcon(QIcon(QString(":/flag.png")));
        button->set_pushed(true);
        ++cells_flagged;
        //found a bomb
        if (m->getTile(row, col) == 9){
        ++bombs_found;
        }
        //get to win state
        if (bombs_found == 9){
            win_game();
        }
    }
    else{

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

    QString coord = QString::number(row)+","+QString::number(col);
    mineButton *push = qobject_cast<mineButton*>(mapper->mapping(coord));
if (flag_on == false){
  if ( m->getTile(row, col) == 0 && push->is_pushed() == false && can_clear == true) {

     change_button(row, col, push);
     push->set_pushed(true);
     cells_left--;
        //should check left right and up down

  if (cells_left == 9 && m->isMine(row, col) == false){

      win_game();
  }

  if (m->getTile(row, col) == 0)
  {
      can_clear = true;
  }
  else{
      can_clear = false;
  }

  if ((row - 1 != -1 ) && (col - 1) != -1)
  {
    recurse_clear(can_clear, row - 1, col - 1);
  }
  if ((col - 1) > -1)
  {
     recurse_clear(can_clear, row, col - 1);
  }
 if ((row - 1) > -1)
  {
    recurse_clear(can_clear, row - 1, col);
  }
  if ((row - 1 > -1 ) && (col + 1) < 9)
  {
    recurse_clear(can_clear, row - 1, col + 1);
  }
  if ((col + 1) < 9)
  {
    recurse_clear(can_clear, row, col + 1);
  }
  if ((row + 1) < 9)
  {
    recurse_clear(can_clear, row + 1, col);
  }
  if ((row + 1 < 9) && (col + 1) < 9)
  {
    recurse_clear(can_clear, row+1, col+1);
  }
  if ((col - 1 > -1 ) && (row + 1) < 9)
  {
    recurse_clear(can_clear, row + 1, col - 1);
  }

  }
}
}
void MainWindow::win_game(){
    //flag all 9 to win
    QMessageBox messageBox;
    messageBox.critical(0,"Congratulations!","You Won!");
    messageBox.setFixedSize(500,200);
    game_done = true;
}

void MainWindow::flag_mines(){
if (ui->flag_box->isChecked() == true){
    flag_on = true;
}
else{
    flag_on = false;
}
//not working for now
}

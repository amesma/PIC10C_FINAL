#include "minesweeper.h"

Minesweeper::Minesweeper()
{
    num_tiles = 9;
    num_mines = 9;
    for (size_t i = 0; i < num_tiles; i++)
    {
        for (size_t j = 0; j < num_tiles; j++)
        {
            //initialization
            gameBoard[i][j] = 0;
        }
    }

    fill_board();

}
Minesweeper::~Minesweeper(){

}

void Minesweeper::fill_board(){
    for( int i = 0; i < num_mines; i++)
    {
        int row, col;

        //Prevent generating mine on another mine
        do
        {
            row = qrand() % 9;
            col = qrand() % 9;
        }while(gameBoard[row][col] == num_tiles);

        gameBoard[row][col] = num_tiles; //Number 9 indiciates a mine

     if ( row != 0 && col != 0 && gameBoard[row-1][col-1] != num_mines){

         gameBoard[row-1][col-1] = gameBoard[row-1][col-1] + 1;
     }

     if ( row != 0 && gameBoard[row-1][col] != num_mines){
         gameBoard[row-1][col] = gameBoard[row-1][col] + 1;
     }

     if ( row != 0 && (col + 1) != 10 && gameBoard[row-1][col+1] != num_mines){
            gameBoard[row-1][col+1]++;
     }

     if ( (col -1) != -1 && gameBoard[row][col-1] != num_mines){
            gameBoard[row][col-1]++;
     }

     if ( (col + 1) != num_tiles && gameBoard[row][col+1] != num_mines){
             gameBoard[row][col+1]++;
     }

     if ( (row+1) != num_tiles && (col -1) != -1 && gameBoard[row+1][col-1] != num_mines){
             gameBoard[row+1][col-1]++;
     }

     if ( (row+1) != num_tiles && gameBoard[row+1][col] != num_mines){
            gameBoard[row+1][col]++;
     }

     if ( (row+1) != num_tiles && (col+1) != num_tiles && gameBoard[row+1][col+1] != num_mines){
             gameBoard[row+1][col+1]++;
     }
    }
}


bool Minesweeper::isMine(int x, int y){
    return (gameBoard[x][y] == num_mines);
}

int Minesweeper::getTile(int x, int y){
    return gameBoard[x][y];
}

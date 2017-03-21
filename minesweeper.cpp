#include "minesweeper.h"
#include <QtGlobal>

Minesweeper::Minesweeper()
{
    num_tiles = 9;
    num_mines = 10;
    for (size_t i = 0; i < num_tiles; i++)
    {
        for (size_t j = 0; j < num_tiles; j++)
        {
            //initialization
            gameBoard[i][j] = 0;
        }
    }
}
//so far, no memory allocated on heap
Minesweeper::~Minesweeper(){

}

void Minesweeper::fillBoard(){
    for (size_t i = 0; i < 10; i++){
        int row, col;

        do{
            row = rand() % 9 + 1;
            col = rand() % 9 + 1;
        }while(gameBoard[row][col] == num_mines);

        gameBoard[row][col] = num_mines;

        if ( (row-1) != -1 && (col -1) != -1 && gameBoard[row-1][col-1] != num_mines)
            gameBoard[row-1][col-1]++;

                if ( (row-1) != -1 && gameBoard[row-1][col] != num_mines)
                    gameBoard[row-1][col]++;

                if ( (row-1) != -1 && (col + 1) != 10 && gameBoard[row-1][col+1] != num_mines)
                    gameBoard[row-1][col+1]++;

                if ( (col -1) != -1 && gameBoard[row][col-1] != num_mines)
                    gameBoard[row][col-1]++;

                if ( (col + 1) != 10 && gameBoard[row][col+1] != num_mines)
                    gameBoard[row][col+1]++;

                if ( (row+1) != 10 && (col -1) != -1 && gameBoard[row+1][col-1] != num_mines)
                    gameBoard[row+1][col-1]++;

                if ( (row+1) != 10 && gameBoard[row+1][col] != num_mines)
                    gameBoard[row+1][col]++;

                if ( (row+1) != 10 && (col+1) != 10 && gameBoard[row+1][col+1] != num_mines)
                    gameBoard[row+1][col+1]++;
            }
    }

bool Minesweeper::isMine(int x, int y) const {
    return (gameBoard[x][y] == num_mines);
}

int Minesweeper::getTile(int x, int y){
    return gameBoard[x][y];
}

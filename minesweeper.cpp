Minesweeper::Minesweeper()
{
    num_tiles = 9;
    num_mines = 10;
    for (size_t i = 0; i < num_tiles; i++)
    {
        for (size_t j = 0; j < num_tiles; j+++)
        {
            //initialization
            gameBoard[i][j] = 0;
        }
    }
}
//so far, no memory allocated on heap
virtual Minesweeper::~Minesweeper(){


}

void fillBoard(){
    for (size_t i = 0; i < 10; i++){
        int row, col;

        do{
            row = rand() % 9 + 1;
            col = rand() % 9 + 1;
        }while(gameBoard[row][col] == num_mines);

        gameBoard[row][col] = num_mines;

        if ( (row-1) != -1 && (col -1) != -1 && gameBoard[row-1][col-1] != num_mines)
                    mineBoard[row-1][column-1]++;

                if ( (row-1) != -1 && mineBoard[row-1][column] != num_mines)
                    mineBoard[row-1][column]++;

                if ( (row-1) != -1 && (column + 1) != 10 && mineBoard[row-1][column+1] != num_mines)
                    mineBoard[row-1][column+1]++;

                if ( (column -1) != -1 && mineBoard[row][column-1] != num_mines)
                    mineBoard[row][column-1]++;

                if ( (column + 1) != 10 && mineBoard[row][column+1] != num_mines)
                    mineBoard[row][column+1]++;

                if ( (row+1) != 10 && (column -1) != -1 && mineBoard[row+1][column-1] != num_mines)
                    mineBoard[row+1][column-1]++;

                if ( (row+1) != 10 && mineBoard[row+1][column] != num_mines)
                    mineBoard[row+1][column]++;

                if ( (row+1) != 10 && (column+1) != 10 && mineBoard[row+1][column+1] != num_mines)
                    mineBoard[row+1][column+1]++;
            }
    }
}

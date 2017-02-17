#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <stdlib.h>
class Minesweeper{
public:
    void newBoard();
    Minesweeper(int board_size);
    Minesweeper();
   // Minesweeper(const& Minesweeper m):num_tiles(m.num_tiles){}
    virtual ~Minesweeper();
    void fillBoard();
    bool isMine(int x, int y);
private:
    int num_tiles;
    int num_mines;
    int gameBoard[][];

}

#endif // MINESWEEPER_H

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <cstdlib>


class Minesweeper{

public:
    void newBoard();
    Minesweeper(int board_size);
    Minesweeper();
   // Minesweeper(const& Minesweeper m):num_tiles(m.num_tiles){}
    virtual ~Minesweeper();
    void fillBoard();
    bool isMine(int x, int y) const;
    int getTile(int x, int y) const ;
private:
    int num_tiles;
    int num_mines;
    int gameBoard[9][9];

};

#endif // MINESWEEPER_H

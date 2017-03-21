#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QtGlobal>


class Minesweeper{

public:
    Minesweeper(int board_size);
    Minesweeper();
   // Minesweeper(const& Minesweeper m):num_tiles(m.num_tiles){}
    virtual ~Minesweeper();
    void fill_board();
    bool isMine(int x, int y);
    int getTile(int x, int y);
private:
    int num_tiles;
    int num_mines;
    int gameBoard[9][9];

};

#endif // MINESWEEPER_H

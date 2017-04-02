# PIC10C_FINAL

This project will implement a simple version of minesweeper. This game of Minesweeper has a mineButton class that inherits from QPushButton that manages the properties of each button. The instances of these buttons will be connected to a QSignalMapper so that an array of buttons can be created and accessed easily. Without the QSignalMapper, it would be difficult to access the individual buttons created by the mineButton class. Once each button is clicked, this tells the signal mapper which button was pushed and what action to perform next. The connection of this signal with a function or associated action was done using SIGNALS and SLOTS, which are important aspects of Qt Creator. Once a button is clicked, it reveals if the button has a mine behind it, or if it has mines surrounding it. When a bomb is clicked on, it should reveal a tile indicating if there is a bomb behind it.

The UI: The interface of the game is created used Qt Designer, and the board by default has 9x9 tiles. There is a button for a new game that should reset the game tiles so that none are showing when clicked, as well as a checkbox that will allow the user to flag the 9 mines. The right LCD counter will tell the user how many flags they have already used.

This project should reflect the learning goals for the PIC10C course. Notably, the game is implemented using Qt, which automatically allocates and deletes resources safely so that there are no memory leaks, as long as the user does not try to manually delete references improperly. In addition, this project uses an object oriented style of programming to rely on inheritance and objects to manage memory and to create interfaces that can be used over and over again instead of single use functions.

Overall Goals: make sure Minesweeper.cpp has the functionality of a Minesweeper game. 

Goal 2: Implement the board UI. Make the game look like a game, even if it is not functional.

Goal 3: Make moves possible. All buttons should click and be associated with signals and slots.

Goal 3: Moves should count correctly and winning and losing should be implemented properly. Create a setting that allows the user to increase the number of tiles on the board to play a 16x16 board.

Current goal: Goal 2. Achieved. Currently I need to make it so that when a button pressed and is clear, you can recursively show the tiles until a tile that has a number on it (meaning it is bordering a bomb).

3/29/17: Goal 3 Achieved, flags not tested, win state not tested. Lose state is tested.

Test cases: Click new game without clicking on other tiles. Keep flagging until more than 9 tiles are clicked.

Bugs:

# PIC10C_FINAL

This project will implement a simple version of minesweeper. This game of Minesweeper has a mineButton class that inherits from QPushButton that manages the properties of each button. The instances of these buttons will be connected to a QSignalMapper so that an array of buttons can be created and accessed easily. Without the QSignalMapper, it would be difficult to access the individual buttons created by the mineButton class.

Goals: make sure Minesweeper.cpp has the functionality of a Minesweeper game. 

Goal 2: Implement the board UI. Make the game look like a game, even if it is none-functional.

Goal 3: Make moves possible. All buttons should click and be associated with signals and slots.

Goal 3: Moves should count correctly and winning and losing should be implemented properly.

Current goal: Goal 2. Achieved. Currently I need to make it so that when a button pressed and is clear, you can recursively show the tiles until a tile that has a number on it (meaning it is bordering a bomb) 

Test cases:

Bugs:

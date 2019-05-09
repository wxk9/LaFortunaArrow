# LaFortunaArrow

This is a simple game implementation for LaFortuna board. 

The idea was to build a music arcade game, like Just dance but interacting with buttons. The screen should display arrows pointed to different directions, and the player should press the button accordingly to gain score. 

In this version, the screen displays the direction in the middle of the screen and the score at the top left of the screen. The user should press the correct button to gain score. Without any action after a certain time, it will count as wrong input. There is no maximum score, but if the score goes down to lower than 3, then the game will end. 

# Instruction 

You should have dfu-programmer

- 1 Connect your LaFortuna board to computer. 
- 2 Open Terminal and change directory to where contains all the files.
- 3 Enter make -f Makefile to generate the .hex file which will automatically load to your board.

The program should be loaded to the board and you should now be able to play. 

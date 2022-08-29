# SO_LONG



</center>
# Description  
 This project is a very small 2D game. It is built to make you work with
textures, sprites. And some very basic gameplay elements.

# How play the game
To play this game you can use any map of your choice as long follow the following rues:

* The extension need be `.ber`
* Its must be rectangular, surrounded by wall `1`
* Must have only one exit, only one player and at least one collectible
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | wall                     |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |
|     *H*     | Enemy starting position  |

In folder [map_files](map_files) have some examples of maps.

# Control of play
You can use `AWSD` to move `UP`, `DOWN`, `LEFT`, `RIGHT`.  
For restart the game press `ESC` or click on the red cross of window.
If you touch the enemy you loose the game.
To win the game its necessary pick up all collectible and pass for the exit.

## Running sol_long ##

```bash
# Clone this project
$ git clone https://github.com/smkatash/42_so_long

# Access
$ cd 42_so_long/game

# Compile the program
$ make

# Run the project
$ ./so_long ../maps/..

```

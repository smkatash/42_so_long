# SO_LONG

# Description  
This project is a very small 2D game. It is made of basic textures, sprites and basic gameplay elements.

![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/76934648/187231929-df788ec7-7bce-4977-848f-f53079027dd8.gif)


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

In folder [maps](maps) have some examples of maps.

# Control of play
You can use `AWSD` to move `UP`, `DOWN`, `LEFT`, `RIGHT`.  
For restart the game press `ESC` or click on the red cross of window.
If you touch the enemy you loose the game.
To win the game its necessary pick up all collectible and pass for the exit.

## Running so_long ##

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

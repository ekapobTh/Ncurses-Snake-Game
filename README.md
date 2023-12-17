# 🐍 Snake Game (Ncurses Library) 

Snake game application for self-learning in C++ game programming using the Ncurses library.
 
## Compilation

To play this game, please follow the following instructions step-by-step.

* After cloned this project, get into the file directory using this command (change the `file directory` to the actual path where the file located)

```
cd [file directory]
```

* Then use this command to compile it. (if you decided to change the main code file to other names, please replace  `Snake` with that name also)

```
gcc Snake.cpp -o play -lncurses
```

* Cast this command to play.

```
./play
```
* Finally, enjoy 🕹️

## Controller

🆆🅰🆂🅳 will be the buttons used for control within this game.

* 🆆 - Up
* 🅰 - Left
* 🆂 - Down
* 🅳 - Right

## In-Game Component

Here are all the components within this game.

* `+` - Wall
* `X` - Egg
* `O` - Snake head
* `o` - Snake Tail

## How to play it?

1. When the game start use your controller button to control the snake.
2. Collect eggs as much as you can. (They will respawn at the new position when you collect them.)
3. Be careful of collisions with `+` (Wall) and `o` (Snake Tail).

## Screenshot

![gameplay screenshot](https://drive.google.com/uc?export=view&id=14GZXgYSnjalMFyCOzefM_AsK1R3xyPnH)


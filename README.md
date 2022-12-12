<h1 align="center">
	📖 SO_LONG
</h1>

<p align="center">
	<b><i>And thanks for all the fish!</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/zstenger93/so_long?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/zstenger93/so_long?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/zstenger93/so_long?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/zstenger93/so_long?color=green" />
</p>

---

## 💡 About the project

> _This project is a very small 2D game._

	Its purpose is to make you work with textures, sprites,
	and some other very basic gameplay elements. 

> _You will try to survive our greatest enemy, the NORM._

	You will be our 42 astronaut,
	trying to drinking enough coffe,
	to be able to debug your code,
	and avoid our beloved cat,
	Norminette!

For more 42 projects [**visit my repository**](https://github.com/zstenger93).

My approach was kinda different because I haven't used structs before so I haven't used much of them,
but enough to learn the concept for future projects.
Mainly used them for images, textures and the movement counter.
I have 2 hooks, one for the player and one for the enemies because together my player was a bit laggy.
Spaghetti ala zstenger, hope you're hungry.
Feel free to ask me anything on slack.

---

## 🛠️ How to play and make different maps:

## Keys for qwerty keyboard ⌥ :

[FORWARD] = W

[GO_LEFT] = A

[GO_RIGHT] = D

[BACKWARD] = S

[EXIT] = ESC

## How to build a map 🗺 :

'0' = WALKING_PATH

'1' = WALL

'P' = PLAYER

'E' = EXIT

'C' = COFFEE

'F' = NORMINETTE (only with bonus)

'F' = NORMINETTE2 (only with bonus)

'B' = NORMINETTE3 (only with bonus)

> _This project is a very small 2D game._

	1111111111111
	10010000000C1
	1000011111001
	1P0011E000001
	1111111111111

> _This project is a very small 2D game._

	1111111111111111111111111111111111
	1E0000000000B00C00000C0000N0000001
	1010010100100000101001000000010101
	1010010010101010001001000000010101
	1P0000000C00C000F000000000000000C1
	1111111111111111111111111111111111

---

## 🛠️ Usage

### Requirements

> <i>The project must comply with the following rules:
>
> - You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
> - You have to turn in a Makefile which will compile your source files. It must not relink.
> - Your program has to take as parameter a map description file ending with the .ber extension.
The game:
> - The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
> - The W, A, S, and D keys must be used to move the main character.
> - The player should be able to move in these 4 directions: up, down, left, right.
> - The player should not be able to move into walls.
> - At every move, the current number of movements must be displayed in the shell.
> - You have to use a 2D view (top-down or profile).
> - The game doesn’t have to be real time.
> - Although the given examples show a dolphin theme, you can create the world you want.
Graphic managment:
> - Your program has to display the image in a window.
> - The management of your window must remain smooth (changing to another window, minimizing, and so forth).
> - Pressing ESC must close the window and quit the program in a clean way.
> - Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
> - The use of the images of the MiniLibX is mandatory.
The map:
> - The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
> - The map must be rectangular.
> - The map must be closed/surrounded by walls. If it’s not, the program must return an error.
> - You have to check if there’s a valid path in the map.
> - You must be able to parse any kind of map, as long as it respects the above rules.
> - Another example of a minimal .ber map:
> - If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.
Bonus:
> - Make the player lose when they touch an enemy patrol.
> - Add some sprite animation.
> - Display the movement count directly on screen instead of writing it in the shell.</i>

---

### Instructions

My Makefile is configured for Mac use. To be able to use it on Linux it NEEDS to be modified.

When you run make or one of my other options (you cansee in Testing):
	-it will download MLX42 and libft from github, since they are submodules
	-compile MLX42 and libft
	-if there is no GLFW downloads GLFW
	-unzip and moves GLFW to the right directory
	-compiles so_long
	-in case the right make option, runs the program right after

---

## 📋 Testing

Multiple options:
	-You can just run make to compile everything.
	-Or run commands from make t to make t5 or make tb to make tb5 to run the test
		right after compiling without any extra command.
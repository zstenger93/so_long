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

> _FYI:_

	The game has some improvements compared to the gifs.
	I was too lazy to make new ones..:]
	Main character and enemy moves fixed as well as the images.
	Also the walking path has been animated.
	Background music and voice reactions have been added.
	More map checks and additional map.

---

![run](https://media2.giphy.com/media/8pkvLD2wAxDyyTA1po/giphy.gif?cid=790b7611610cc8aac29440459a2e89288b9c3f4e3ae0d6c5&rid=giphy.gif&ct=g)

---

## 💡 About the project

> _This project is a very small 2D game._

	Its purpose is to make you work with textures, sprites,
	and some other very basic gameplay elements
	and you will hit your head into the table if you haven't
	used structs before.

> _You will try to survive our greatest enemy, the NORM._

	You will be our 42 astronaut,
	trying to drink enough coffe,
	to be able to debug your code,
	and avoid our beloved cat,
	Norminette!

For more 42 projects [**visit my repository**](https://github.com/zstenger93).

![42](https://media1.giphy.com/media/gbnrIActVDTKljeCrd/giphy.gif?cid=790b7611d7da81e2b3f02e67f5c235528dd1c3d96f69bcdd&rid=giphy.gif&ct=g)

My approach was kinda different because I haven't used structs before so I barely used them,
but enough to learn the concept for future projects.
Mainly used them for images, textures and the movement counter.
I have 2 hooks, one for the player and one for the enemies because together my player was a bit laggy.
Feel free to ask me anything on slack.
`Spaghetti ala zstenger, hope you're hungry.`

### 1st step:
> - Checking for the input with `ft_wrong_input` when you try to run the program and if you included a `.ber` map as well
### 2nd step:
> - Checking the error cases on the provided map with `ft_error_types`.
> - Inside using `ft_map_validator` function where
> - We check for walls with `ft_have_walls`
> - With `ft_map_have_all_elements` for the map elements and if they are correct or not
> - And finally `ft_map_validpath` to check if the exit and al the collectables are reachable.
### 3rd step:
> - Open a window which is the size of the map with `ft_open_mapsize_window`.
### 4th step:
> - Creating the new imgages we will use with `ft_make_new_images`.
### 5th step:
> - Creating the actual map we will see in the window with `ft_make_map`.
> - Putting the loaded images with `ft_put_loaded_image` where we tell it each should be 32*32 pixel
> - Inside of `ft_put_loaded_image` we call each image loading function depending on the map element
> - If it's `P`, `0`, `C`, `E` elements, I load the `walking_path` as well 
> - In case of bonus I do the same with the enemies
> - Also at the image loads I check `ft_player_location` where I compare a few things like:
> - Wall, I guess you don't want to fall off of the map!
> - If it's pickable, removes it from the map
> - In bonus if it's norminette? -> death
> - Other than that, for exit and activate it if there is nothing else to collect.
### 6th step:
> - Opening the `mlx_loop_hook` for the game.
> - It is open until the window is closed, this is where the game is playing.
> - Here in the `ft_player_hook` we have the `ft_move_and count` and `ft_player_movement` functions.
> - First is obvious, calculates the movement and prints it to the terminal.
> - The latter controls the movement and the exit/coffee animations.
### 7th step:
> - Using the `mlx_loop` function to deal with rendering and refreshing.
### 8th step:
> - Calling `mlx_terminate` function when closing the window to clean up everything.
### Sprite animation:
> - I handle it in my `load` and `movement` functions in a very simplistic way.
> - Everything moves when the player does.
> - From the enemies 2 moves the oposite and one in the same direction, each has different speed.

---

## 🛠️ How to play and make different maps:

### Keys for qwerty keyboard ⌥ :

`FORWARD` = `W`

`LEFT` = `A`

`RIGHT` = `D`

`BACKWARD` = `S`

`EXIT` = `ESC`

### How to build a map 🗺 :

`0` = `WALKING_PATH`

`1` = `WALL`

`P` = `PLAYER`

`E` = `EXIT`

`C` = `COFFEE`

`F` = `NORMINETTE` (only with bonus)

`N` = `NORMINETTE2` (only with bonus)

`B` = `NORMINETTE3` (only with bonus)

### Mandatory map example:
```
					1111111111111
					10010000000C1
					1000011111001
					1P0011E000001
					1111111111111
```
### Bonus part example:
```
				1111111111111111111111111111111111
				1E0000000000B00C00000C0000N0000001
				1010010100100000101001000000010101
				1010010010101010001001000000010101
				1P0000000C00C000F000000000000000C1
				1111111111111111111111111111111111
```
---

## 🛠️ Usage

### Requirements:

> <i>The project must comply with the following rules:
>
> - You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
> - You have to turn in a Makefile which will compile your source files. It must not relink.
> - Your program has to take as parameter a map description file ending with the .ber extension.</i>
### The game:
> - <i>The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
> - The W, A, S, and D keys must be used to move the main character.
> - The player should be able to move in these 4 directions: up, down, left, right.
> - The player should not be able to move into walls.
> - At every move, the current number of movements must be displayed in the shell.
> - You have to use a 2D view (top-down or profile).
> - The game doesn’t have to be real time.
> - Although the given examples show a dolphin theme, you can create the world you want.</i>
### Graphic managment:
> - <i>Your program has to display the image in a window.
> - The management of your window must remain smooth (changing to another window, minimizing, and so forth).
> - Pressing ESC must close the window and quit the program in a clean way.
> - Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
> - The use of the images of the MiniLibX is mandatory.</i>
### The map:
> - <i>The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
> - The map must be rectangular.
> - The map must be closed/surrounded by walls. If it’s not, the program must return an error.
> - You have to check if there’s a valid path in the map.
> - You must be able to parse any kind of map, as long as it respects the above rules.
> - Another example of a minimal .ber map:
> - If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.</i>
### Bonus:
> - <i>Make the player lose when they touch an enemy patrol.
> - Add some sprite animation.
> - Display the movement count directly on screen instead of writing it in the shell.</i>

---

## Instructions

> - `My Makefile` is configured for Mac use. To be able to use it `on Linux` it `NEEDS to be modified`.

### When you run make or one of my other options (you can see in Testing):
> - it will download `MLX42` and `libft` from github, since they are `submodules`
> - compile `MLX42` and `libft`
> - if there is no `GLFW` downloads `GLFW`
> - unzip and moves `GLFW` to the right directory
> - compiles `so_long`
> - in case the right make option, runs the program right after

![run](https://media4.giphy.com/media/pZISzrkzYha50THHc5/giphy.gif?cid=790b76116c6215c75f7acbe135c7dc1093b7458ce935622c&rid=giphy.gif&ct=g)

---

## 📋 Testing

### Multiple options:
> - You can just run `make` to compile the mandatory part eg:
```shell
$ make
```
> - Run `make bonus` to compile the bonus version eg:
```shell
$ make bonus
```
> - Or run commands from `make t` to `make t5` or `make tb` to `make tb5` to run the test right after compiling without any extra command eg:
```shell
$ make tb2
```

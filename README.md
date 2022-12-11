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

For more information about 42 projects [**visit my repository**](https://github.com/zstenger93).

My approach was kinda different because I haven't used structs before so I haven't used much of them,
but enough to learn the concept for future projects.
Mainly used them for images, textures and the movement counter.
I have 2 hooks, one for the player and one for the enemies because together my player was a bit laggy.



## 🛠️ Usage

### Requirements

My Makefile is configured for Mac use. To be able to use it on Linux it NEEDS to be modified.

### Instructions

When you run make or one of my other options (you cansee in Testing):
	-it will download MLX42 and libft from github, since they are submodules
	-compile MLX42 and libft
	-if there is no GLFW downloads GLFW
	-unzip and moves GLFW to the right directory
	-compiles so_long
	-in case the right make option, runs the program right after

## 📋 Testing

Multiple options:
	-You can just run make to compile everything.
	-Or run commands from make t to make t5 or make tb to make tb5 to run the test
		right after compiling without any extra command.
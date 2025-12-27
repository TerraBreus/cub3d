<div align="center">

  ###### The inspiration of this program was taken by [this video from javidx9](https://www.youtube.com/watch?v=NbSee-XM7WA&t=1505s&pp=ygUIRERBIGluIEM%3D).

  ## ./geometry_game
A very simple and finnicky program to help visualize some geometry in a topdown 2D map. The aim of this program was to write (and understand) the DDA-algorithm needed for the cub3d engine. 

## Controls

The idea is quite simple. You start in an empty 20x20 matrix with two cursors. The red cursor is controlled by the wasd-keys and the green cursor is controlled by the mouse position. When (left)clicking on an empty square, a wall is created (blue tile). Clicking again on a wall removes it. 

The magic happens when you press the `l` key on your keyboard (I chose `l` as I drew a `line`). The program will then shoot a ray from the green cursor to the red cursor (it overshoots but I couldn't be bothered to fix that as that won't be needed in the final product). If a wall is encountered within that path, the ray stops and a line from the green cursor to the wall is shown.

Below an example of a ray encountering a wall:

<img width="298" height="260" alt="image" src="https://github.com/user-attachments/assets/25aec287-1099-44e5-98cf-971a7841dd53" />

**NB: The game does not close properly cause I'm lazy. You must sig_interrupt by pressing `ctrl+c` in the terminal that is running the program...**
## How to run?
lol if anyone is interested you can try it out yourself:
</div>

```
git clone https://github.com/TerraBreus/cub3d.git cub3d_terra
cd ./cub3d_terra/geometry_game
make
./geometry_game
```

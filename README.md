## 42_cursus_cub3d

**Description**
This is my first raycasting project, part of my journey as a Cadet at 42 São Paulo.
Inspired by Wolfenstein3D, which was the first FPS game ever, the goal was to make a dynamic view inside a maze, using C language and minilibx. This projects runs on Linux.

**Method**
I have chosen to use *Digital Differential Analysis* (DDA) algorithm for all the calculation needed to be able to draw the projeted walls.

## How to access

Clone this repository:

``git clone git@github.com:clacrisostomo/42_cursus_cub3d.git``

Then:

``cd 42_cursus_cub3d``

## Mandatory part

For the mandatory part of this project I had to:
- render projected walls
- apply a different texture to the walls according to where they are facing (North, South, East, West)
- render one type of sprite
- set two different colours for the floor and ceiling
- be able to move around the map using **W, A, S, D** keys and rotate ("look") the view with the **left** and **right** keys.
- be able to close the window using ESC or clicking on the x button.
- be able to take a screen shot (.bmp file) of the entering view with ```--save```
- if the resolution set in the map is greater than the screen's, the program should resize the window to the user's screen size.

The maps (.cub files) can be configured like the example below, where:

```
R 1920 1080 - resolution
NO ./path_to_the_north_texture - North facing wall texture
SO ./path_to_the_south_texture - South facing wall texture
WE ./path_to_the_west_texture - West facing wall texture
EA ./path_to_the_east_texture - East facing wall texture

S ./path_to_the_sprite_texture - sprite texture

F 220,100,0 - floor colour (RGB values)
C 225,30,0 - ceiling colour (RGB values)

1111111111111111111111111
1000000000110000000000001
1011000001110000002000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

```make```

```./cub3D maps/mandatory/1_map.cub```

```./cub3D maps/mandatory/2_map.cub```

![1_map]<img src="https://github.com/clacrisostomo/pics/blob/master/1_map.png">

![2_map]<img src="https://github.com/clacrisostomo/pics/blob/master/2_map.png">

---

## Bonus part

Try not to lose lives or go to the limbo, find the star to win.

**Bonus features**

- wall collisions
- object collisions
- extra items in the maze
- HUD (minimap)
- floor texture
- doors that can open and close
- secret doors
- items that take and give lives
- run
- limbo mode

```make bonus```

```./cub3D maps/bonus/bonus.cub```

![Door]<img src="https://github.com/clacrisostomo/pics/blob/master/door.png">

![Life]<img src="https://github.com/clacrisostomo/pics/blob/master/life.png">

![Limbo]<img src="https://github.com/clacrisostomo/pics/blob/master/limbo.png">

![Win]<img src="https://github.com/clacrisostomo/pics/blob/master/win.png">
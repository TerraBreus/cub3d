# Notes from the subject.
- Only parameter for the program is the map (in a .cub file)
- Name of program: ./cub3D
- Display different wall textures depending on which side the wall is facing (North, South, East & West)
- Floor and Ceiling must be set to two different colors
- left and right arror should rotate the player
- W A S D should move the player
- Pressing Esc or the Cross should close the program

## Map parsing
- Only 6 possible characters (Technically 3)
    - `0` for empty space
    - `1` for wall
    - `N/S/E/W` for player to identify okayer start position and orientation.
- There must be one (and only one) player/orientation in the map
- The map must be completely closed by walls, otherwise the game should not start
- the maps may be seperated by at least one (white)space
- the lines of the map may be seperated by more than one empty line
```
1 1 1 1 1



1 0 0 0 1

1 0 N 0 1


1 1 1 1 1
```
- Maps don't need to be squares necessarily
- 

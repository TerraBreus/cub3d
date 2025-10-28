# Notes from the subject.
- Only parameter for the program is the mapfile (in a .cub file) which contains some info and the map.
- Name of program: ./cub3D
- If any wrong mapfile or misconfiguration is given, program must give a promt error message (on STDERRNO)
## Textures and mapfile
- Display different wall textures depending on which side the wall is facing (North, South, East & West)
- Floor and Ceiling must be set to two different colors
- The textures are set in the mapfile before the map
- The textures and colors can be given in any order but only in front of the map
- Textures for every side must be given

Identifiers are `NO`, `SO`, `WE` and `EA`

- Floor and ceiling are set by:

`F 345,349,9` or `C 0,0,0` and must conform to the 256 [0,255] color RGB
- There can be a numerous amount (or none) of whitespace/newlines between the texture/colors


## Key binds
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
- Maps don't need to be squares necessarily
- Maps can have spaces!

## Some errors I can already see
- Too many/little texture files
- Incorrect texture files; files don't exist or are not readable
- all textures are on a single line or are seperated by multiple (both need to be parsable)
- No colors given (or too many!)
- Incorrect identifiers (`NORTH`)
- Overflow in colors (or this is what you want)
- Incorrect file extension
- More than one player character (or none)
- Incorrect characters (`Z` or `O`)
- Textures are in different order (which should still have the program run)
- Maps will have many (and inconsistent) spaces
- Newlines in the map
- Map is not closed
- Element does not begin with its identifier
- Extra irrelevant information is given in the map that the parser does not understand
- whitespace in the colors
- element can have whitespace between identifier and path name (or none?)

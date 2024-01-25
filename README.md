# Spaceships
A simple 2D space-shooter written in C++ using SFML.

## How to try it out (Linux)

- clone the repo: Run `git clone https://github.com/LouisAlexanderSkowronek/Spaceships.git` or download as zip and then extract it.
- create and change into build directory: run `cd Spaceships/ && mkdir build && cd build/`
- Build the game: Make sure that you have GNU C++ compiler, cmake, and SFML libraries installed within your system, then run `cmake .. && make`
- Run the program using `./Spaceships`


## Copyright limitations

Due to copyright reasons, the public version of the game has currently neither a window icon nor music or any sound effects. Instead, there are placeholder files (empty files with the same name) in the assets directory and the header file include/Spaceships/copyright_limitations.hpp. To play the full version of the game, place two slashes (//) right before the `#define COPYRIGHT_LIMITATIONS` statement after replacing the placeholder files with an actual icon and music, and after rebuilding the game (see above in "How to try it out" under "Build the game") you can enjoy the full game.

## Contact

You can email me if you have any questions, bugs or improvement ideas.
Email: louis.alexander.skowronek@gmail.com

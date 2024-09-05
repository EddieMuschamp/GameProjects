# Game Projects
 Game projects made in C++ using the SDL (Simple DirectMedia Layer) library for rendering.

Games include:
## Conway's Game of Life
An implementation of Conway's Game of Life, a cellular automaton devised by mathematician John Conway. The game is played on a grid where cells live, die, or evolve based on their neighboring cells.

The project includes:

* Initialization of SDL for window and rendering. </b>
* Setup of the grid with initial live cells. </b>
* Main loop for updating the grid and rendering each frame. </b>
* A window displaying the grid. The grid will update according to the rules of the Game of Life. Initial cells are set up manually in the code, but you can modify these to explore different patterns.

To run, ensure that SDL2 is installed and properly linked with the project and run the .sln file in Visual Studio.

## 2D Object Fall Game
An implementation of a 2D object fall game. The game features a player character that can move left and right, interact with pickups, and avoid enemies.

The project includes:

Initialization of SDL for window and rendering. </b>
* Setup of player character, including movement and sprite animations. </b>
* Implementation of pickups with cooldowns and score multipliers.
* Creation of enemies with collision detection and score impact.
* Main game loop for handling input, updating game state, and rendering.

To run, ensure SDL2 and SDL2_image are installed and properly linked with the project. Run the .sln file in Visual Studio.

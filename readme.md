# Snake Game Implementation in C

## Overview
This project is a simple console-based Snake game written in C. It uses linked lists for managing the snake's body, a dynamic 2D array for the game map, and basic keyboard input handling for movement. The snake moves around the map, growing in length as it eats food, and the game ends if the snake collides with the walls or itself.

## Features
- **Dynamic Memory Allocation:** The game dynamically allocates memory for the snake, map, and queue structures.
- **Queue-Based Snake Body:** The snake's body is implemented using a queue, where new positions are enqueued at the head, and the tail is dequeued when the snake moves.
- **Simple Collision Detection:** The game checks for collisions with the walls or the snake's own body.
- **Keyboard Input Handling:** Uses `_kbhit()` and `_getch()` for real-time user input.
- **Basic Console Graphics:** The game board is represented using characters (`.` for empty spaces, `@` for walls, numbers for objects like the snake and food).

## File Structure
### `main.c`
This is the entry point of the program. It initializes the game, handles user input, updates the snake's position, and checks for collisions.

### `queue.h` and `queue.c`
Defines and implements a queue structure to manage the snake's body.

- **`enqueue(QNode** head, QNode** tail, Position position)`** - Adds a new segment to the snake.
- **`dequeue(QNode** head, QNode** tail, Position* position)`** - Removes the tail segment.
- **`is_empty(QNode* head)`** - Checks if the queue is empty.
- **`peek(QNode* head, Position* position)`** - Returns the front element of the queue without removing it.
- **`print_queue(QNode* head)`** - Prints the queue (for debugging).
- **`free_queue(QNode* head)`** - Frees allocated memory for the queue.

### `map.h` and `map.c`
Defines and implements the game map.

- **`create_map(int rows, int cols)`** - Dynamically allocates memory for the map.
- **`map_initialization(Map* map, char empty, char wall)`** - Initializes the map with walls and empty spaces.
- **`set_value(Map* map, int x, int y, char value)`** - Sets a specific value in the map.
- **`get_value(Map* map, int x, int y)`** - Retrieves the value from a specific position.
- **`print_map(const Map* map)`** - Prints the map to the console.

### `snake.h` and `snake.c`
Defines and implements snake-related functions.

- **`create_snake(int start_x, int start_y)`** - Initializes a new snake.
- **`eat(Snake* snake, Map* map, char direction)`** - Handles food consumption and growth.
- **`move_snake(Snake* snake, char direction, Map* map, char value)`** - Moves the snake in the specified direction and handles collisions.
- **`is_collision(Position position, Map* map)`** - Checks if the snake collides with walls or itself.
- **`delete_snake(Snake* snake)`** - Frees memory allocated for the snake.

## How to Compile and Run
1. Ensure you have a C compiler installed (e.g., `gcc` for Linux/Mac or MinGW for Windows).
2. Open a terminal and navigate to the project directory.
3. Compile the program using:
   ```sh
   gcc main.c queue.c map.c snake.c -o snake_game
   ```
4. Run the executable:
   ```sh
   ./snake_game
   ```

## Controls
- `W` - Move Up
- `S` - Move Down
- `A` - Move Left
- `D` - Move Right

## Future Improvements
- Add more game mechanics (e.g., increasing speed over time, more food types).
- Implement a better rendering system for smoother animations.
- Add a user interface with a score counter.
- Improve memory management and error handling.

This project demonstrates fundamental C programming concepts, including dynamic memory allocation, linked lists, and file separation for modular programming. Enjoy coding and playing the game!


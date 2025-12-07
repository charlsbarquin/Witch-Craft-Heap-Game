# Witch Craft Heap Game

## Overview

**Witch Craft Heap Game** (also known as **Witchcraft's Defense**) is an educational console-based game implemented in C++. It combines elements of strategy, number selection, and basic data structures to create an engaging experience where players defend against monstrous foes using magical potions made from odd and even numbers.

The game is designed as part of a Data Structures and Algorithm course, emphasizing concepts like vector manipulation, random number generation, input validation, sorting algorithms, and strategic decision-making.

## Features

- **Random Number Generation**: Generates 15 unique odd numbers and 15 unique even numbers between 1 and 50, creating a pool of 30 mystical numbers.
- **Strategic Selection**: Players choose 3 odd numbers (offensive potions) and 3 even numbers (defensive potions) from the available list.
- **Sorting and Display**: Selected numbers are sorted in ascending order and displayed as part of the "Heap Sorting Ritual."
- **Combat System**: Player's total power (sum of selected numbers) is compared against a randomly generated monster power level (120-250).
- **Lives System**: Players have 3 attempts (lives) to succeed. Lose a life if power is insufficient; win if power exceeds monster's; tie if equal.
- **Input Validation**: Robust validation ensures only valid odd/even numbers from the list are accepted, with helpful error messages.
- **Educational Focus**: Demonstrates data structure usage (vectors), algorithms (sorting, searching), and problem-solving.
- **Unicode Support**: Includes emojis and special characters for an immersive console experience (Windows-specific).

## How to Play

1. **Game Start**: The game welcomes you with a magical theme and generates 30 unique numbers (15 odd, 15 even) between 1 and 50.
2. **Number Selection**:
   - Select 3 odd numbers for offensive spells.
   - Select 3 even numbers for defensive spells.
   - Numbers must be from the summoned list and meet parity requirements.
3. **Sorting Ritual**: The selected numbers are sorted and displayed.
4. **Combat**: A monster with a random power level (120-250) appears. Your total power is the sum of your selected numbers.
5. **Outcome**:
   - If your power > monster's power: Victory!
   - If equal: Average player (tie).
   - If less: Lose a life and try again (up to 3 attempts).
6. **Game End**: Win, lose all lives, or achieve a tie.

### Example Gameplay

```
🧙‍♀️ Welcome to the Witch Craft Heap Game!   🧙‍♀️

30 mystical numbers have been summoned:
[generated list of 30 numbers]

You must pick 3 odd (offensive) and 3 even (defensive) numbers.

Enter an odd number: 5
✔️ 5 added to the offensive spells.
... (repeat for selections)

🔮 The Witch Craft Heap Sorting Ritual Begins 🔮
Sorted Offensive (Odd) Numbers: 1 5 11
Sorted Defensive (Even) Numbers: 2 4 12

A monstrous foe with a power level of 146 appears!

Your combined magic power is 35.

💔 Your power is insufficient! You lose 1 life.
```

## Requirements

- **Operating System**: Windows (due to `SetConsoleOutputCP` for Unicode support).
- **Compiler**: C++ compiler supporting C++11 or later (e.g., g++, Visual Studio).
- **Libraries**: Standard C++ libraries (included in most compilers):
  - `<iostream>`
  - `<vector>`
  - `<algorithm>`
  - `<cstdlib>`
  - `<ctime>`
  - `<windows.h>` (Windows-specific)

## Installation

1. **Clone or Download**: Ensure the source code file `HEAPS ACT.cpp` is in your project directory.
2. **Compile**: Use a C++ compiler to build the executable.
   - Example with g++: `g++ HEAPS ACT.cpp -o heap_game.exe`
   - Example with Visual Studio: Create a new console project and add the source file.
3. **Run**: Execute the compiled program in a Windows console.

## Usage

1. Run the executable: `./heap_game.exe` (or `heap_game.exe` on Windows).
2. Follow the on-screen prompts to select numbers.
3. Play through up to 3 attempts.
4. The game ends with a win, loss, or tie message.

### Command Line Example

```
g++ "Heaps Activity Source Code/HEAPS ACT.cpp" -o heap_game.exe
./heap_game.exe
```

## Code Structure

The game is implemented in a single C++ file (`HEAPS ACT.cpp`) with the following key components:

- **Global Functions**:
  - `displayVector<T>(const vector<T>& vec)`: Template function to display vector elements.
  - `isInList(int num, const vector<int>& list)`: Checks if a number exists in a vector.
  - `removeFromList(int num, vector<int>& list)`: Removes a number from a vector if present.
  - `clearSelectedNumbers(...)`: Removes selected numbers from the main list and clears selections.

- **Main Function**:
  - Initializes random seed and console encoding.
  - Generates odd and even number vectors.
  - Combines into a main numbers vector.
  - Handles user input loops for odd and even selections with validation.
  - Sorts and displays selections.
  - Generates monster power and compares with player power.
  - Manages game loop with lives system.

- **Data Structures Used**:
  - `vector<int>`: For dynamic arrays of numbers (odd, even, selected, main list).
  - Algorithms: `find`, `erase`, `sort` from `<algorithm>`.

## Learning Objectives

As part of the Data Structures and Algorithm course, this game teaches:

- **Vector Manipulation**: Using C++ vectors for dynamic storage and operations.
- **Random Number Generation**: Seeding and generating unique random numbers.
- **Input Validation**: Ensuring user inputs meet specific criteria (range, parity, existence).
- **Sorting Algorithms**: Applying ascending sort to selected numbers.
- **Strategic Thinking**: Maximizing limited resources (number selections) to achieve goals.
- **Decision Making**: Choosing optimal odd/even combinations for higher power sums.
- **Problem-Solving**: Handling edge cases in game logic and user interactions.

## Author

- **Name**: Charls Emil C. Barquin
- **Course**: Bachelor of Science in Information System
- **Institution**: Bicol University Polangui, Polangui, Albay

## License

This project is for educational purposes as part of a university assignment. No specific license is applied; use at your own discretion.

## Contributing

This is an educational project. For improvements or modifications, ensure changes align with the learning objectives and maintain code accuracy.

## Acknowledgments

- Inspired by heap data structures and magical themes.
- Developed to demonstrate practical application of DSA concepts in game development.

# Tides of Manila

*Tides of Manila* is a turn-based strategy game built using C, created as a Machine Project for CCPROG1.

## Installation

### Prerequisites

- Ensure you have [MinGW-w64](https://sourceforge.net/projects/mingw-w64/) installed.

### Build from source

**1. Clone the repository**

```bash
git clone https://github.com/angele34/tides-of-manila.git
```

**2. Navigate to the project directory**

```bash
cd tides-of-manila
cd src
```

**3. Compile the program with gcc -Wall -std=c99**

```bash
gcc -Wall -std=c99 main.c menu.c welcome.c input.c end_of_game.c location.c generate_price.c check_turns.c clear_screen.c -o tides-of-manila.exe
```

**4. Run the .exe file**

```bash
./tides-of-manila
```

## Gameplay

- Start the game by entering:
  - Player code
  - Initial capital
  - Target profit (at least 20% of your initial capital)
- The game begins in the port of Manila.
- Navigate through Tondo, Sapa, and Pandakan ports.
- Buy items for low prices and sell for profit in other ports.
- Win the game once your target profit is reached.

## Keyboard Shortcuts

| Screen            | Key   | Description            |
| ----------------- | ----- | ---------------------- |
| **Main Screen**    | 1     | Buy                    |
|                   | 2     | Sell                   |
|                   | 3     | Go to another port     |
|                   | Q     | Exit the game          |
| **Purchase/Sell Screen**| 1     | Coconut                |
|                   | 2     | Rice                   |
|                   | 3     | Silk                   |
|                   | 4     | Gun                    |
|                   | X     | Return to Main Screen  |

## Acknowledgements

1. Code used for generating random numbers for market prices
    
    https://www.geeksforgeeks.org/generating-random-number-range-c/

2. ANSI escape sequences chart referred to for coloring texts and clearing the screen

    https://gist.github.com/ConnerWill/d4b6c776b509add763e17f9f113fd25b

3. Website used for converting a text to ASCII Art

    https://www.asciiart.eu/text-to-ascii-art
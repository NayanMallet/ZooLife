# Zoo Simulator

Welcome to ZooLife, a turn-based zoo management simulator written in C++!

## Overview

In ZooLife, you are the manager of a zoo, responsible for buying and selling animals, habitats, and food, as well as managing the well-being of your animals. Visitors generate revenue for your zoo, but be careful not to overcrowd your enclosures, as this could lead to sickness and death among your animals. The game spans 10 years, so manage your finances wisely and run your zoo to the best of your ability!

## How to Play

### Getting Started

1. Clone this repository to your local machine.
2. Compile the `main.cpp` file using a C++ compiler.

### Gameplay

- Upon starting the game, you will be prompted to enter a name for your zoo.
- You have 10 years to manage your zoo.
- Each turn represents one month in the game.

### Actions

1. **View Your Zoo**: See the current status of your zoo, including animals, habitats, and available budget.
2. **Visit the Vendor**: Buy or sell animals, habitats, or food from the vendor.
3. **Advance to Next Month**: Progress the game to the next month.

### Animal Management

- You can view specific enclosures and animals within them.
- Perform actions such as renaming animals, treating illnesses, or moving animals to different enclosures.

### Vendor Interaction

- Buy or sell animals, habitats, or food from the vendor.
- Manage your budget carefully to make profitable transactions.

### End of Game

- The game ends after 10 years.
- Your goal is to maximize revenue and maintain a healthy, thriving zoo.

## Implementation Details

### Animals

- Implemented various types of animals including tigers, eagles, chickens, and roosters.
- Each animal has specific feeding requirements, breeding behaviors, and lifespan considerations.

### Habitats

- Created different habitats suitable for various animal types.
- Each habitat has a capacity limit to prevent overcrowding.

### Food

- Implemented a variety of food types with corresponding prices.
- Animals must be fed regularly to prevent starvation.

### Financial Management

- Manage your zoo's budget to make strategic decisions.
- Generate revenue from visitor ticket sales.

### User Interaction

- Interact with the game through a command-line interface.
- Make choices to buy, sell, or manage zoo assets.

### Game Progression

- The game progresses through 10 simulated years.
- Each turn represents one month of in-game time.

## Dependencies

- C++ Compiler

## How to Execute the Project

1. Compile the `main.cpp` file using a C++ compiler.
2. Run the compiled executable file.

## Credits

ZooLife was developed by [Nayan](https://github.com/NayanMallet) and [Pablo](https://github.com/NotGrafik) in [2022].

Feel free to contribute to the project by submitting bug fixes or additional features!

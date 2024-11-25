# Rover Run
Project of Data Structures and Algorithmics 2, S3

## Introduction
In 2028, a solar storm hit the MARC (Mars Rover Cartograph) rover. Its programming, guidance, and movement systems were affected. The only way to repair MARC is to bring it back to a base station.

The aim of this project is to use the tools and techniques learned during the semester to program MARC to navigate autonomously and safely return to the base station.

## Usage
First, to ensure the expected output in the console, check your Cion configurations for the following:
Navigate to Run -> Edit Configurations, and activate Emulate terminal in the output console.

Then, you can run the program. A menu will appear:

Start Mission: **Press 1** to begin.
Exit: **Press 2** to quit the program.
### Steps to Use
After selecting 1 to start, you will see an introduction. To continue, press any key.
You will then be prompted to choose between multiple maps by typing their corresponding number:
**Press 1** for the **first** map.
**Press 2** for the **second** map.
**Press N** for the **Nth** map.
If you make an invalid choice, the program will automatically select Map 1.
Once the map is selected, you can observe MARC navigating to find the base station.

## Features
Terrain Handling: MARC can navigate different types of terrain, such as:

- Plain
- Erg
- Reg
- Mud
- Crevasse
- Ice

Dynamic Pathfinding: MARC adjusts its path based on terrain constraints.

## Authors
Killian KOULOURATH, Lélia GHEZALI, Noah JEANDEAU, Idrissa BARRY

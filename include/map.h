//
// Created by flasque on 19/10/2024.
//

#ifndef UNTITLED1_MAP_H
#define UNTITLED1_MAP_H

// Color codes for terrains
#define RESET "\033[0m"
#define GREEN "\033[32m"  // Plain
#define YELLOW "\033[33m" // Erg
#define CYAN "\033[36m"   // Reg
#define RED "\033[31m"    // Crevasse
#define BLUE "\033[34m"   // Slope
#define MAGENTA "\033[35m" // MARC's position
#define WHITE "\033[37m" // ICE
#define ORANGE "\033[38;5;214m" // MUD




#define COST_UNDEF 65535



/**
 * @brief Enum for the possible soils of the map
 */
typedef enum e_soil
{
    BASE_STATION,
    PLAIN,
    ERG,
    REG,
    CREVASSE,
    MUD,
    ICE,
    SLOPE
} t_soil;

/**
 * @brief Array of costs for the soils
 */
static const int _soil_cost[7] = {0, 1, 2, 4, 10000, 5, 6};

/**
 * @brief Structure for the map

 */
typedef struct s_map
{
    t_soil  **soils;
    int     **costs;
    int     x_max;
    int     y_max;
} t_map;

/**
 * @brief Function to initialise the map from a file
 * @param filename : the name of the file
 * @return the map
 */
t_map createMapFromFile(char *);

/**
 * @brief Function to create a standard training map (11x11 with only plains and base station in the middle)
 * @param none
 * @return a standard map
 */
t_map createTrainingMap();

/**
 * @brief display the map with characters.
 * @param map : the map to display
 */
void displayMap(t_map);

/**
 * @brief Display the map with colors for each kind of soil and a red color for MARC's position.
 * @param map : the map to display
 * @param locMarc : MARC's position
 * return the colored map
 */
void displayColoredMap(t_map);

/**
 * @brief Display the legend for the map.
 * @return the legend
 */
void displayLegend();

#endif //UNTITLED1_MAP_H

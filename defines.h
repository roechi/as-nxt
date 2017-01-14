#include "current_state.h"

// +++ ROBOT CONSTANTS ***
#define RIGHT OUT_C
#define LEFT OUT_B
#define BOTH_DRIVE OUT_BC
#define NECK OUT_A
#define GROUND_DETECTOR_L IN_2
#define GROUND_DETECTOR_R IN_3
#define TOUCH IN_1
#define ULTRA IN_4
#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1
#define DIRECTION_BACK 0
#define NECK_ROT_SPEED 50
#define SPEED 75
#define MAX_US_DISTANCE 25
#define LIGHT_THRESHOLD 15
#define WHEEL_RADIUS 2.8
#define WHEEL_DISTANCE 14
#define TILE_SIZE 30

// +++ NAVIGATION +++
// Dimensions
const char MAP_DIMENSION = 3;
const char MAP_DIM_X = 3;
const char MAP_DIM_Y = 3;
// Directions
const char NORTH = 0;
const char EAST = 1;
const char SOUTH = 2;
const char WEST = 3;
// Field-specifier
const char FREE = 'F';
const char OCCUPIED = 'C';
const char TARGET = 'T';
const char EXPLORED = 'E';
const char BORDER = 'B';

// +++ VARIABLES +++
// field
char MOVE_SPACE[MAP_DIM_X][MAP_DIM_Y];
// current state of explorer
Current_State current_state;
// normal ground color
int NORMAL_GROUND_COLOR = 0;


// +++ A-Star Algorithm +++
const unsigned char LIST_SIZE = 255;

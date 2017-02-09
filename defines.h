
// +++ ROBOT CONSTANTS ***
#define RIGHT OUT_C
#define LEFT OUT_B
#define BOTH_DRIVE OUT_BC
#define NECK OUT_A
#define GROUND_DETECTOR_LIGHT IN_2
#define GROUND_DETECTOR_RGB IN_3
#define TOUCH_SENSOR IN_1
#define ULTRA IN_4
#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1
#define DIRECTION_BACK 0
#define NECK_ROT_SPEED 50
#define SPEED 60
#define ROTATION_SPEED 30
#define MAX_US_DISTANCE 25
#define LIGHT_THRESHOLD 15
#define WHEEL_RADIUS 1.5 //2.8
#define WHEEL_DISTANCE 11 //13.8
#define TILE_SIZE 30
#define MOVE_FORWARD 1
#define MOVE_BACKWARD -1

// +++ NAVIGATION +++
// Dimensions
const char MAP_DIM_X = 7;
const char MAP_DIM_Y = 7;
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
// normal ground color
int NORMAL_GROUND_COLOR = 0;


// +++ A-Star Algorithm +++
const unsigned char LIST_SIZE = 255;

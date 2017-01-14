// Initialization
void init_MoveSpace();
void init_current_state(char x, char y, char direction);
void init_ground_detectors();

void doStuff();
void see();

void update_current_position(char direction);
void reorient();
char get_field_in_direction(char direction);
bool can_move(short direction);
void move()
char find_new_direction();
bool isOccupied();



// Movement
void rotateOnSpot(char direction, float wheelDistance, float wheelRadius, int angle);
void moveForward(char speed);
void moveBackward(char speed);
void backOff();
void stopMove();
void rotate90(char direction);
void turnRight();
void turnLeft();
void turnAround();
void drive(int distance, int direction);


bool checkGround();





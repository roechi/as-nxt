void initMoveSpace();
void doStuff(char &environment[][]);
void see(char &environment[][], short &directions[], short length);
bool isOccupied();
short backOff();
short findNewDirection();
void rotateOnSpot(int direction, float wheelDistance, float wheelRadius, int angle);
void moveForward(long speed);
void backForward(long speed);
void stopMove();
void rotate90(int direction);
void turnRight();
void turnLeft();
void turnAround();
bool checkGround();
void initGroundDetectors();
void drive(int distance, int direction);
void move();

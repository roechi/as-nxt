
/*
 *  Rotates the robot on his position.
 *  direction = 1: right
 *  direction = -1: left
 */
void rotateOnSpot(char direction, float wheelDistance, float wheelRadius, int angle)
{
    int wheelRotationAngle = angle * ((wheelDistance / 2) / wheelRadius);

    RotateMotorEx(BOTH_DRIVE, SPEED, wheelRotationAngle, (-direction) * 100, true, true);
}


void moveForward(char speed) {
//void RotateMotorEx(byte outputs,char pwr, long angle, char turnpct, bool sync, bool stop)   
    RotateMotorEx(BOTH_DRIVE, speed, 360, 100, true, true);
    //OnFwd(BOTH_DRIVE, speed);
}

void moveBackward(char speed) {
    moveForward(-1 * speed);
}

void backOff() {
    moveBackward(SPEED);
}

void stopMove() {
    OnFwd(BOTH_DRIVE, 0);
}

void rotate90(char direction)
{   
    rotateOnSpot(direction, WHEEL_DISTANCE, WHEEL_RADIUS, 90);
    // RotateMotorEx(BOTH_DRIVE, SPEED, 225, -direction * 100, true, true);
}

void turnRight() {
    rotateOnSpot(DIRECTION_RIGHT, WHEEL_DISTANCE, WHEEL_RADIUS, 90);
}

void turnLeft() {
    rotateOnSpot(DIRECTION_LEFT, WHEEL_DISTANCE, WHEEL_RADIUS, 90);
}

void turnAround() {
    turnRight();
    turnRight();
}

void drive(int distance, int direction)
{
    int wheelRotationAngle = 2 * PI * WHEEL_RADIUS * distance * direction;

    RotateMotorEx(BOTH_DRIVE, SPEED, wheelRotationAngle, 0, true, true);
}


void drive_away()
{
    //Drive
    OnFwd(BOTH_DRIVE, 100);
    //Stop if touchsensor calls collision
    while(!Sensor(TOUCH_SENSOR));
    //Stop driving
    stopMove();
}
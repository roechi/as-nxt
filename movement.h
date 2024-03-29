#include "current_state.h"
// current state of robot
Current_State current_state;

// Movement
void rotateOnSpot(char direction, float wheelDistance, float wheelRadius, int angle);
//should not be used anymore!!!
void moveForward(char speed);
//should not be used anymore!!!
void moveBackward(char speed);
//should not be used anymore!!!
void backOff();
void stopMove();
void rotate90(char direction);
void turnRight();
void turnLeft();
void turnAround();
void drive(int distance, int direction);

//void move_to_target(Position current, Position target);
void turn_to_direction(char current_direction, char target_direction);

void update_current_position(char direction);


/*
 *  Rotates the robot on his position.
 *  direction = 1: right
 *  direction = -1: left
 */
void rotateOnSpot(char direction, float wheelDistance, float wheelRadius, int angle)
{
    int wheelRotationAngle = angle * ((wheelDistance / 2) / wheelRadius);
    
    RotateMotorEx(BOTH_DRIVE, ROTATION_SPEED, wheelRotationAngle, (-direction) * 100, true, true);
}

//should not be used anymore!!!
void moveForward(char speed) {
//void RotateMotorEx(byte outputs,char pwr, long angle, char turnpct, bool sync, bool stop)   
    RotateMotorEx(BOTH_DRIVE, speed, 360, 100, true, true);
    //OnFwd(BOTH_DRIVE, speed);
}
//should not be used anymore!!!
void moveBackward(char speed) {
    moveForward(-1 * speed);
}
//should not be used anymore!!!
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
    int wheelRotationAngle = distance * 360 / (2 * WHEEL_RADIUS * PI);

    RotateMotorEx(BOTH_DRIVE, SPEED, wheelRotationAngle * direction, 0, true, true);
}


void drive_away()
{
    turn_to_direction(current_state.direction, NORTH);
    //Drive
    OnFwd(BOTH_DRIVE, 100);
    //Stop if touchsensor calls collision
    while(!Sensor(TOUCH_SENSOR));
    //Stop driving
    stopMove();
}


/*
 * turn to target direction. updated current_state
 */
void turn_to_direction(char current_direction, char target_direction)
{
    char offset = (target_direction - current_direction);
	
	// Gilt wenn offset == 3 und macht offset = -1 => wechselt die Drehrichtung (auch fuer -3 => 1)
	if (abs(offset) > 2)
		offset = -(offset % 2);

    if(offset < 0)
    {
        for(char i = 0; i < abs(offset); ++i)
        {
            turnLeft();
        }
    }
    else if (offset > 0)
    {
        for(char i = 0; i < abs(offset); ++i)
        {
            turnRight();
        } 
    }
    
    current_state.direction = target_direction;
}

//current and target a in neighborhood
/*
 * move robot to target. current and target should be
 * neighbours! updates current state
 */
void move_to_target(Position current, Position target)
{
	//Wait(1000);
	
    //Position p = get_top();	
	
	//char d = current_state.direction;
	
	// switch (d)
	// {
	// 	case NORTH:
	// 		TextOut(0, LCD_LINE2, "Norden");
	// 		break;
	// 	case EAST:
	// 		TextOut(0, LCD_LINE2, "Osten");
	// 		break;
	// 	case SOUTH:
	// 		TextOut(0, LCD_LINE2, "Sueden");
	// 		break;
	// 	case WEST:
	// 		TextOut(0, LCD_LINE2, "Westen");
	// 		break;
	// 	default:
	// 		TextOut(0, LCD_LINE2, "KP");
	// }
	
    if(current.x > target.x)
    {
        turn_to_direction(current_state.direction, WEST);
		// TextOut(0, LCD_LINE3, "Nach Westen");
    }
    else if (current.x < target.x)
    {
        turn_to_direction(current_state.direction, EAST);
		// TextOut(0, LCD_LINE3, "Nach Osten");
    }
    else if (current.y > target.y)
    {
        turn_to_direction(current_state.direction, SOUTH);
		// TextOut(0, LCD_LINE3, "Nach Sueden");
    }
    else if(current.y < target.y)
    {
        turn_to_direction(current_state.direction, NORTH);
		// TextOut(0, LCD_LINE3, "Nach Norden");
    }
    else
    {
        //janz blöd throw Exception;
        //current and target are equal
        return;
    }

	// Wait(2000);
	
    drive(TILE_SIZE, MOVE_FORWARD);
    current_state.pos_x = target.x;
    current_state.pos_y = target.y;

}


/*
 *  Updates the current Position (int current_state) 
 *  with the given direction.
 */
void update_current_position(char direction) {
    switch (direction) {
        case NORTH: current_state.pos_y += 1;
                    break;
        case EAST:  current_state.pos_x += 1;
                    break;
        case SOUTH: current_state.pos_y += -1;
                    break;
        case WEST:  current_state.pos_x += -1;
                    break;
        default: ;
    }
}

int MAP_LEFT_OFFSET = 50;
int MAP_LEFT_BOTTOM = 35;

struct Map {
       int x_dim;
       int y_dim;
       char data[][];
};

void drawMapOuterBorder(char MOVE_SPACE[][], char MAP_DIM_X, char MAP_DIM_Y) {
    for (int i = 0; i < MAP_DIM_X + 2; i++) {
        PointOut(i + MAP_LEFT_OFFSET - 1, 0 + MAP_LEFT_BOTTOM - 1);
        PointOut(i + MAP_LEFT_OFFSET - 1, MAP_DIM_X + 1 + MAP_LEFT_BOTTOM - 1);
        PointOut(MAP_LEFT_OFFSET - 1, i + MAP_LEFT_BOTTOM - 1);
        PointOut(MAP_LEFT_OFFSET - 1 + MAP_DIM_X+ 1, i + MAP_LEFT_BOTTOM - 1);
    }
}

void drawMap(char MOVE_SPACE[][], char MAP_DIM_X, char MAP_DIM_Y) {
     drawMapOuterBorder(MOVE_SPACE, MAP_DIM_X, MAP_DIM_Y);
     for (int i = 0; i < MAP_DIM_X; i++) {
         for (int j = 0; j < MAP_DIM_Y; j++) {
            if (MOVE_SPACE[i][j] == 'E') {
                PointOut(i + MAP_LEFT_OFFSET, j + MAP_LEFT_BOTTOM);
            }
         }
     }

}


int MAP_LEFT_OFFSET = 50;
int MAP_LEFT_BOTTOM = 35;

struct Map {
       int x_dim;
       int y_dim;
       char data[][];
};

void drawMapOuterBorder(Map map) {
    for (int i = 0; i < map.x_dim + 2; i++) {
        PointOut(i + MAP_LEFT_OFFSET - 1, 0 + MAP_LEFT_BOTTOM - 1);
        PointOut(i + MAP_LEFT_OFFSET - 1, map.x_dim + 1 + MAP_LEFT_BOTTOM - 1);
        PointOut(MAP_LEFT_OFFSET - 1, i + MAP_LEFT_BOTTOM - 1);
        PointOut(MAP_LEFT_OFFSET - 1 + map.x_dim + 1, i + MAP_LEFT_BOTTOM - 1);
    }
}

void drawMap(Map map) {
     drawMapOuterBorder(map);
     for (int i = 0; i < map.x_dim; i++) {
         for (int j = 0; j < map.y_dim; j++) {
            if (map.data[i][j]) {
                PointOut(i + MAP_LEFT_OFFSET, j + MAP_LEFT_BOTTOM);
            }
         }
     }
}

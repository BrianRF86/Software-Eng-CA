#include "raylib.h"
#include "raymath.h"
//Ball https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c

class Ball {
public: 
float x, y;
int speed_x, speed_y;
int radius;

void Draw () {

    DrawCircle(x, y, radius, YELLOW);

    }


//ball movement

void Update() {
x += speed_x;
y += speed_y;


// Border collision

 if (y + radius >= GetScreenHeight() || y - radius <=0)
    {
            speed_y *= -1;
    }
 if (x + radius >= GetScreenWidth() || x - radius <=0)
    {
            speed_x *= -1;
    }
}
};
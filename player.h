//Based on https://github.com/AndrewHamel111/raylib-Asteroids/blob/main/src/player.h

#include "raymath.h"
#include "raylib.h"

// Trying struct instead of class https://www.youtube.com/watch?v=eW05rq1Nz2I&t=5s
// updating struct as per Lecturer's example: https://github.com/naoisecollins/2023MSc-SoftwareEngineering1-Class-Workspace/commit/747a80cc5ce8c3abccc23f8f5545c3e809b61d46

class player {

public:

float x,y;
int width, height;
float speed;
//// For zoom function from Raylib example  Copyright (c) 2022-2023 Jeffery Myers (@JeffM2501) https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_mouse_zoom.c
float zoom;
Texture2D texture;
Vector2 position;
//adding vectors for offset and target to see if fixes errors.
Vector2 offset;
Vector2 target;   

player () {

height = GetScreenHeight ()/ 4;
width = GetScreenWidth ()/ 4;

}

void Limitmovement(){
if(y <= 0)
    {
        y = 0;
    }

if (y + height >= GetScreenHeight()) 
    {
        y = GetScreenHeight() - height;
    }

if(x <=0)
{
    x = 0;
}

if(x + width >= GetScreenWidth())
{
    x = GetScreenWidth() - width;
}

} 

void Loadtexture(player);
 
 };
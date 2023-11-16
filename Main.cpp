#include "raylib.h"

// Added raymath to resolve vector errors from https://github.com/raysan5/raylib/blob/master/src/raymath.h

#include "raymath.h"

//trying to set screen width & height to avoid zooming out of map.

const int screenWidth = 832;
const int screenHeight = 430;

//objects

// Trying struct instead of class https://www.youtube.com/watch?v=eW05rq1Nz2I&t=5s

struct player{

protected:

float x,y;
float width, height;

//// For zoom function from Raylib example  Copyright (c) 2022-2023 Jeffery Myers (@JeffM2501) https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_mouse_zoom.c
float zoom;

//Setting player details
player.width = screenWidth/4;
player.height = screenHeight/4;
player.x = screenWidth/2;
player.y = screenHeight/2;

// Preventing the player from leaving the screen. 

void Limitmovement(){
if(y <= 0)
    {
        y = 0;
    }

if (y + height >= GetScreenHeight()) 
    {
        y = GetScreenHeight - height;
    }

if(x <=0)
{
    x = 0;
}

if(x + width >= GetScreenWidth())
{
    x = GetScreenWidth - width;
}

}
    

void Loadtexture(player);

};

int main() {
    // Determine the Game Window Width and Height
    // changed screen size to match widescreen laptops
    const int screenWidth = 832;
    const int screenHeight = 430;

//Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Saving President Chump");

//Background Texture
Texture2D background = LoadTexture("resources/Street.png");



    // Setting the Frames Per Second
    SetTargetFPS(60);






    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        //Updates

     // Player movement & Map navigation on mouse click right --- moving back to INT section


if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        { Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/player.zoom);
        player.target = Vector2Add(player.target, delta);
        }
        // Zoom function on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {



Camera2D player = { 0 }; 
player.zoom = 1.0f;

     //World point is at mouse position.

            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), player);
           

            //Set the offset to where the mouse is
            player.offset = GetMousePosition();

         // Set the target to match, so that the camera maps the world space point 
        // under the cursor to the screen space point under the cursor at any zoom
            player.target = mouseWorldPos;
    

         
       
        // Zoom increase
        const float zoomIncrease = 0.125f;

        player.zoom += (wheel*zoomIncrease);
        if(player.zoom < zoomIncrease) player.zoom = zoomIncrease;

        }
        
        // Setup Canvas
        BeginDrawing();
        
        // Here goes all the Game Logic
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
        // initiaing 2D mode
         BeginMode2D(player);

    
  
        Loadtexture(background,0.0f, 2.0f, WHITE);
        

       

        // Ending 2D mode
        EndMode2D();

        // teardown Canvas
        EndDrawing();
    }
        //De-Initialization
//Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c
UnloadTexture(background); 
UnloadTexture(player);

    CloseWindow();
    return 0;
}


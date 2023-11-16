#include "raylib.h"

// Added raymath to resolve vector errors from https://github.com/raysan5/raylib/blob/master/src/raymath.h

#include "raymath.h"



//objects

// Preventing the player from leaving the screen. 

class player{

protected:

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


    float x,y;
    float width, height;
    

void Loadtexture(Player);

// Player movement & Map navigation on mouse click right 


if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        { Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/player.zoom);
        player.target = Vector2Add(player.target, delta);
        }
        // Zoom function on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {

// For zoom function from Raylib example  Copyright (c) 2022-2023 Jeffery Myers (@JeffM2501) https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_mouse_zoom.c

Camera2D player = { 0 }; 
Player.zoom = 1.0f;

     //World point is at mouse position.

            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), Player);
           

            //Set the offset to where the mouse is
            Player.offset = GetMousePosition();

         // Set the target to match, so that the camera maps the world space point 
        // under the cursor to the screen space point under the cursor at any zoom
            Player.target = mouseWorldPos;
    

};

player player;

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

     
         
       
        // Zoom increase
        const float zoomIncrease = 0.125f;

        Player.zoom += (wheel*zoomIncrease);
        if(Player.zoom < zoomIncrease) Player.zoom = zoomIncrease;

        }
        
        // Setup Canvas
        BeginDrawing();
        
        // Here goes all the Game Logic
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
        // initiaing 2D mode
         BeginMode2D(Player);

    
  
        Loadtexture(background,0.0f, 2.0f, WHITE);
        

       

        // Ending 2D mode
        EndMode2D();

        // teardown Canvas
        EndDrawing();
    }
        //De-Initialization
//Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c
UnloadTexture(background); 
UnloadTexture(Player);

    CloseWindow();
    return 0;
}

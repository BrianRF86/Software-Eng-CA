#include "raylib.h"

// Added raymath to resolve vector errors from https://github.com/raysan5/raylib/blob/master/src/raymath.h

#include "raymath.h"
#include "player.h"

//objects

// Trying struct instead of class https://www.youtube.com/watch?v=eW05rq1Nz2I&t=5s
// updating struct as per Lecturer's example: https://github.com/naoisecollins/2023MSc-SoftwareEngineering1-Class-Workspace/commit/747a80cc5ce8c3abccc23f8f5545c3e809b61d46
struct player{

float x,y;
float width, height;
float speed;
//// For zoom function from Raylib example  Copyright (c) 2022-2023 Jeffery Myers (@JeffM2501) https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_mouse_zoom.c
float zoom;
Texture2D texture;
Vector2 position;

//adding vectors for offset and target to see if fixes errors.
Vector2 offset;
Vector2 target;


//defining 

// Preventing the player from leaving the screen. 


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

//https://github.com/naoisecollins/2023MSc-SoftwareEngineering1-Class-Workspace/commit/747a80cc5ce8c3abccc23f8f5545c3e809b61d46

player.position = GetMousePosition ();
player.texture = LoadTexture("resources/crosshair.png");
player.speed = 4.0f;

    // Setting the Frames Per Second
    SetTargetFPS(60);






    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        //Updates

     // Player movement & Map navigation on mouse click right --- moving back to INT section https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_mouse_zoom.c


if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        { Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/player.zoom);
        player.target = Vector2Add(player.target, delta);
        }
        // Zoom function on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {



Camera2D Camera = { 0 }; 
player.zoom = 1.0f;

     //World point is at mouse position.

            Camera2D mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), Camera);
           

            //Set the offset to where the mouse is
            Camera.offset = GetMousePosition();

         // Set the target to match, so that the camera maps the world space point 
        // under the cursor to the screen space point under the cursor at any zoom
            Camera.target = mouseWorldPos;
    

         
       
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

    
  
        LoadTexture(background,0.0f, 2.0f, WHITE);
        

       

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


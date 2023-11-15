#include "raylib.h"

// Added raymath to resolve vector errors from https://github.com/raysan5/raylib/blob/master/src/raymath.h

#include "raymath.h"

//Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c

//objects

struct crosshair{

Texture2D texture;
Rectangle circ;
Vector2 position;

};

int main() {
    // Determine the Game Window Width and Height
    // changed screen size to match widescreen laptops
    const int screenWidth = 1280;
    const int screenHeight = 720;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Saving President Chump");

//Background Texture
Texture2D background = LoadTexture("resources/Street.png");

//Crosshair texture
Texture2D crosshair = LoadTexture("resources/crosshair.png");


float scrollingBackground = 0.0f;

// Camera class - For zoom function from Raylib example  Copyright (c) 2022-2023 Jeffery Myers (@JeffM2501) https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_mouse_zoom.c

Camera2D camera = { 0 }; 
camera.zoom = 1.0f;

    // Setting the Frames Per Second
    SetTargetFPS(60);


    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        //Updates
        //Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c
        scrollingBackground -= 0.1f;

        crosshair cursor = (crosshair){
            .texture = crosshair,
            .position = GetMousePosition (),
            .circ = {0.0f, 0.0f, 64.0f, 64.f},
        };

        //Map navigation on mouse click right 
        if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        { Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/camera.zoom);
        camera.target = Vector2Add(camera.target, delta);
        }
        // Zoom function on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {
            
            //World point is at mouse position.
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

            //Set the offset to where the mouse is
            camera.offset = GetMousePosition();

         // Set the target to match, so that the camera maps the world space point 
        // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos;

        // Zoom increase
        const float zoomIncrease = 0.125f;

        camera.zoom += (wheel*zoomIncrease);
        if(camera.zoom < zoomIncrease) camera.zoom = zoomIncrease;

        }
        
        // Setup Canvas
        BeginDrawing();
        
        // Here goes all the Game Logic
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
        // initiaing 2D mode
         BeginMode2D(camera);

    
        //Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c
        DrawTextureEx(background, { scrollingBackground, 20 }, 0.0f, 2.0f, WHITE);
        DrawTextureEx(background, { background.width*2 + scrollingBackground, 20 }, 0.0f, 2.0f, WHITE);

        DrawTexture(crosshair,0.0f,2.0f,WHITE);

        // Ending 2D mode
        EndMode2D();

        // teardown Canvas
        EndDrawing();
    }
        //De-Initialization
//Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c
UnloadTexture(background); 
UnloadTexture(crosshair);

    CloseWindow();
    return 0;
}

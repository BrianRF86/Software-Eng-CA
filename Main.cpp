#include "raylib.h"

int main() {
    // Determine the Game Window Width and Height
    // changed screen size to match widescreen laptops
    const int screenWidth = 1280;
    const int screenHeight = 720;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Saving President Chump");

// Camera class - For zoom function from Raylib example  Copyright (c) 2022-2023 Jeffery Myers (@JeffM2501)

Camera2D camera = { 0 };
camera.zoom = 1.0f;

    // Setting the Frames Per Second
    SetTargetFPS(60);


    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        //Updates

        //Map navigation on mouse click right 
        if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        { Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/camera.zoom);
        camera.target = Vector2Add(camera.target, delta);
        }


       

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);

        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

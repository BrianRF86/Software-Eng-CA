#include "raylib.h"

// Added raymath to resolve vector errors from https://github.com/raysan5/raylib/blob/master/src/raymath.h

#include "raymath.h"
#include "player.h"

//objects

//defining 

// Preventing the player from leaving the screen. 


int main() {
    // Determine the Game Window Width and Height
    // changed screen size to match widescreen laptops
    const int screenWidth = 832;
    const int screenHeight = 430;


//Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Saving President Chump");

         // Player movement & Map navigation on mouse click right --- moving back to INT section https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_mouse_zoom.c

//Background Texture
Texture2D background = LoadTexture("resources/Street.png");

    // Setting the Frames Per Second
    SetTargetFPS(60);


    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        //Updates
         // Translate based on mouse right click
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f/camera.zoom);

            camera.target = Vector2Add(camera.target, delta);
        }

        // Zoom based on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
            
            // Set the offset to where the mouse is
            camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos;

            // Zoom increment
            const float zoomIncrement = 0.125f;

            camera.zoom += (wheel*zoomIncrement);
            if (camera.zoom < zoomIncrement) camera.zoom = zoomIncrement;
        }
        
        // Setup Canvas
        BeginDrawing();
        
        // Here goes all the Game Logic
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
   
    

    
  
        DrawTexture(background,0.0f, 2.0f, WHITE);
        DrawTexture(player,0.0f, 2.0f,WHITE);

       

        // Ending 2D mode
        EndMode2D();

        // teardown Canvas
        EndDrawing();
    }
        //De-Initialization
//Fixing texture https://github.com/raysan5/raylib/blob/master/examples/textures/textures_background_scrolling.c
UnloadTexture(background); 


    CloseWindow();
    return 0;
}


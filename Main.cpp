#include "raylib.h"

//including raymath to solve Vector2ADD error
#include "raymath.h"


#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1


int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 800;
    const int screenHeight = 450;

    //Defining Player speed

    
    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Scarfy's dodgeball survival");

//https://www.youtube.com/watch?v=j0C4ox1gFxk&list=PLORJX3OiHbbMs9AFM5bzpNUychJm1raub

Texture2D playertex = LoadTexture("resources/scarfy3.png");
unsigned numFrames = 6;
	int frameWidth = playertex.width / numFrames;
	Rectangle frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)playertex.height };
	Vector2 playerPosition = {screenWidth / 2.0f, screenHeight / 2.0f};
    Vector2 playerVelocity = {0.0f,0.0f};
	
   int currentFrame = 0;   
   int framesCounter = 0;
   int framesSpeed = 8;

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {


            //updates

        //fix animation speed https://github.com/raysan5/raylib/blob/master/examples/textures/textures_sprite_anim.c

  framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 5) currentFrame = 0;

            frameRec.x = (float)currentFrame*(float)playertex.width/6;
        
        // Stop walking animation if no button is pressed

        } else if(!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT) &&
        !IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) &&
        !IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
        
        framesCounter = 0;
        }

        // Player movement

        if (IsKeyDown(KEY_RIGHT) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
			playerVelocity.x = framesSpeed;
			if(frameRec.width < 0) {
				frameRec.width = -frameRec.width;
			}
        } else if (IsKeyDown(KEY_LEFT) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
			playerVelocity.x = -framesSpeed;
			if(frameRec.width > 0) {
				frameRec.width = -frameRec.width;
			}
		} else {
			playerVelocity.x = 0;
		}

        
		bool playerMoving = playerVelocity.x != 0.0f || playerVelocity.y != 0.0f;

        playerPosition = Vector2Add(playerPosition, playerVelocity);




        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);

       
        DrawTextureRec(playertex, frameRec, playerPosition,WHITE);
        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

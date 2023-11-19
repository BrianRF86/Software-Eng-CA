#include "raylib.h"

//including raymath to solve Vector2ADD error
#include "raymath.h"


int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 800;
    const int screenHeight = 450;

    //Defining Player speed

    const int playerSpeed = 6;
    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Scarfy's dodgeball survival");

//https://www.youtube.com/watch?v=j0C4ox1gFxk&list=PLORJX3OiHbbMs9AFM5bzpNUychJm1raub

Texture2D playertex = LoadTexture("resources/scarfy3.png");
unsigned numFrames = 6;
	int frameWidth = playertex.width / numFrames;
	Rectangle frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)playertex.height };
	Vector2 playerPosition = {screenWidth / 2.0f, screenHeight / 2.0f};
    Vector2 playerVelocity = {0.0f,0.0f};
	
	unsigned frameDelay = 5;
	unsigned frameDelayCounter = 0;
	unsigned frameIndex = 0;

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {


            //updates
        // Player movement

        if (IsKeyDown(KEY_RIGHT) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
			playerVelocity.x = playerSpeed;
			if(frameRec.width < 0) {
				frameRec.width = -frameRec.width;
			}
        } else if (IsKeyDown(KEY_LEFT) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
			playerVelocity.x = -playerSpeed;
			if(frameRec.width > 0) {
				frameRec.width = -frameRec.width;
			}
		} else {
			playerVelocity.x = 0;
		}
		bool playerMoving = playerVelocity.x != 0.0f || playerVelocity.y != 0.0f;

        playerPosition = Vector2Add(playerPosition, playerVelocity);

          	++frameDelayCounter;
		if(frameDelayCounter > frameDelay) {
			frameDelayCounter = 0;
        }
    
    // fix player moving animation
    if(playerMoving) {
				++frameIndex;
				frameIndex %= numFrames;
				frameRec.x = (float) frameWidth * frameIndex;
			}

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

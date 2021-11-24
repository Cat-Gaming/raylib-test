#include "raylib.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Game");

    Image icon = LoadImage("icon.png");
    SetWindowIcon(icon);

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 1.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 70.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FIRST_PERSON);

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        // Update
        UpdateCamera(&camera);

        if (IsKeyDown('Z')) camera.target = cubePosition; //(Vector3){ 0.0f, 0.0f, 0.0f };
        if (IsKeyPressed('X')) camera.up.y = -camera.up.y;
        if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
        {
            cubePosition.y += GetMouseWheelMove();
        } else if (IsMouseButtonUp(MOUSE_BUTTON_MIDDLE))
        {
            camera.fovy += GetMouseWheelMove()*5;
        }
        

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);

        DrawGrid(20, 1.0f);

        EndMode3D();

        char fovNum[16] = "";

        sprintf(fovNum, "%g", camera.fovy);
        DrawText("FOV:", 10, 30, 20, BLACK);
        DrawText(fovNum, 65, 30, 20, BLACK);
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
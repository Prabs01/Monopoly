#include"raylib.h"
#include<iostream>
#include "game.h"

using namespace std;


int main(void){
    const int OriginalScreenWidth = 1000;
    const int OriginalscreenHeight= 800;


    InitWindow(OriginalScreenWidth, OriginalscreenHeight, "Monopoly");

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Game game;

    if(game.Init() == false){
        cout<<"error occured";
    }

    RenderTexture2D renderTexture = LoadRenderTexture(OriginalScreenWidth, OriginalscreenHeight);

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        if (screenWidth != renderTexture.texture.width || screenHeight != renderTexture.texture.height) {
            UnloadRenderTexture(renderTexture);
            renderTexture = LoadRenderTexture(screenWidth, screenHeight);
        }
        game.handleInput();
        game.handleEvent();

        BeginDrawing();
            ClearBackground(LIGHTGRAY);


            game.Draw();

        EndDrawing();

    }
     
    CloseWindow();
    return 0;
}
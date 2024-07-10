#include"raylib.h"
#include<string>


const int screenWidth = 1000;
const int screenHeight= 600;
    
class Screen{
    protected:
        int screenWidth;
        int screenHeight;
        string name;
    public:
        Screen(int scWidth=1000, int scHeight=600, string screenName){
            screenHeight=scHeight;
            screenWidth=scWidth;
            name = screenName;
        }

        void Init(){
            InitWindow(screenWidth, screenHeight, name);
        }
        
        

};


int main(void){
   
    

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("hello world",190,200,10,RED);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
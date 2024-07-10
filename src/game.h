#pragma once
#include "board.h"
#include "raylib.h"
#include"player.h"
#include <string>


const Vector2 dicePos = {775,50};
extern int framesCnt;
extern int diceSeparation;

const int ANIMATION_FRAMES = 50;

class Dice{
    private:
        int d1_number;
        int d2_number;
        int number;
        Texture2D diceFaces[6];
    
    public:
        Dice();
        bool load();
        void Draw();
        void roll();
        int getNum();
        void setNum(int);
        bool isRolling;
};

class Game
{
    public:
        Game();
        ~Game();
        bool Init();
        void Draw();
        void handleInput();
        void handleEvent();

    private:
        Board board;
        Player players[4];
        Dice dice;
        int activePlayer;

};

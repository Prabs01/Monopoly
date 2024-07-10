#include "board.h"

Board::Board(){
    playingRectangle = {25, 25, 750, 750};
    boardPos = {playingRectangle.x+25,playingRectangle.y+25};
}

bool Board::load(){
    Image img= LoadImage("../resources/Monopoly_board.png");

    boardTex = LoadTextureFromImage(img);
    UnloadImage(img);

    if (boardTex.id == 0)
    {
        return false;
    }
    return true;
}

void Board::draw(){
    DrawRectangleRec(playingRectangle, GRAY);
    DrawTextureEx(boardTex, boardPos, 0.0f, 1.0f, WHITE);
}


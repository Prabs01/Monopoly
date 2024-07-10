#pragma once

#include "raylib.h"

#include "properties.h"


class Board
{
    private:
        

    public:
        Board();
        void draw();
        bool load();
        Rectangle playingRectangle;
        Vector2 boardPos;
        Texture2D boardTex;
};

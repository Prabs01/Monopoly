#include"raylib.h"
#include "properties.h"

class  Player
{
    private:
        int position;
        int type;

    public:
        Player();
        void addPos(int);
        void Draw();
        bool load();
        int getPos();
        void setPos(int);
        void setType(int);
        void move(int);
        Texture2D texture;
        bool isMoving;
};
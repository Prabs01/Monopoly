#include "player.h"

int moveCount = 0;

Player::Player(){
    position = 0;
    type = 0;
    isMoving = false;
}

bool Player::load(){
    Image image;
    if(type == 0){
        image = LoadImage("../resources/car.png");
        ImageResize(&image, 30, 30);
    }

    else if(type == 1){
        image = LoadImage("../resources/man.png");
        ImageResize(&image, 30, 30);
    }

    else if(type == 2){
        image = LoadImage("../resources/duck.png");
        ImageResize(&image, 30, 30);
    }

    else if(type == 3){
        image = LoadImage("../resources/tv.png");
        ImageResize(&image, 30, 30);
    }
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    if(texture.id ==0){
        return false;
    }
    return true;
}

void Player::addPos(int dieNum){
    position+=dieNum;
    if(position >=40){
        position%=40;
    }
}

void Player::Draw(){
    Vector2 pos = {lands[position].x,lands[position].y};
    DrawTextureEx(texture, pos, 0.0f, 1.0f, WHITE);
}

int Player::getPos(){
    return position;
}

void Player::setPos(int pos){
    position = pos;
}

void Player::setType(int type_){
    type = type_;
 }

void Player::move(int pos){
    moveCount++;
    if(moveCount % 5 == 0){
        addPos(1);
    }
    if(moveCount == 5*pos){
        isMoving = false;
        moveCount = 0;
    }
}
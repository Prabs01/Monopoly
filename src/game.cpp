#include"game.h"

int framesCnt=0;
int diceSeparation=100;

Game::Game(){
    board = Board();
    for(int i=0;i<4;i++){
        players[i]=Player();
        players[i].setType(i);
    }
    dice = Dice();
    activePlayer=0;
}

Game::~Game(){
    UnloadTexture(board.boardTex);
}

bool Game::Init(){
    if(board.load() == false){
        return false;
    }
    for(int i=0;i<4;i++){
        if(players[i].load() == false){
        return false;
    }
    }
    
    if(dice.load()==false){
        return false;
    }
    return true;
}

void Game::Draw(){
    board.draw();
    players[activePlayer].Draw();
    dice.Draw();
}

void Game::handleInput(){


    if(IsKeyPressed(KEY_SPACE)){
        players[activePlayer].isMoving=true;
    }
    
    //heandling dice roll
    else if(IsKeyPressed(KEY_R)){
        dice.isRolling=true;
    }
    

}

void Game::handleEvent(){
    if(dice.isRolling){
        dice.roll();
    }

    else if(players[activePlayer].isMoving){
        players[activePlayer].move(dice.getNum());
    }
    
}

Dice::Dice(){
    d1_number = 1;
    d2_number = 1;
    isRolling = false;
}

bool Dice::load(){
    diceFaces[0]=LoadTexture("../resources/dice1.png");
    diceFaces[1]=LoadTexture("../resources/dice2.png");
    diceFaces[2]=LoadTexture("../resources/dice3.png");
    diceFaces[3]=LoadTexture("../resources/dice4.png");
    diceFaces[4]=LoadTexture("../resources/dice5.png");
    diceFaces[5]=LoadTexture("../resources/dice6.png");
    for(int i =0 ;i<6;i++){
        if (diceFaces[i].id == 0)
        {
            return false;
        }
    }
    
    return true;
}

void Dice::Draw(){
    DrawTexture(diceFaces[(d1_number-1)],dicePos.x,dicePos.y,WHITE);
    DrawTexture(diceFaces[(d2_number-1)],dicePos.x+diceSeparation,dicePos.y,WHITE);
}

void Dice::roll(){
    framesCnt++;
        if (framesCnt % 5 == 0) // Change face every 5 frames
        {
            d1_number = GetRandomValue(1,6);
            d2_number = GetRandomValue(1,6);
        }

        if (framesCnt > ANIMATION_FRAMES)
        {
            isRolling = false;
            framesCnt = 0;
            d1_number = GetRandomValue(1, 6);
            d2_number = GetRandomValue(1, 6);
        }
}

void Dice::setNum(int num){
    number = num;
}

int Dice::getNum(){
    return (d1_number+d2_number);
}
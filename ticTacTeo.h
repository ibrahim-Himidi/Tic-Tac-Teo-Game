#ifndef TICTACTEO_H
#define TICTACTEO_H

using namespace std;

class Board{
    private:
     char list[3][3];
    public:
    void displayBoard();
    void updateBoard(char symbol , int index1 , int index2);
    void resetBoard();
    bool isEmpty(int index1 , int index2);
    char getList(int index1, int index2);
};


class  Computer {
private:
    Board* ptrBoard;
    char computerSym;
    char playerSym;
public:

    void setPtr(Board* address);
    char getsymbol();
    void setSymbol(char sym);
    void play();
    bool attack();
    bool defend();
};


class Player {
private:
    char playerSym;
    int index1 , index2;
public:
    void setSymbol(Computer* obj);
    char getSymbol();
    void play(Board* obj);
    void  translateId(int id);
};



class Game {
private:
    Board board;
    Computer computer;
    Player player;
    bool turn; // => true = palyer turn
public:
    Game();
    void startGame();
    char checkWin(Board* obje);
    bool checkDraw();
};



#endif

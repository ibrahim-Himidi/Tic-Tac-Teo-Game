#include "ticTacTeo.h"
#include <iostream>
#include <random>

using namespace std;

void Board::resetBoard() {
    char counter = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            list[i][j] = counter++;
    }
}

void Board::displayBoard() {
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cout << "  " << list[i][j];
            if(j < 2)
                cout << " |";
        }
        cout << endl;
        if(i < 2)
            cout << "----|----|----"<< endl;
    }

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}

bool Board::isEmpty(int index1 , int index2) {
    if(list[index1][index2] != 'X' && list[index1][index2] != 'O')
        return true;
    else
        return false;
};

void Board::updateBoard(char symbol, int index1, int index2) {
    list[index1][index2] = symbol;
}

char Board::getList(int index1, int index2) {
    return list[index1][index2];
}






void Player::setSymbol(Computer* obj) {
    while (true) {
        cout << "to Select your a player pleas enter  (X or O) : ";
        cin >> playerSym;
        cin.ignore();
        if (playerSym == 'x' || playerSym == 'X') {
            playerSym = 'X';
            obj->setSymbol(playerSym);
            break;
        }else if(playerSym == 'o' || playerSym == 'O') {
            playerSym = 'O';
            obj->setSymbol(playerSym);
            break;
        }
        cout << "Invalid input. Please try again!! \n\n";
    }
}

char Player::getSymbol() {
    return playerSym;
}

void Player::translateId(int id) {
    if(id == 1) {
        index1 = 0;
        index2 = 0;
    }
    else if(id == 2){
        index1 = 0;
        index2 = 1;
    }
    else if(id == 3){
        index1 = 0;
        index2 = 2;
    }
    else if(id == 4){
        index1 = 1;
        index2 = 0;
    }
    else if(id == 5){
        index1 = 1;
        index2 = 1;
    }
    else if(id == 6){
        index1 = 1;
        index2 = 2;
    }
    else if(id == 7){
        index1 = 2;
        index2 = 0;
    }
    else if(id == 8){
        index1 = 2;
        index2 = 1;
    }
    else if(id == 9){
        index1 = 2;
        index2 = 2;
    }
}

void Player::play(Board* obj) {
    int id;
    while (true) {
        cout << "Please enter box ID ; " ;
           cin >> id ;
        if (id >= 1 && id <= 9)
        {
            translateId(id);
            if(obj->isEmpty(index1,index2)) {
                obj->updateBoard(playerSym,index1,index2);
                break;
            }else {
                cout << "This position is already taken! Please choose another location. \n\n" ;
            }
        }
        else {
            cout << "Please enter a valid location between 1-9. \n\n";
        }

    }
}




void Computer::setPtr(Board *address) {
    ptrBoard = address;
}

char Computer::getsymbol() {
    return computerSym;
}

void Computer::setSymbol(char sym) {
    if(sym == 'X') {
        computerSym = 'O';
        playerSym = 'X';
    }
    else if(sym == 'O') {
        computerSym = 'X';
        playerSym = 'O';
    }else
        cout << "Error! Something went wrong. Invalid computer symbol." << endl;
}

bool Computer::attack() {
    // Start lines check
    if(ptrBoard->getList(0,0) == computerSym && ptrBoard->getList(0,1) == computerSym && ptrBoard->isEmpty(0,2))
        ptrBoard->updateBoard(computerSym,0,2);
    else if(ptrBoard->getList(0,1) == computerSym && ptrBoard->getList(0,2) == computerSym && ptrBoard->isEmpty(0,0))
        ptrBoard->updateBoard(computerSym,0,0);
    else if(ptrBoard->getList(0,0) == computerSym && ptrBoard->getList(0,2) == computerSym && ptrBoard->isEmpty(0,1))
        ptrBoard->updateBoard(computerSym,0,1);
    else if(ptrBoard->getList(1,0) == computerSym && ptrBoard->getList(1,1) == computerSym && ptrBoard->isEmpty(1,2))
        ptrBoard->updateBoard(computerSym,1,2);
    else if(ptrBoard->getList(1,1) == computerSym && ptrBoard->getList(1,2) == computerSym && ptrBoard->isEmpty(1,0))
        ptrBoard->updateBoard(computerSym,1,0);
    else if(ptrBoard->getList(1,0) == computerSym && ptrBoard->getList(1,2) == computerSym && ptrBoard->isEmpty(1,1))
        ptrBoard->updateBoard(computerSym,1,1);
    else if(ptrBoard->getList(2,0) == computerSym && ptrBoard->getList(2,1) == computerSym && ptrBoard->isEmpty(2,2))
        ptrBoard->updateBoard(computerSym,2,2);
    else if(ptrBoard->getList(2,1) == computerSym && ptrBoard->getList(2,2) == computerSym && ptrBoard->isEmpty(2,0))
        ptrBoard->updateBoard(computerSym,2,0);
    else if(ptrBoard->getList(2,0) == computerSym && ptrBoard->getList(2,2) == computerSym && ptrBoard->isEmpty(2,1))
        ptrBoard->updateBoard(computerSym,2,1); // End lines check

    // Start columns check
    else if(ptrBoard->getList(0,0) == computerSym && ptrBoard->getList(1,0) == computerSym && ptrBoard->isEmpty(2,0))
        ptrBoard->updateBoard(computerSym,2,0);
    else if(ptrBoard->getList(1,0) == computerSym && ptrBoard->getList(2,0) == computerSym && ptrBoard->isEmpty(0,0))
        ptrBoard->updateBoard(computerSym,0,0);
    else if(ptrBoard->getList(0,0) == computerSym && ptrBoard->getList(2,0) == computerSym && ptrBoard->isEmpty(1,0))
        ptrBoard->updateBoard(computerSym,1,0);
    else if(ptrBoard->getList(0,1) == computerSym && ptrBoard->getList(1,1) == computerSym && ptrBoard->isEmpty(2,1))
        ptrBoard->updateBoard(computerSym,2,1);
    else if(ptrBoard->getList(1,1) == computerSym && ptrBoard->getList(2,1) == computerSym && ptrBoard->isEmpty(0,1))
        ptrBoard->updateBoard(computerSym,0,1);
    else if(ptrBoard->getList(0,1) == computerSym && ptrBoard->getList(2,1) == computerSym && ptrBoard->isEmpty(1,1))
        ptrBoard->updateBoard(computerSym,1,1);
    else if(ptrBoard->getList(0,2) == computerSym && ptrBoard->getList(1,2) == computerSym && ptrBoard->isEmpty(2,2))
        ptrBoard->updateBoard(computerSym,2,2);
    else if(ptrBoard->getList(1,2) == computerSym && ptrBoard->getList(2,2) == computerSym && ptrBoard->isEmpty(0,2))
        ptrBoard->updateBoard(computerSym,0,2);
    else if(ptrBoard->getList(0,2) == computerSym && ptrBoard->getList(2,2) == computerSym && ptrBoard->isEmpty(1,2))
        ptrBoard->updateBoard(computerSym,1,2); // End columns check

    // Diagonal check
    else if(ptrBoard->getList(0,0) == computerSym && ptrBoard->getList(1,1) == computerSym && ptrBoard->isEmpty(2,2))
        ptrBoard->updateBoard(computerSym,2,2);
    else if(ptrBoard->getList(1,1) == computerSym && ptrBoard->getList(2,2) == computerSym && ptrBoard->isEmpty(0,0))
        ptrBoard->updateBoard(computerSym,0,0);
    else if(ptrBoard->getList(0,0) == computerSym && ptrBoard->getList(2,2) == computerSym && ptrBoard->isEmpty(1,1))
        ptrBoard->updateBoard(computerSym,1,1);
    else if(ptrBoard->getList(0,2) == computerSym && ptrBoard->getList(1,1) == computerSym && ptrBoard->isEmpty(2,0))
        ptrBoard->updateBoard(computerSym,2,0);
    else if(ptrBoard->getList(1,1) == computerSym && ptrBoard->getList(2,0) == computerSym && ptrBoard->isEmpty(0,2))
        ptrBoard->updateBoard(computerSym,0,2);
    else if(ptrBoard->getList(0,2) == computerSym && ptrBoard->getList(2,0) == computerSym && ptrBoard->isEmpty(1,1))
        ptrBoard->updateBoard(computerSym,1,1);
    else
        return false;

    return true;

}

bool Computer::defend() {
    // Start lines check
    if(ptrBoard->getList(0,0) == playerSym && ptrBoard->getList(0,1) == playerSym && ptrBoard->isEmpty(0,2))
        ptrBoard->updateBoard(computerSym,0,2);
    else if(ptrBoard->getList(0,1) == playerSym && ptrBoard->getList(0,2) == playerSym && ptrBoard->isEmpty(0,0))
        ptrBoard->updateBoard(computerSym,0,0);
    else if(ptrBoard->getList(0,0) == playerSym && ptrBoard->getList(0,2) == playerSym && ptrBoard->isEmpty(0,1))
        ptrBoard->updateBoard(computerSym,0,1);
    else if(ptrBoard->getList(1,0) == playerSym && ptrBoard->getList(1,1) == playerSym && ptrBoard->isEmpty(1,2))
        ptrBoard->updateBoard(computerSym,1,2);
    else if(ptrBoard->getList(1,1) == playerSym && ptrBoard->getList(1,2) == playerSym && ptrBoard->isEmpty(1,0))
        ptrBoard->updateBoard(computerSym,1,0);
    else if(ptrBoard->getList(1,0) == playerSym && ptrBoard->getList(1,2) == playerSym && ptrBoard->isEmpty(1,1))
        ptrBoard->updateBoard(computerSym,1,1);
    else if(ptrBoard->getList(2,0) == playerSym && ptrBoard->getList(2,1) == playerSym && ptrBoard->isEmpty(2,2))
        ptrBoard->updateBoard(computerSym,2,2);
    else if(ptrBoard->getList(2,1) == playerSym && ptrBoard->getList(2,2) == playerSym && ptrBoard->isEmpty(2,0))
        ptrBoard->updateBoard(computerSym,2,0);
    else if(ptrBoard->getList(2,0) == playerSym && ptrBoard->getList(2,2) == playerSym && ptrBoard->isEmpty(2,1))
        ptrBoard->updateBoard(computerSym,2,1); // End lines check

    // Start columns check
    else if(ptrBoard->getList(0,0) == playerSym && ptrBoard->getList(1,0) == playerSym && ptrBoard->isEmpty(2,0))
        ptrBoard->updateBoard(computerSym,2,0);
    else if(ptrBoard->getList(1,0) == playerSym && ptrBoard->getList(2,0) == playerSym && ptrBoard->isEmpty(0,0))
        ptrBoard->updateBoard(computerSym,0,0);
    else if(ptrBoard->getList(0,0) == playerSym && ptrBoard->getList(2,0) == playerSym && ptrBoard->isEmpty(1,0))
        ptrBoard->updateBoard(computerSym,1,0);
    else if(ptrBoard->getList(0,1) == playerSym && ptrBoard->getList(1,1) == playerSym && ptrBoard->isEmpty(2,1))
        ptrBoard->updateBoard(computerSym,2,1);
    else if(ptrBoard->getList(1,1) == playerSym && ptrBoard->getList(2,1) == playerSym && ptrBoard->isEmpty(0,1))
        ptrBoard->updateBoard(computerSym,0,1);
    else if(ptrBoard->getList(0,1) == playerSym && ptrBoard->getList(2,1) == playerSym && ptrBoard->isEmpty(1,1))
        ptrBoard->updateBoard(computerSym,1,1);
    else if(ptrBoard->getList(0,2) == playerSym && ptrBoard->getList(1,2) == playerSym && ptrBoard->isEmpty(2,2))
        ptrBoard->updateBoard(computerSym,2,2);
    else if(ptrBoard->getList(1,2) == playerSym && ptrBoard->getList(2,2) == playerSym && ptrBoard->isEmpty(0,2))
        ptrBoard->updateBoard(computerSym,0,2);
    else if(ptrBoard->getList(0,2) == playerSym && ptrBoard->getList(2,2) == playerSym && ptrBoard->isEmpty(1,2))
        ptrBoard->updateBoard(computerSym,1,2); // End columns check

    // Diagonal check
    else if(ptrBoard->getList(0,0) == playerSym && ptrBoard->getList(1,1) == playerSym && ptrBoard->isEmpty(2,2))
        ptrBoard->updateBoard(computerSym,2,2);
    else if(ptrBoard->getList(1,1) == playerSym && ptrBoard->getList(2,2) == playerSym && ptrBoard->isEmpty(0,0))
        ptrBoard->updateBoard(computerSym,0,0);
    else if(ptrBoard->getList(0,0) == playerSym && ptrBoard->getList(2,2) == playerSym && ptrBoard->isEmpty(1,1))
        ptrBoard->updateBoard(computerSym,1,1);
    else if(ptrBoard->getList(0,2) == playerSym && ptrBoard->getList(1,1) == playerSym && ptrBoard->isEmpty(2,0))
        ptrBoard->updateBoard(computerSym,2,0);
    else if(ptrBoard->getList(1,1) == playerSym && ptrBoard->getList(2,0) == playerSym && ptrBoard->isEmpty(0,2))
        ptrBoard->updateBoard(computerSym,0,2);
    else if(ptrBoard->getList(0,2) == playerSym && ptrBoard->getList(2,0) == playerSym && ptrBoard->isEmpty(1,1))
        ptrBoard->updateBoard(computerSym,1,1);
    else
        return false;

    return true;
}

void Computer::play() {
    int ran1,ran2;

    if (attack() == false) {
        if (defend() == false) {
            while (true) {
                ran1 = rand()%3;
                ran2 = rand()%3;

                if (ptrBoard->isEmpty(ran1,ran2)) {
                    ptrBoard->updateBoard(computerSym,ran1,ran2);
                    break;
                }
            }
        }
    }

}



Game::Game() {
    cout << "Welcome to the Tic Tac Teo Game! \n\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    computer.setPtr(&board);
    board.resetBoard();
}


char Game::checkWin(Board *obje) {
    // Satırları kontrol et
    if (obje->getList(0,0) == obje->getList(0,1) && obje->getList(0,1) == obje->getList(0,2))
        return obje->getList(0,0);
    else if (obje->getList(1,0) == obje->getList(1,1) && obje->getList(1,1) == obje->getList(1,2))
        return obje->getList(1,0);
    else if (obje->getList(2,0) == obje->getList(2,1) && obje->getList(2,1) == obje->getList(2,2))
        return obje->getList(2,0);

    // Sütunları kontrol et
    else if (obje->getList(0,0) == obje->getList(1,0) && obje->getList(1,0) == obje->getList(2,0))
        return obje->getList(0,0);
    else if (obje->getList(0,1) == obje->getList(1,1) && obje->getList(1,1) == obje->getList(2,1))
        return obje->getList(0,1);
    else if (obje->getList(0,2) == obje->getList(1,2) && obje->getList(1,2) == obje->getList(2,2))
        return obje->getList(0,2);

    // Köşegenleri kontrol et
    else if (obje->getList(0,0) == obje->getList(1,1) && obje->getList(1,1) == obje->getList(2,2))
        return obje->getList(0,0);
    else if (obje->getList(0,2) == obje->getList(1,1) && obje->getList(1,1) == obje->getList(2,0))
        return obje->getList(0,2);
    else
        return '1';
}

bool Game::checkDraw() {
    if(
        board.getList(0,0) != '1' &&
        board.getList(0,1) != '2' &&
        board.getList(0,2) != '3' &&
        board.getList(1,0) != '4' &&
        board.getList(1,1) != '5' &&
        board.getList(1,2) != '6' &&
        board.getList(2,0) != '7' &&
        board.getList(2,1) != '8' &&
        board.getList(2,2) != '9'
        )
        return false;
    else
        return true;
}

void Game::startGame() {
    computer.setPtr(&board);
    char win,option;
    bool cont;
    while (true) {
        player.setSymbol(&computer);
        if(player.getSymbol() == 'X') {
            turn = true;
        } else {
            turn = false;
        }


        while (true) {
            if (turn) {
                board.displayBoard();
                player.play(&board);
                if (checkDraw() == false)
                    break;
                turn = false;
                board.displayBoard();
            }else {
                computer.play();
                if (checkDraw() == false)
                    break;
                turn = true;
            }

            if(checkWin(&board) != '1') {
                win = checkWin(&board);
                break;
            }
        }

        if (win == player.getSymbol())
            cout << "Congratulations! You won! " << endl;
        else if(win == computer.getsymbol())
            cout << "Unfortunately, you lost." << endl;
        else if(checkDraw() == false)
            cout << "It's a tie!" << endl;
        else
            cout << "Error! Something went wrong." << endl;

        board.resetBoard();
        while (true) {
            cout << "Would you like to play a game again  (y,n) : ";
            cin.ignore();
            cin >> option;
            if(option == 'Y' || option == 'y') {
                cont = true;
                break;
            }
            else if(option == 'N' || option == 'n') {
                cont = false;
                break;
            }else {
                cout << "Invalid input. Please try again!! \n\n";
            }

        }


        if(cont == false)
            break;
    }
}


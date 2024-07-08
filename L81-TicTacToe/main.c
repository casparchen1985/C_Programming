#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool is1stPlayer = true;
int myChoice = -1;

void drawBoard();
void showText();
void showWrongPositionText();
void showIllegalPositionText();
void showDrawEvenText();
void showWinText();
void markTheBoard();
bool isPositionLegal(int position);
bool isPositionAvailable(int position);
int checkTheWin();


int main(int argc, char **argv)
{
    drawBoard();
    showText();
    return 0;
}

void drawBoard () {
    system("clear");
    printf("Tic Tac Toe\n\n");
    printf("┌‒‒┬‒‒┬‒‒┐\n");
    printf("╎%2c╎%2c╎%2c╎\n", board[0], board[1], board[2]);
    printf("├‒‒╋‒‒╋‒‒┤\n");
    printf("╎%2c╎%2c╎%2c╎\n", board[3], board[4], board[5]);
    printf("├‒‒╋‒‒╋‒‒┤\n");
    printf("╎%2c╎%2c╎%2c╎\n", board[6], board[7], board[8]);
    printf("└‒‒┴‒‒┴‒‒┘\n\n");
}

void markTheBoard() {
     if (!isPositionLegal(myChoice)) {
        drawBoard();
        showIllegalPositionText();
    } else if (!isPositionAvailable(myChoice)) {
        drawBoard();
        showWrongPositionText();
    }
    
    if (is1stPlayer) board[myChoice-1] = 'O'; else board[myChoice-1] = 'X';
    drawBoard();
    
    int checkResult = checkTheWin();
    if (checkResult == 1) {
        // Game is over with result
        showWinText();
    } else if (checkResult == 0) {
        // Game is over but without result
        showDrawEvenText();
    } else {
        // Game is ongoing
        is1stPlayer = !is1stPlayer;
        showText();
    }
}

bool isPositionLegal(int position) {
    if (position >= 1 && position <= 9) return true; else return false;
}

bool isPositionAvailable(int position) {
    if (
        (position == 1 && board[0] == '1') ||
        (position == 2 && board[1] == '2') ||
        (position == 3 && board[2] == '3') ||
        (position == 4 && board[3] == '4') ||
        (position == 5 && board[4] == '5') ||
        (position == 6 && board[5] == '6') ||
        (position == 7 && board[6] == '7') ||
        (position == 8 && board[7] == '8') ||
        (position == 9 && board[8] == '9')
    ) {
        return true;
    } else {
       return false; 
    }
}

void showText() {
    printf("It's your turn, %s Player\n", is1stPlayer == true ? "1st" : "2nd");
    printf("What's your choice? ");
    scanf("%d", &myChoice);
    markTheBoard();
}

void showWrongPositionText() {
    printf("This location has been chosen\n");
    printf("Pick up another position: ");
    scanf("%d", &myChoice);
    markTheBoard();
}

void showIllegalPositionText() {
    printf("This location is invalid.\n");
    printf("Please enter correct position (1~9): ");
    scanf("%d", &myChoice);
    markTheBoard();
}

void showDrawEvenText() {
    printf("It battles to a draw \n\n");
}

void showWinText() {
    printf("The Winner is %s Player!!\n\n", is1stPlayer == true ? "1st" : "2nd");
}

/* Return the current status of the board
 * 1 For Game is over with result 
 * -1 For Game is ongoing
 * 0 For Game is over but without result
 */ 
int checkTheWin() {
    if ( 
        (board[0] == board[1] && board[1] == board[2]) || 
        (board[3] == board[4] && board[4] == board[5]) ||
        (board[6] == board[7] && board[7] == board[8]) ||
        (board[0] == board[3] && board[3] == board[6]) ||
        (board[1] == board[4] && board[4] == board[7]) ||
        (board[2] == board[5] && board[5] == board[8]) ||
        (board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[4] == board[6])
    ) {
        return 1;
    } else if (
        board[0] != '1' && board[1] != '2' && board[2] != '3' &&
        board[3] != '4' && board[4] != '5' && board[5] != '6' && 
        board[6] != '7' && board[7] != '8' && board[8] != '9'
    ) {
        return 0;
    } else {
        return -1;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct Game {
    char board[3][3];
    char player; // x or o
} Game;



int get_game_status(Game *game) {
     // check horizontal win
    for (int row = 0; row < 3; row++) {
        char pchar = game->board[row][0];
        if (game->board[row][1] == pchar &&
            game->board[row][2] == pchar) {
            if (pchar == 'O') {
                return 1;
            }
            else if (pchar == 'X') {
                return 2;
            }
        }
        
        
    }

    // check vertical win
    for (int col = 0; col < 3; col++) {
        char pchar = game->board[0][col];
        if (game->board[1][col] == pchar &&
            game->board[2][col] == pchar) {
            if (pchar == 'O') {
                return 1;
            }
            else if (pchar == 'X') {
                return 2;
            }
        }
        
        
    }
    
    char pchar = game->board[1][1];
    if (pchar != '-') {
        if (game->board[0][0] == pchar &&
            game->board[2][2] == pchar) {
            if (pchar == 'O') {
                return 1;
            }
            else if (pchar == 'X') {
                return 2;
            }

        }
        if (game->board[0][2] == pchar &&
            game->board[2][0] == pchar) {
            if (pchar == 'O') {
                return 1;
            }
            else if (pchar == 'X') {
                return 2;
            }
        }
    }
    

    return 0;
    
}

void get_input(char prompt[], char input[10]) {
    printf("%s", prompt);
    scanf("%10s", input);
}

void render_game(Game *game){
    printf("\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%c  ", game->board[row][col]);
   
        }
        printf("\n");
    }
    printf("\n");
    
}

int make_move(Game *game, int move) {
    int row, col;
    move--;
    if (move < 0 || move > 9) {
        return 1;
    }
    // move is 0-2
    if (move < 4) {
        row = 0;
        col = move;
    }
    // move is 3-5
    else if (move < 7) {
        row = 1;
        col = move-3;
    }
    //move is 6-8
    else {
        row = 2;
        col = move-6;
    }
    if (game->board[row][col] == '-') {
        game->board[row][col] = game->player;
        return 0;
    }
    return 1;
    
}

int main() {
    util_stuff();
    Game game = {
    .board = {{'-','-','-'}, {'-','-','-'}, {'-','-','-'}},
    .player = 'O',
    };

    printf("Tic Tac Toe\n");

    int running = 1;
    while (running == 1) {
        printf("%cs turn\n", game.player);

        render_game(&game);
        char player_input[10];
        get_input("move: ", player_input);
        int move_success = make_move(&game, atoi(player_input));
        while (move_success == 1) {
            printf("Invalid Move :<\n");
            get_input("move: ", player_input);
            move_success = make_move(&game, atoi(player_input));
        }

        int game_status = get_game_status(&game);
        if (game_status == 1) {
            render_game(&game);
            printf("Congratulations O");
            break;
        }
        else if (game_status == 2) {
            render_game(&game);
            printf("Congratulations X");
            break;
        }


        if (game.player == 'O') {
            game.player = 'X';
        }
        else {
            game.player = 'O';
        }

        printf("\n");

        
    }
    return 0;
}
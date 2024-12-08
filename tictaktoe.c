#include <stdio.h>

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWinner(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col, moves = 0;
    char player = 'X';
    int winner = 0;

    while (!winner && !isBoardFull(board)) {
        printBoard(board);
        printf("Player %c, enter row (1-3) and column (1-3): ", player);
        scanf("%d %d", &row, &col);
        row--; col--;
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        board[row][col] = player;
        moves++;
        if (checkWinner(board, player)) {
            winner = 1;
            printBoard(board);
            printf("Player %c wins!\n", player);
        } else if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
        }
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

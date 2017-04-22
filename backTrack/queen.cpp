//
// Created by RetroX on 20/04/2017.
//

#include <stdlib.h>
#include <stdio.h>

#define TRUE        1
#define FALSE       0
#define NUM_QUEENS  8

void output(int *queens) {
    for (int i = 0; i < NUM_QUEENS; i++) {
        printf("%d ", queens[i]);
    }
    printf("\n");
}

/*
 * 查看是否和 row 以上几行的皇后在同一列或同一对角线
 */

int constraint(int *queens, int row) {
    for (int i = 0; i < row; i++) {
        if (queens[row] == queens[i]
            || abs(i - row) == abs(queens[row] - queens[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

void eight_queens_puzzle_iter(int *queens, int row) {
    if (row == NUM_QUEENS) {
        output(queens);
        return;
    }
    for (int col = 0; col < NUM_QUEENS; col++) {
        queens[row] = col;
        if (constraint(queens, row) == TRUE) {
            eight_queens_puzzle_iter(queens, row + 1);
        }
    }
}

void eight_queens_puzzle(int *queens) {
    eight_queens_puzzle_iter(queens, 0);
}

int main() {
    int queens[NUM_QUEENS] = {0};

    eight_queens_puzzle(queens);

    return 0;
}

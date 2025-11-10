#include <stdio.h>

char papan[6][7];
int isItStop = 0;

void showPapan(char *data) {
    printf("-------------\n");
    printf("1 2 3 4 5 6 7\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%c ", *(data + i * 7 + j));
        }
        printf("\n");
    }
    printf("-------------\n");
    printf("1 2 3 4 5 6 7\n");
}

char checkVertical(char *data, int col) {
    int count = 0;
    char last = '.';
    col = col - 1;
    
    for (int i = 5; i >= 0; i--) {
        char now = *(data + i * 7 + col);
        if (now != '.' && now == last) {
            count++;
            if (count == 3) return now;
        } else {
            count = 0;
        }
        last = now;
    }
    return '-';
}

char checkHorizontal(char *data, int row) {
    int count = 0;
    char last = '.';
    for (int j = 0; j < 7; j++) {
        char now = *(data + row * 7 + j);
        if (now != '.' && now == last) {
            count++;
            if (count == 3) return now;
        } else {
            count = 0;
        }
        last = now;
    }
    return '-';
}

char checkDiagonal(char *data, int row, int col) {
    char now = *(data + row * 7 + col);
    if (now == '.') return '-';

    int count = 1;

    // ↘️
    for (int i = 1; row + i < 6 && col + i < 7; i++) {
        if (*(data + (row + i) * 7 + (col + i)) == now) count++;
        else break;
    }
    // ↖️
    for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
        if (*(data + (row - i) * 7 + (col - i)) == now) count++;
        else break;
    }
    if (count >= 4) return now;

    
    count = 1;
    // ↙️
    for (int i = 1; row + i < 6 && col - i >= 0; i++) {
        if (*(data + (row + i) * 7 + (col - i)) == now) count++;
        else break;
    }
    // ↗️
    for (int i = 1; row - i >= 0 && col + i < 7; i++) {
        if (*(data + (row - i) * 7 + (col + i)) == now) count++;
        else break;
    }
    if (count >= 4) return now;

    return '-';
}

int addNew(int col, char *data, char s) {
    for (int i = 5; i >= 0; i--) {
        if (*(data + i * 7 + col - 1) == '.') {
            *(data + i * 7 + col - 1) = s;
            return i; 
        }
    }
    return -1;
}

void getWinner(int col, int row) {
    char winner = checkVertical(&papan[0][0], col);
    if (winner == '-') winner = checkHorizontal(&papan[0][0], row);
    if (winner == '-') winner = checkDiagonal(&papan[0][0], row, col - 1);
    if (winner != '-') {
        isItStop = 1;
        showPapan(&papan[0][0]);
        printf("THE WINNER: %c\n", winner);
    }
}

int main() {
    int inputPlayer;
    char nowPlay = 'A';

    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            papan[i][j] = '.';
        }
    }

    int i=0;
    while (isItStop == 0) {
        showPapan(&papan[0][0]);
        printf("Kolom player %c: ", nowPlay);
        scanf("%d", &inputPlayer);

        int row = addNew(inputPlayer, &papan[0][0], nowPlay);
        if (row == -1) {
            printf("Kolom penuh!\n");
            continue;
        }

        getWinner(inputPlayer, row);
        nowPlay = (nowPlay == 'A') ? 'B' : 'A';
        i++;
        if (i == 42 && isItStop == 0) {
            isItStop = 1;
            showPapan(&papan[0][0]);
            printf("SERI!\n");
        }
    }
    return 0;
}

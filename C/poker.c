#include <stdio.h>

void sortCard(int *a) {
    for (int i = 0; i < 4;i++){
        
    }
}

int main(void) {
    int player[4][5][2]; //[player][card][rank/suit]

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char a, b;
            scanf("%c%c", &a, &b);

            if('1'<=a && a<='9'){
                player[i][j][0] = a - '0';
            }else{
                if (a == 't') player[i][j][0] = 10;
                if (a == 'j') player[i][j][0] = 11;
                if (a == 'q') player[i][j][0] = 12;
                if (a == 'k') player[i][j][0] = 13;
                if (a == 'a') player[i][j][0] = 14;
            }

            if (b == 's') player[i][j][1] = 4;
            if (b == 'h') player[i][j][1] = 3;
            if (b == 'd') player[i][j][1] = 2;
            if (b == 'c') player[i][j][1] = 1;
        }
    }

    sortCard(player);

    for (int i = 0; i < 4; i++) {
        char cards[5][2] = player[i];
        if (cards[0][0] == cards[0][0] == cards[0][0] == cards[0][0]){
        } else if (cards[0][0] == cards[0][0] == cards[0][0] && cards[0][0] == cards[0][0])
    }

    return 0;
}

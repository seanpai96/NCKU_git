#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int players[4][5][2];       //[player][card][rank/suit]

void sortCard() {
    for (int i = 0; i < 4;i++){
        for(int j=0;j<5;j++){
            for(int k= j;k<5;k++){
                if(players[i][j][0]>players[i][k][0]){
                    int tmp[2];
                    tmp[0] = players[i][j][0];
                    tmp[1] = players[i][j][1];
                    players[i][j][0] = players[i][k][0];
                    players[i][j][1] = players[i][k][1];
                    players[i][k][0] = tmp[0];
                    players[i][k][1] = tmp[1];
                }
            }
        }

        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(players[i][j][0] == players[i][k][0] && players[i][j][1] < players[i][k][1]){
                    int tmp[2];
                    tmp[0] = players[i][j][0];
                    tmp[1] = players[i][j][1];
                    players[i][j][0] = players[i][k][0];
                    players[i][j][1] = players[i][k][1];
                    players[i][k][0] = tmp[0];
                    players[i][k][1] = tmp[1];
                }
            }
        }
    }
}

int main(void) {
    int score[4] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            char a, b;
            a = getchar();
            b = getchar();
            getchar();
            // scanf("%c%c", &a, &b);

            if('1'<=a && a<='9'){
                players[i][j][0] = a - '0';
            }else{
                if (a == 't') players[i][j][0] = 10;
                if (a == 'j') players[i][j][0] = 11;
                if (a == 'q') players[i][j][0] = 12;
                if (a == 'k') players[i][j][0] = 13;
                if (a == 'a') players[i][j][0] = 14;
            }

            if (b == 's') players[i][j][1] = 4;
            if (b == 'h') players[i][j][1] = 3;
            if (b == 'd') players[i][j][1] = 2;
            if (b == 'c') players[i][j][1] = 1;
        }
    }

    sortCard();

    // for(int i=0;i<4;i++){
    //     for(int j=0;j<5;j++){
    //         printf("%d/%d ", players[i][j][0],players[i][j][1]);
    //     }
    //     putchar('\n');
    // }

    for(int i=0;i<4;i++){
        bool straight = true, flush = true;
        
        for(int j=0;j<4;j++){
            if(players[i][j+1][0] - players[i][j][0] != 1){
                straight = false;
                break;
            }
        }
        for (int j = 0; j < 4; j++){
            if(players[i][j][1] != players[i][j+1][1]){
                flush = false;
                break;
            }
        }

        if(straight && flush){
            score[i] = 90000+players[i][4][0]*10+players[i][4][1];      //straight flush, rank then suit
        }else{          //start to determine the amount of same card
            /*
            maxSame(int): the current amount of the card
            maxSameNum(int): the rank of the current recording card
            maxSameArr(int array[#ofCard][amount/rank]): array that stores the record of the same card
            maxSamePtr(int): the pointer that indicates the current place of maxSameArr.
            */
            int maxSame = 0, maxSameNum = players[i][0][0], maxSamePtr = 0, maxSameArr[5][2] = {0};
            for(int j=0;j<5;j++,maxSame++){
                if(players[i][j][0] != maxSameNum){
                    maxSameArr[maxSamePtr][0] = maxSame;
                    maxSameArr[maxSamePtr][1] = maxSameNum;
                    maxSamePtr++;
                    maxSame = 0;
                    maxSameNum = players[i][j][0];
                }
            }
            maxSameArr[maxSamePtr][0] = maxSame;
            maxSameArr[maxSamePtr][1] = maxSameNum;
            maxSamePtr++;

            //sort the list by the amount([0]), decending
            for(int j=0;j<maxSamePtr;j++){
                for(int k=j;k<maxSamePtr;k++){
                    if(maxSameArr[j][0]<maxSameArr[k][0]){
                        int tmp[2];
                        tmp[0] = maxSameArr[j][0];
                        tmp[1] = maxSameArr[j][1];
                        maxSameArr[j][0] = maxSameArr[k][0];
                        maxSameArr[j][1] = maxSameArr[k][1];
                        maxSameArr[k][0] = tmp[0];
                        maxSameArr[k][1] = tmp[1];
                    }
                }
            }

            if(flush){          //flush, rank then suit
                score[i] = 60000 + players[i][4][0]* 10 + players[i][4][1];
                continue;
            }

            if(straight){       //straight, rank then suit
                score[i] = 50000 + players[i][4][0]* 10 + players[i][4][1];
                continue;
            }

            if(maxSameArr[0][0] == 4){              //four of a kind, rank
                score[i] = 80000 + maxSameArr[0][1];
            }else if(maxSameArr[0][0] == 3){
                if(maxSameArr[1][0] == 2){          //full house, three card rank
                    score[i] = 70000 + maxSameArr[0][1];
                }else{                              //three of a kind, three card rank
                    score[i] = 40000 + maxSameArr[0][1];
                }
            }else if(maxSameArr[0][0] == 2){
                if(maxSameArr[1][0] == 2){          //two pair, rank then suit
                    int suitA = 0, suitB = 0;
                    for(int k=0;k<5;k++){
                        if(players[i][k][0] == maxSameArr[0][1]){
                            suitA = (suitA < players[i][k][1]) ? players[i][k][1] : suitA;
                        }
                        if(players[i][k][0] == maxSameArr[1][1]){
                            suitB = (suitB < players[i][k][1]) ? players[i][k][1] : suitB;
                        }
                    }
                    bool AB = maxSameArr[0][1] > maxSameArr[1][1];
                    score[i] = 30000 + (AB ? maxSameArr[0][1] : maxSameArr[1][1])*10 + (AB ? suitA : suitB);
                }else{                              //pair, rank then suit
                    int suit = 0;
                    for(int k=0;k<5;k++){
                        if(players[i][k][0] == maxSameArr[0][1]){
                            suit = (suit < players[i][k][1]) ? players[i][k][1] : suit;
                        }
                    }
                    score[i] = 20000 + maxSameArr[0][1]*10 + suit;
                }
            }else{                                  //high card, rank then suit
                score[i] = 10000 + players[i][4][0]*10 + players[i][4][1];
            }
            
        }
        
    }
    
    for(int a=0;a<4;a++){
        char winner;
        int mx = -1;
        for(int i=0;i<4;i++){
            char currentplayer = 'A' + i;
            if(score[i] > mx){
                winner = currentplayer;
                mx = score[i];
            }
        }
        int winnerpos = winner - 'A';
        printf("%c ", winner);
        // printf("%d %c/", score[winnerpos], winner);
        score[winnerpos] = -999;
    }

    
    return 0;
}

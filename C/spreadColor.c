#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position
    
    spread(&graph[0][0], row, col);
    
    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
// Your code goes here



void spread(char* graph, int row, int col) {
	int nowrow = row;
    int nowcol = col;
    char colorToSpread = *(graph+nowrow*N+nowcol);
    //up
    while(*(graph+nowrow*N+nowcol) == 'X' || *(graph+nowrow*N+nowcol) == colorToSpread){
        *(graph+nowrow*N+nowcol) = colorToSpread;
        nowrow--;
        if(nowrow < 0) break;
    }

    nowrow = row;
    nowcol = col;

    //down
    while(*(graph+nowrow*N+nowcol) == 'X' || *(graph+nowrow*N+nowcol) == colorToSpread){
        *(graph+nowrow*N+nowcol) = colorToSpread;
        nowrow++;
        if(nowrow > 5) break;
    }

    nowrow = row;
    nowcol = col;

    //right
    while(*(graph+nowrow*N+nowcol) == 'X' || *(graph+nowrow*N+nowcol) == colorToSpread){
        *(graph+nowrow*N+nowcol) = colorToSpread;
        nowcol++;
        if(nowcol>7) break;
    }

    nowrow = row;
    nowcol = col;

    //left
    while(*(graph+nowrow*N+nowcol) == 'X' || *(graph+nowrow*N+nowcol) == colorToSpread){
        *(graph+nowrow*N+nowcol) = colorToSpread;
        nowcol--;
        if(nowcol < 0) break;
    }
}








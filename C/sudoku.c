#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
// Your code goes here

void check_sudoku(int (*grid_p)[NUM]){
    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            int flag = 0;
            //go sideway
            for(int k=0;k<NUM;k++){
                if(k == j) continue;
                if(grid_p[i][j] == grid_p[i][k]){
                     printf("(%d,%d)\n", i, j);
                     flag = 1;
                     break;
                }
            }

            if(flag == 1) continue;

            //go straight
            for(int k=0;k<NUM;k++){
                if(k == i) continue;
                if(grid_p[i][j] == grid_p[k][j]){
                    printf("(%d,%d)\n", i, j);
                    flag = 1;
                    break;
                }
            }

            if(flag == 1) continue;

            //check square
            //get midpoint
            int upperLefti = (i/3)*3;
            int upperLeftj = (j/3)*3;
            for(int x=upperLefti; x<upperLefti+3;x++){
                for(int y=upperLeftj; y<upperLeftj+3;y++){
                    if(i == x && j == y) continue;
                    if(grid_p[i][j] == grid_p[x][y]){
                        printf("(%d,%d)\n", i,j);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1)break;
            }
        }
    }
}

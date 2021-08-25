#include <stdio.h>
#include <stdbool.h>

#define WALLS 4
#define ROWS 8

#define COLS 8
#define PASS 0

bool solveMaze(int (*rows_ptr)[COLS][WALLS], int *head, int *end, int row, int col){
    int *prev;
    int oppositeWall;

    if(head == end){
        printf("\nmaze end");
        return true;
    }
    
    for(int i = 3; i >= 0; i--){
        if(head[i] == PASS){
            if(i <=1 ){
                oppositeWall = i+2;
            }else{
                oppositeWall = i-2;
            }
            printf("\nrow = %d, col = %d", row, col);
            printf("\nhead[%d] = %d", i, head[i]);
            //head[i] = 1;
            (*(*(rows_ptr+row)+col))[i] = 1;
            printf("\nhead[%d] = %d", i, head[i]);
            prev = head;
            switch(i){
                case 0:
                    row-=1;
                    break;
                case 1:
                    col+=1;
                    break;
                case 2:
                    row+=1;
                    break;
                case 3:
                    col-=1;
                    break;
            }
            head = *(*(rows_ptr+row)+col);
            printf("\n-------------------");
            printf("\nrow = %d, col = %d", row, col);
            printf("\nhead[%d] = %d", oppositeWall, head[oppositeWall]);
            (*(*(rows_ptr+row)+col))[oppositeWall] = 1;
            //head[oppositeWall] = 1;
            printf("\nhead[%d] = %d", oppositeWall, head[oppositeWall]);
            printf("\n--------------lol----------------\n");
            
            if(solveMaze(rows_ptr, head, end, row, col)){
                return true;
            }
            head = prev;
        }
    }

    printf("\nreturn false");
    return false;
}

int main(){

    int col = 0, row = 3;
    int maze[ROWS][COLS][WALLS] = 
    {
        {{1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 0}, {1, 0, 1, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 1}, {1, 1, 0, 0}},
        {{0, 1, 0, 1}, {1, 0, 0, 1}, {1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 1, 0, 1}},
        {{0, 0, 1, 1}, {0, 1, 1, 0}, {0, 1, 0, 1}, {0, 0, 1, 1}, {1, 0, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 0}, {0, 1, 0, 1}},
        {{1, 1, 0, 1}, {1, 0, 1, 1}, {0, 0, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 0, 1}},
        {{0, 1, 0, 1}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 0, 1}, {1, 1, 0, 1}, {0, 1, 0, 1}},
        {{0, 0, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 1, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}, {0, 1, 0, 1}},
        {{1, 0, 0, 1}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}, {0, 1, 0, 1}},
        {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 0, 1, 0}, {1, 0, 1, 0}, {0, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}}

    };

    int (*rows_ptr)[COLS][WALLS] = maze;
    int *start = **(rows_ptr+3);
    int *end = *(*(rows_ptr+7)+7);
    int *head = start;

    //printf("%d", *head);
    printf("%d", &head[3]);
    solveMaze(rows_ptr, head, end, row, col);
    return 0;
}
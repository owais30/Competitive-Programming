/* C/C++ program to solve N Queen Problem using 
   backtracking */
#define N 8
#include<stdio.h> 
#include<stdbool.h> 
#include<iostream>
using namespace std;
/* A utility function to print solution */
int ans = 0;
int diff = 10000;
int getdiff(int board[N][N], int inputs[])
{
    int d = 0;
    for(int i=0;i<N;i++)
        for(int j =0; j<N; j++)
            if(board[j][i])
                d += abs(j - inputs[i] + 1);
    return d;
}

void printSolution(int board[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
} 
bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 
  

    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  
int solveNQUtil(int board[N][N], int col, int curr, int inputs[]) 
{ 
    if (col >= N) 
    {
        ans++;
        printf("ans: %d diff: %d\n", ans, getdiff(board, inputs));
        //diff = min(getdiff(board, inputs), diff);
        printSolution(board);
        printf("\n");
        board[N][N] = {0};
        return false;
    }
  
    for (int i = 0; i < N; i++) 
    { 
        if ( isSafe(board, i, col) ) 
        { 
            board[i][col] = 1; 
            if ( solveNQUtil(board, col + 1, 1, inputs) ) 
            {
                return true;
            }
  
            
            board[i][col] = 0;
        } 
    } 
    if(curr) return false;
    else
    return ans;
} 
  

bool solveNQ(int inputs[]) 
{ 
    int board[N][N] = {0};
    printf("%d\n", solveNQUtil(board, 0, 0, inputs));
} 
  
// driver program to test above function 
int main() 
{ 
    int inputs[N];
    for(int i=0;i<N;i++)
        scanf("%d", &inputs[i]);
    solveNQ(inputs); 
    printf("%d\n", diff);
    return 0; 
} 

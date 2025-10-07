#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define MINES 10

typedef struct node
{
    int row, col;
	int vertex;
}node;

//Declaring the global variables
bool visited[MINES] = {false};
node graph[MINES];
node *head;
void dfs(int v);
void PlaceNums(node g);
int board[ROWS][COLS] = {0}; // 0 = empty, -1 = mine

int main() 
{
    int placed = 0;
    head = graph;
    srand(time(NULL)); // seed random generator

    while (placed < MINES) {
        int r = rand() % ROWS;
        int c = rand() % COLS;

        if (board[r][c] == 0) {   // place mine only if empty
            board[r][c] = -1;     // -1 = mine
            graph[placed].row = r;
            graph[placed].col = c;
            graph[placed].vertex = placed;
            placed++;
        }
    }
    
    dfs(0);

    //Print the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1)
            {
                printf(" * ");
            }
            else if(board[i][j] == 0)
            {
                printf(" _ ");
            }
            else
            {
                printf(" %d ",board[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

void dfs(int v)
{
    visited[v]=true;
	PlaceNums(graph[v]);
    //printf("%d\t",v);
	for(node w = graph[v] ; w.vertex<MINES ; w = graph[++v])
    {
		if(!visited[w.vertex])
        {
			dfs(w.vertex);
        }
    }
	return;		
}

void PlaceNums(node g)
{
    for(int i = g.col-1; i <= g.col+1; i++)
    {
        if(g.row!=0 && i!=(MINES-1) && i!=-1 && board[g.row-1][i]!=-1)
        {
            board[g.row-1][i] += 1;
        }
        if(g.row!=(MINES-2) && i!=(MINES-1) && i!=-1 && board[g.row+1][i]!=-1)
        {
            board[g.row+1][i] += 1;
        }
    }
    if(g.col!=(MINES-2) && board[g.row][g.col+1]!=-1)
    {    
        board[g.row][g.col+1] += 1;
    }
    if(g.col!=0 && board[g.row][g.col-1]!=-1)
    {
        board[g.row][g.col-1] += 1;
    }
    // for(int i = g.row-1; i <= g.row; i++)
    // {
    //     for(int j = g.col-1; j <= g.col; j++)
    //     {
    //         printf("%d ",board[i][j]);
    //     }
    //     printf("\n");
    // }
}

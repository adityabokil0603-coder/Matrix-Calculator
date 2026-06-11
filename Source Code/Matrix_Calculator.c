// An Advanced Matrix Calculator Program for Mini Project
#include <stdio.h>

void inputMatrix(int mat[10][10], int r, int c)
{
    int i,j;
    printf("Enter matrix elements:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
}

void displayMatrix(int mat[10][10], int r, int c)
{
    int i,j;
    printf("Entered Matrix:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[10][10];
    int rows,cols;

    printf("Enter number of rows and columns:\n");
    scanf("%d %d",&rows,&cols);

    inputMatrix(A,rows,cols);
    displayMatrix(A,rows,cols);

    getchar();
    getchar();
    
    return 0;
}
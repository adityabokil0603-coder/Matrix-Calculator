// An Advanced Matrix Calculator Program for Mini Project
#include <stdio.h>

void inputMatrix(int mat[10][10], int r, int c) // A method to input matrix elements
{
    int i,j;
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
}

void displayMatrix(int mat[10][10], int r, int c) // A method to display matrices
{
    int i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%4d",mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matA[10][10], int matB[10][10], int matSum[10][10], int r, int c) // A method to add matrices
{
    int i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        matSum[i][j]=matA[i][j]+matB[i][j];
    }
}

int main()
{
    int choice;

    printf("====Advanced Matrix Calculator====\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    printf("4. Transpose of a Matrix\n");
    printf("5. Exit\n"); 

    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
        {
            int r,c;
            printf("Enter rows and columns of Matrix A and B:\n");
            scanf("%d %d",&r,&c);
            int matA[10][10], matB[10][10], matSum[10][10];

            printf("Enter elements of Matrix A:\n");
            inputMatrix(matA,r,c);

            printf("\n");

            printf("Enter elements of Matrix B:\n");
            inputMatrix(matB,r,c); 

            addMatrix(matA,matB,matSum,r,c);

            printf("\n");

            printf("Summation Matrix:\n");
            displayMatrix(matSum,r,c);

            break;
        }
        case 2:
        {
            // Code for Matrix Subtraction
            break;
        }
        case 3:
        {
            // Code for Matrix Multiplication
            break;
        }
        case 4:
        {
            // Code for Matrix Transpose
            break;
        }
        case 5:
        {
            // Exit code
            break;
        }
        default:
        {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
} 
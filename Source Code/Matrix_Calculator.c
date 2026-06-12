// An Advanced Matrix Calculator Program for Mini Project
#include <stdio.h>

void inputMatrix(int mat[10][10], int r, int c) // A method to input matrix elements
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

void displayMatrix(int mat[10][10], int r, int c) // A method to display matrices
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
            // Code for Matrix Addition
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
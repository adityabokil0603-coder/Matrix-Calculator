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
        {
            matSum[i][j]=matA[i][j]+matB[i][j];
        }
    }
}

void subtractMatrix(int matA[10][10], int matB[10][10], int matDiff[10][10], int r, int c) // A method to subtract matrices
{
    int i,j;
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            matDiff[i][j]=matA[i][j]-matB[i][j];
        }
    }
}

void multiplyMatrix(int matA[10][10], int matB[10][10], int matMul[10][10], int r, int c, int p) // A method to multiply matrices
{
    int i,j,k;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            for(k=0;k<p;k++)
            {
                matMul[i][j]+=matA[i][k]*matB[k][j]; 
            }
        }
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

    printf("\n");
    
    switch(choice)
    {
        case 1:
        {
            int r,c;
            printf("Enter rows and columns of Matrix A and B:\n");
            scanf("%d %d",&r,&c);

            printf("\n");

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
            int r,c;
            printf("Enter rows and columns of Matrix A and B:\n");
            scanf("%d %d",&r,&c);

            printf("\n");

            int matA[10][10], matB[10][10], matDiff[10][10];

            printf("Enter elements of Matrix A:\n");
            inputMatrix(matA,r,c);

            printf("\n");

            printf("Enter elements of Matrix B:\n");
            inputMatrix(matB,r,c);

            subtractMatrix(matA,matB,matDiff,r,c);

            printf("\n");

            printf("Difference Matrix:\n");
            displayMatrix(matDiff,r,c);

            break;
        }
        case 3:
        {
            int i,j; int rA,cA,rB,cB;
            int matA[10][10], matB[10][10], matMul[10][10];

            printf("Enter rows and columns of Matrix A:\n");
            scanf("%d %d",&rA,&cA);

            printf("\n");

            printf("Enter rows and columns of Matrix B:\n");
            scanf("%d %d",&rB,&cB);

            printf("\n");

            if(cA!=rB)
            {
                printf("Invalid Input!!\n");
                printf("Columns of Matrix A must be equal to Rows of Matrix B!");
            }
            else
            {
                // First we need to initialize matMul as a null matrix
                for(i=0;i<rA;i++)
                {
                    for(j=0;j<cB;j++)
                    {
                        matMul[i][j]=0;
                    }
                }

                printf("Enter elements of Matrix A:\n");
                inputMatrix(matA,rA,cA);

                printf("\n");

                printf("Enter elements of Matrix B:\n");
                inputMatrix(matB,rB,cB);

                printf("\n");

                multiplyMatrix(matA,matB,matMul,rA,cB,cA);

                printf("Multiplication Matrix:\n");
                displayMatrix(matMul,rA,cB);
            }

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
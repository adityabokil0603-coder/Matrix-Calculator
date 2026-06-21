// An Advanced Matrix Calculator Program for Mini Project
#include <stdio.h>

/* *********************************HELPER FUNCTIONS********************************** */

void inputMatrix(int mat[10][10], int r, int c) // A method to input matrix elements
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[10][10], int r, int c) // A method to display matrices
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

/* ********************************OPERATIONAL FUNCTIONS********************************** */

void addMatrix(int matA[10][10], int matB[10][10], int matSum[10][10], int r, int c) // A method to add matrices
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matSum[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void subtractMatrix(int matA[10][10], int matB[10][10], int matDiff[10][10], int r, int c) // A method to subtract matrices
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matDiff[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

void multiplyMatrix(int matA[10][10], int matB[10][10], int matMul[10][10], int r, int c, int p) // A method to multiply matrices
{
    int i, j, k;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            for (k = 0; k < p; k++)
            {
                matMul[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[10][10], int matTrans[10][10], int r, int c) // A method to take transpose of a matrix
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matTrans[j][i] = mat[i][j];
        }
    }
}

void rowSum(int mat[10][10], int matRowSum[10][10], int r, int c) // A method to calculate the sum of all elements in a row of a matrix
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matRowSum[i][0] += mat[i][j];
        }
    }
}

void colSum(int mat[10][10], int matColSum[10][10], int r, int c) // A method to calculate the sum of all elements in a column of a matrix
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matColSum[0][j] += mat[i][j];
        }
    }
}

void matTrace(int mat[10][10], int matSum[10][10], int r) // A method to calculate the trace of a matrix
{
    int i;

    for (i = 0; i < r; i++)
    {
        matSum[0][0] += mat[i][i];
    }
}

void matSecDiag(int mat[10][10], int matSum[10][10], int r, int c) // A method to calculate sum of secondary diagonal
{
    int i;

    for(i=0;i<r;i++)
    {
        matSum[0][0]+=mat[i][c-1-i];
    }
}

/* *********************************HANDLER FUNCTIONS********************************** */
// Yet to add

int main()
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("====Advanced Matrix Calculator====\n\n");
        printf("===Core Calculator Foundation===\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Subtraction\n");
        printf("3. Matrix Multiplication\n");
        printf("4. Transpose of a Matrix\n\n");
        printf("===Matrix Analysis Operations===\n");
        printf("5. Row Sum\n");
        printf("6. Column Sum\n");
        printf("7. Matrix Trace\n");
        printf("8. Secondary Diagonal Sum\n");
        printf("9. Sum of All elements\n");
        printf("10. Maximum Element\n");
        printf("11. Minimum Element\n");
        printf("12. Count Positive Elements\n");
        printf("13. Count Negative Elements\n");
        printf("14. Count Zero Elements\n\n");
        printf("15. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
        case 1:
        {
            int r, c;
            printf("Enter rows and columns of Matrix A and B:\n");
            scanf("%d %d", &r, &c);

            printf("\n");

            int matA[10][10], matB[10][10], matSum[10][10];

            printf("Enter elements of Matrix A:\n");
            inputMatrix(matA, r, c);

            printf("\n");

            printf("Enter elements of Matrix B:\n");
            inputMatrix(matB, r, c);

            addMatrix(matA, matB, matSum, r, c);

            printf("\n");

            printf("Summation Matrix:\n");
            displayMatrix(matSum, r, c);

            break;
        }
        case 2:
        {
            int r, c;
            printf("Enter rows and columns of Matrix A and B:\n");
            scanf("%d %d", &r, &c);

            printf("\n");

            int matA[10][10], matB[10][10], matDiff[10][10];

            printf("Enter elements of Matrix A:\n");
            inputMatrix(matA, r, c);

            printf("\n");

            printf("Enter elements of Matrix B:\n");
            inputMatrix(matB, r, c);

            subtractMatrix(matA, matB, matDiff, r, c);

            printf("\n");

            printf("Difference Matrix:\n");
            displayMatrix(matDiff, r, c);

            break;
        }
        case 3:
        {
            int i, j;
            int rA, cA, rB, cB;
            int matA[10][10], matB[10][10], matMul[10][10];

            printf("Enter rows and columns of Matrix A:\n");
            scanf("%d %d", &rA, &cA);

            printf("\n");

            printf("Enter rows and columns of Matrix B:\n");
            scanf("%d %d", &rB, &cB);

            printf("\n");

            if (cA != rB)
            {
                printf("Invalid Input!!\n");
                printf("Columns of Matrix A must be equal to Rows of Matrix B!");
            }
            else
            {
                // First we need to initialize matMul as a null matrix
                for (i = 0; i < rA; i++)
                {
                    for (j = 0; j < cB; j++)
                    {
                        matMul[i][j] = 0;
                    }
                }

                printf("Enter elements of Matrix A:\n");
                inputMatrix(matA, rA, cA);

                printf("\n");

                printf("Enter elements of Matrix B:\n");
                inputMatrix(matB, rB, cB);

                printf("\n");

                multiplyMatrix(matA, matB, matMul, rA, cB, cA);

                printf("Multiplication Matrix:\n");
                displayMatrix(matMul, rA, cB);
            }

            break;
        }
        case 4:
        {
            int mat[10][10], matTrans[10][10];
            int r, c;

            printf("Enter rows and columns of Matrix:\n");
            scanf("%d %d", &r, &c);

            printf("\n");

            printf("Enter elements of the Matrix:\n");
            inputMatrix(mat, r, c);

            printf("\n");

            transposeMatrix(mat, matTrans, r, c);

            printf("Transpose Matrix:\n");
            displayMatrix(matTrans, c, r);

            break;
        }
        case 5:
        {
            int mat[10][10], matSum[10][10];
            int r, c, i;

            printf("Enter rows and columns of Matrix:\n");
            scanf("%d %d", &r, &c);

            printf("\n");

            printf("Enter elements of the Matrix:\n");
            inputMatrix(mat, r, c);

            printf("\n");

            // Initializing matSum matrix as a null matrix
            for (i = 0; i < r; i++)
            {
                matSum[i][0] = 0;
            }

            rowSum(mat, matSum, r, c);

            printf("Row Sum Matrix:\n");
            displayMatrix(matSum, r, 1);

            break;
        }
        case 6:
        {
            int mat[10][10], matSum[10][10];
            int r, c, j;

            printf("Enter rows and columns of Matrix:\n");
            scanf("%d %d", &r, &c);

            printf("\n");

            printf("Enter elements of the Matrix:\n");
            inputMatrix(mat, r, c);

            printf("\n");

            // Initializing matSum as a null matrix
            for (j = 0; j < c; j++)
            {
                matSum[0][j] = 0;
            }

            colSum(mat, matSum, r, c);

            printf("Column Sum Matrix:\n");
            displayMatrix(matSum, 1, c);

            break;
        }
        case 7:
        {
            int r, c, i, j;
            int mat[10][10], matSum[10][10];

            printf("Enter rows and columns of Matrix:\n");
            scanf("%d %d", &r, &c);

            if (r != c)
            {
                printf("Invalid input!! Trace only works for square matrices!");
            }
            else
            {
                printf("Enter elements of matrix:\n");
                inputMatrix(mat, r, c);

                printf("\n");

                // Initializing matSum as Null Matrix
                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        matSum[i][j] = 0;
                    }
                }

                matTrace(mat, matSum, r);

                printf("Trace of Matrix:\n");
                displayMatrix(matSum, 1, 1);
            }

            break;
        }
        case 8:
        {
            int r,c,i,j;
            int mat[10][10], matSum[10][10];

            printf("Enter rows and columns of matrix:\n");
            scanf("%d %d",&r,&c);

            printf("\n");

            if(r!=c)
            {
                printf("Invalid input!! Rows and Columns must be equal for this feature!\n");
            }
            else
            {
                printf("Enter elements of matrix:\n");
                inputMatrix(mat,r,c);

                printf("\n");

                // Initializing matSum as Null Matrix
                for(i=0;i<r;i++)
                {
                    for(j=0;j<c;j++)
                    {
                        matSum[i][j]=0;
                    }
                }

                matSecDiag(mat,matSum,r,c);

                printf("Secondary Diagonal Sum of Matrix:\n");
                displayMatrix(matSum,1,1);
            }

            break;
        }
        case 9:
        {
            // Code for Sum of all elements in a Matrix
            break;
        }
        case 10:
        {
            // Code to find greatest element in matrix
            break;
        }
        case 11:
        {
            // Code to find smallest element in matrix
            break;
        }
        case 12:
        {
            // Code to count number of positive elements
            break;
        }
        case 13:
        {
            // Code to count number of negative elements
            break;
        }
        case 14:
        {
            // Code to count number of zero elements
            break;
        }
        case 15:
        {
            printf("Thank you for using the Matrix Calculator!!\n");
            printf("Hope you had a good time!!\n");
            printf("Visit soon!!\n");
            printf("Program Ends :D !!\n");
            break;
        }
        default:
        {
            printf("Invalid Choice!\n");
            printf("Please enter a correct choice!\n");
        }
        }

        if (choice == 15)
        {
            break;
        }
    }

    return 0;
}
// An Advanced Matrix Calculator Program for Mini Project
#include <stdio.h>

/* **************************************** FUNCTION PROTOTYPES **************************************** */

/* Helper Functions */
void inputMatrix(int mat[10][10], int r, int c);
void displayMatrix(int mat[10][10], int r, int c);
void initialize2DMatrix(int mat[10][10], int r, int c);

/* Operational Functions */
// Phase 1
void addMatrices(int matA[10][10], int matB[10][10], int matSum[10][10], int r, int c);
void subtractMatrices(int matA[10][10], int matB[10][10], int matDiff[10][10], int r, int c);
void multiplyMatrices(int matA[10][10], int matB[10][10], int matMul[10][10], int r, int c, int p);
void transposeMatrix(int mat[10][10], int matTrans[10][10], int r, int c);

// Phase 2
void rowSum(int mat[10][10], int matRowSum[10], int r, int c);
void colSum(int mat[10][10], int matColSum[10], int r, int c);
int matTrace(int mat[10][10], int r);
int matSecDiag(int mat[10][10], int r, int c);
int matEleSum(int mat[10][10], int r, int c);
int matGreatEle(int mat[10][10], int r, int c);
int matSmallEle(int mat[10][10], int r, int c);
int posCount(int mat[10][10], int r, int c);
int negCount(int mat[10][10], int r, int c);
int zeroCount(int mat[10][10], int r, int c);

/* Handler Functions */
// Phase 1
void handleAddition();
void handleSubtraction();
void handleMultiplication();
void handleTranspose();

// Phase 2
void handleRowSum();
void handleColSum();
void handleTrace();
void handleSecondaryDiagonal();
void handleElementsSum();
void handleMaximum();
void handleMinimum();
void handlePositiveCount();
void handleNegativeCount();
void handleZeroCount();

/* Menu Functions */
void printMenu();
void printPhase1Menu();
void printPhase2Menu();

/* **************************************** HELPER FUNCTIONS *************************************** */

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

void initialize2DMatrix(int mat[10][10], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            mat[i][j] = 0;
        }
    }
}

/* **************************************** OPERATIONAL FUNCTIONS **************************************** */

// Phase 1
void addMatrices(int matA[10][10], int matB[10][10], int matSum[10][10], int r, int c) // A method to add matrices
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

void subtractMatrices(int matA[10][10], int matB[10][10], int matDiff[10][10], int r, int c) // A method to subtract matrices
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

void multiplyMatrices(int matA[10][10], int matB[10][10], int matMul[10][10], int r, int c, int p) // A method to multiply matrices
{
    int i, j, k;

    initialize2DMatrix(matMul, r, c);

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

// Phase 2
void rowSum(int mat[10][10], int matRowSum[10], int r, int c) // A method to calculate the sum of all elements in a row of a matrix
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matRowSum[i] += mat[i][j];
        }
    }
}

void colSum(int mat[10][10], int matColSum[10], int r, int c) // A method to calculate the sum of all elements in a column of a matrix
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matColSum[j] += mat[i][j];
        }
    }
}

// Precondition: Matrix must be square (r==c)
int matTrace(int mat[10][10], int r) // A method to calculate the trace of a matrix
{
    int i, sum = 0;

    for (i = 0; i < r; i++)
    {
        sum += mat[i][i];
    }

    return sum;
}

// Precondition: Matrix must be square (r==c)
int matSecDiag(int mat[10][10], int r, int c) // A method to calculate sum of secondary diagonal
{
    int i, sum = 0;

    for (i = 0; i < r; i++)
    {
        sum += mat[i][c - 1 - i];
    }

    return sum;
}

int matEleSum(int mat[10][10], int r, int c) // A method to calculate sum of all elements in matrix
{
    int i, j, sum = 0;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            sum += mat[i][j];
        }
    }

    return sum;
}

int matGreatEle(int mat[10][10], int r, int c) // A method to find greatest element in matrix
{
    int i, j, max;
    max = mat[0][0];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mat[i][j] > max)
            {
                max = mat[i][j];
            }
        }
    }

    return max;
}

int matSmallEle(int mat[10][10], int r, int c) // A method to find smallest element in matrix
{
    int i, j, min;
    min = mat[0][0];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mat[i][j] < min)
            {
                min = mat[i][j];
            }
        }
    }

    return min;
}

int posCount(int mat[10][10], int r, int c)
{
    int i, j, count = 0;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mat[i][j] > 0)
            {
                count++;
            }
        }
    }

    return count;
}

int negCount(int mat[10][10], int r, int c)
{
    int i, j, count = 0;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mat[i][j] < 0)
            {
                count++;
            }
        }
    }

    return count;
}

int zeroCount(int mat[10][10], int r, int c)
{
    int i, j, count = 0;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
            {
                count++;
            }
        }
    }

    return count;
}

/* *********************************HANDLER FUNCTIONS********************************** */

// Phase 1
void handleAddition()
{
    int r, c;
    printf("Enter rows and columns of Matrix A and B:\n");
    scanf("%d %d", &r, &c);

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("\n");

    int matA[10][10], matB[10][10], matSum[10][10];

    printf("Enter elements of Matrix A:\n");
    inputMatrix(matA, r, c);

    printf("\n");

    printf("Enter elements of Matrix B:\n");
    inputMatrix(matB, r, c);

    addMatrices(matA, matB, matSum, r, c);

    printf("\n");

    printf("Summation Matrix:\n");
    displayMatrix(matSum, r, c);
}

void handleSubtraction()
{
    int r, c;
    printf("Enter rows and columns of Matrix A and B:\n");
    scanf("%d %d", &r, &c);

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("\n");

    int matA[10][10], matB[10][10], matDiff[10][10];

    printf("Enter elements of Matrix A:\n");
    inputMatrix(matA, r, c);

    printf("\n");

    printf("Enter elements of Matrix B:\n");
    inputMatrix(matB, r, c);

    subtractMatrices(matA, matB, matDiff, r, c);

    printf("\n");

    printf("Difference Matrix:\n");
    displayMatrix(matDiff, r, c);
}

void handleMultiplication()
{
    int rA, cA, rB, cB;
    int matA[10][10], matB[10][10], matMul[10][10];

    printf("Enter rows and columns of Matrix A:\n");
    scanf("%d %d", &rA, &cA);

    printf("\n");

    printf("Enter rows and columns of Matrix B:\n");
    scanf("%d %d", &rB, &cB);

    printf("\n");

    if (rA <= 0 || rA > 10 || cA <= 0 || cA > 10 || rB <= 0 || rB > 10 || cB <= 0 || cB > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }
    if (cA != rB)
    {
        printf("Matrix multiplication is not possible. Columns of Matrix A must equal rows of Matrix B.\n");
        return;
    }

    printf("Enter elements of Matrix A:\n");
    inputMatrix(matA, rA, cA);

    printf("\n");

    printf("Enter elements of Matrix B:\n");
    inputMatrix(matB, rB, cB);

    printf("\n");

    multiplyMatrices(matA, matB, matMul, rA, cB, cA);

    printf("Multiplication Matrix:\n");
    displayMatrix(matMul, rA, cB);
}

void handleTranspose()
{
    int mat[10][10], matTrans[10][10];
    int r, c;

    printf("Enter rows and columns of Matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("\n");

    printf("Enter elements of the Matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    transposeMatrix(mat, matTrans, r, c);

    printf("Transpose Matrix:\n");
    displayMatrix(matTrans, c, r);
}

// Phase 2
void handleRowSum()
{
    int mat[10][10], matSum[10];
    int r, c, i;

    printf("Enter rows and columns of Matrix:\n");
    scanf("%d %d", &r, &c);

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("\n");

    printf("Enter elements of the Matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    for (i = 0; i < r; i++)
    {
        matSum[i] = 0;
    }

    rowSum(mat, matSum, r, c);

    printf("Row Sum Matrix:\n");
    for (i = 0; i < r; i++)
    {
        printf("%d\n", matSum[i]);
    }
}

void handleColSum()
{
    int mat[10][10], matSum[10];
    int r, c, j;

    printf("Enter rows and columns of Matrix:\n");
    scanf("%d %d", &r, &c);

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("\n");

    printf("Enter elements of the Matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    for (j = 0; j < c; j++)
    {
        matSum[j] = 0;
    }

    colSum(mat, matSum, r, c);

    printf("Column Sum Matrix:\n");
    for (j = 0; j < c; j++)
    {
        printf("%d ", matSum[j]);
    }
    printf("\n");
}

void handleTrace()
{
    int r, c;
    int mat[10][10], sum;

    printf("Enter rows and columns of Matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    if (r != c)
    {
        printf("Invalid input!! Trace only works for square matrices!\n");
        return;
    }

    printf("Enter elements of matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    sum = matTrace(mat, r);

    printf("Trace of Matrix: %d\n", sum);
}

void handleSecondaryDiagonal()
{
    int r, c;
    int mat[10][10], sum;

    printf("Enter rows and columns of matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    if (r != c)
    {
        printf("Invalid input!! Rows and Columns must be equal for this feature!\n");
        return;
    }

    printf("Enter elements of matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    sum = matSecDiag(mat, r, c);

    printf("Secondary Diagonal Sum of Matrix: %d\n", sum);
}

void handleElementsSum()
{
    int r, c;
    int mat[10][10], sum;

    printf("Enter number of rows and columns of matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("Enter elements of matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    sum = matEleSum(mat, r, c);

    printf("Sum of all elements in matrix: %d\n", sum);
}

void handleMaximum()
{
    int mat[10][10], r, c, max;
    printf("Enter number of rows and columns of the matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("Enter elements of the matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    max = matGreatEle(mat, r, c);

    printf("Greatest element in the matrix: %d\n", max);
}

void handleMinimum()
{
    int mat[10][10], r, c, min;
    printf("Enter number of rows and columns of the matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("Enter elements of the matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    min = matSmallEle(mat, r, c);

    printf("Smallest element in the matrix: %d\n", min);
}

void handlePositiveCount()
{
    int mat[10][10], r, c, count;
    printf("Enter number of rows and columns of matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("Enter elements of the matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    count = posCount(mat, r, c);

    printf("The number of positive elements in the matrix: %d\n", count);
}

void handleNegativeCount()
{
    int mat[10][10], r, c, count;
    printf("Enter number of rows and columns of matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("Enter elements of the matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    count = negCount(mat, r, c);

    printf("The number of negative elements in the matrix: %d\n", count);
}

void handleZeroCount()
{
    int mat[10][10], r, c, count;
    printf("Enter number of rows and columns of matrix:\n");
    scanf("%d %d", &r, &c);

    printf("\n");

    if (r <= 0 || r > 10 || c <= 0 || c > 10)
    {
        printf("Invalid matrix dimensions! Rows and columns must be between 1 and 10.\n");
        return;
    }

    printf("Enter elements of the matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    count = zeroCount(mat, r, c);

    printf("The number of zeros in the matrix: %d\n", count);
}

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
            handleAddition();
            break;
        }
        case 2:
        {
            handleSubtraction();
            break;
        }
        case 3:
        {
            handleMultiplication();
            break;
        }
        case 4:
        {
            handleTranspose();
            break;
        }
        case 5:
        {
            handleRowSum();
            break;
        }
        case 6:
        {
            handleColSum();
            break;
        }
        case 7:
        {
            handleTrace();
            break;
        }
        case 8:
        {
            handleSecondaryDiagonal();
            break;
        }
        case 9:
        {
            handleElementsSum();
            break;
        }
        case 10:
        {
            handleMaximum();
            break;
        }
        case 11:
        {
            handleMinimum();
            break;
        }
        case 12:
        {
            handlePositiveCount();
            break;
        }
        case 13:
        {
            handleNegativeCount();
            break;
        }
        case 14:
        {
            handleZeroCount();
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
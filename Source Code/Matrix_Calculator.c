// An Advanced Matrix Calculator Program for Mini Project
#include <stdio.h>

/* **************************************** FUNCTION PROTOTYPES **************************************** */

/* Helper Functions */

void inputMatrix(int mat[10][10], int r, int c);
void displayMatrix(int mat[10][10], int r, int c);
void initialize2DMatrix(int mat[10][10], int r, int c);
void printMainMenu();
void printPhase1Menu();
void printPhase2Menu();
void printPhase3Menu();

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

// Phase 3
int identityMatrix(int mat[10][10], int r);

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

// Phase 3
void handleIdentityMatrix();
void handleSymmetricMatrix();
void handleUpperTriMatrix();
void handleLowerTriMatrix();
void handleDiagonalMatrix();
void handleSparseMatrix();

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

void initialize2DMatrix(int mat[10][10], int r, int c) // A method to initialze a matrix to a null matrix
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

void printMainMenu() // A method to print the Main Menu
{
    printf("========================================\n");
    printf("|      ADVANCED MATRIX CALCULATOR      |\n");
    printf("========================================\n");
    printf("\n");
    printf("1. Core Calculator Foundation\n");
    printf("2. Matrix Analysis Operations\n");
    printf("3. Matrix Property Checker\n");
    printf("4. Determinants and Classical Linear Algebra\n");
    printf("5. Matrix Transformations\n");
    printf("6. Row Operations and Gaussian Elimination\n");
    printf("7. Matrix Searching & Statistics\n");
    printf("8. Exit\n\n");
}

void printPhase1Menu() // A method to print Phase 1 Menu
{
    printf("==========CORE CALCULATOR FOUNDATION==========\n\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    printf("4. Transpose of a Matrix\n");
    printf("5. Exit Phase 1 Menu\n\n");
}

void printPhase2Menu() // A method to print Phase 2 Menu
{
    printf("==========MATRIX ANALYSIS OPERATIONS==========\n\n");
    printf("1. Row Sum\n");
    printf("2. Column Sum\n");
    printf("3. Main Diagonal Sum (Trace)\n");
    printf("4. Secondary Diagonal Sum\n");
    printf("5. Sum of All Elements\n");
    printf("6. Maximum Element in Matrix\n");
    printf("7. Minimum Element in Matrix\n");
    printf("8. Count Positive Elements in Matrix\n");
    printf("9. Count Negative Elements in Matrix\n");
    printf("10. Count Zeros in Matrix\n");
    printf("11. Exit Phase 2 Menu\n\n");
}

void printPhase3Menu() // A method to print Phase 3 Menu
{
    printf("==========MATRIX PROPERTY CHECKER==========\n\n");
    printf("1. Identity Matrix Check\n");
    printf("2. Symmetric Matrix Check\n");
    printf("3. Upper Triangular Matrix Check\n");
    printf("4. Lower Triangular Matrix Check\n");
    printf("5. Diagonal Matrix Check\n");
    printf("6. Sparse Matrix Check\n");
    printf("7. Exit Phase 3 Menu\n\n");
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

int posCount(int mat[10][10], int r, int c) // A method to count total positive elements in matrix
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

int negCount(int mat[10][10], int r, int c) // A method to count total negative elements in matrix
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

int zeroCount(int mat[10][10], int r, int c) // A method to count total zeros in matrix
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

// Phase 3
// Matrix must strictly be a square matrix (r==c)
int identityMatrix(int mat[10][10], int r) // A method to check identity matrix
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            if (i == j)
            {
                if (mat[i][j] != 1)
                {
                    return 0;
                }
            }
            else
            {
                if (mat[i][j] != 0)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
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

// Phase 3
void handleIdentityMatrix()
{
    int mat[10][10], r, c, check;
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
        printf("Invalid input!! Rows and columns must be equal to implement this feature!\n");
        return;
    }

    printf("Enter elements of the matrix:\n");
    inputMatrix(mat, r, c);

    printf("\n");

    identityMatrix(mat, r);

    if (identityMatrix(mat, r))
    {
        printf("Entered matrix is an Identity Matrix\n");
    }
    else
    {
        printf("Entered matrix is not an Identity Matrix\n");
    }
}

int main()
{
    int mainChoice, subChoice;
    printf("\n");

    while (1)
    {
        printMainMenu();

        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        printf("\n");

        switch (mainChoice)
        {
        case 1:

            while (1)
            {
                printPhase1Menu();

                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                printf("\n");

                switch (subChoice)
                {
                case 1:
                    handleAddition();
                    printf("\n");
                    break;

                case 2:
                    handleSubtraction();
                    printf("\n");
                    break;

                case 3:
                    handleMultiplication();
                    printf("\n");
                    break;

                case 4:
                    handleTranspose();
                    printf("\n");
                    break;

                case 5:
                    printf("Exiting Phase 1 Menu..\n\n");
                    break;

                default:
                    printf("Invalid Input!! Please choose from 1-5\n\n");
                }

                if (subChoice == 5)
                {
                    break;
                }
            }

            break;

        case 2:

            while (1)
            {
                printPhase2Menu();

                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                printf("\n");

                switch (subChoice)
                {
                case 1:
                    handleRowSum();
                    printf("\n");
                    break;

                case 2:
                    handleColSum();
                    printf("\n");
                    break;

                case 3:
                    handleTrace();
                    printf("\n");
                    break;

                case 4:
                    handleSecondaryDiagonal();
                    printf("\n");
                    break;

                case 5:
                    handleElementsSum();
                    printf("\n");
                    break;

                case 6:
                    handleMaximum();
                    printf("\n");
                    break;

                case 7:
                    handleMinimum();
                    printf("\n");
                    break;

                case 8:
                    handlePositiveCount();
                    printf("\n");
                    break;

                case 9:
                    handleNegativeCount();
                    printf("\n");
                    break;

                case 10:
                    handleZeroCount();
                    printf("\n");
                    break;

                case 11:
                    printf("Exiting Phase 2 Menu..\n\n");
                    break;

                default:
                    printf("Invalid Input!! Please choose from 1-11\n\n");
                }

                if (subChoice == 11)
                {
                    break;
                }
            }

            break;

        case 3:

            while (1)
            {
                printPhase3Menu();

                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                printf("\n");

                switch (subChoice)
                {
                case 1:
                    handleIdentityMatrix();
                    printf("\n");
                    break;

                case 7:
                    printf("Exiting Phase 3 Menu..\n\n");
                    break;

                default:
                    printf("Invalid Input!! Please choose from 1-7\n\n");
                }

                if (subChoice == 7)
                {
                    break;
                }
            }

            break;

        case 4:

            // Phase 4 Features
            break;

        case 5:

            // Phase 5 Features
            break;

        case 6:

            // Phase 6 Features
            break;

        case 7:

            // Phase 7 Features
            break;

        case 8:

            printf("Thank you for using the Matrix Calculator!!\n");
            printf("Hope you had a good time!!\n");
            printf("Visit soon!!\n");
            printf("Program Ends :D !!\n\n");
            break;

        default:

            printf("Invalid Input!! Please choose from 1-8\n\n");
        }

        if (mainChoice == 8)
        {
            break;
        }
    }

    return 0;
}
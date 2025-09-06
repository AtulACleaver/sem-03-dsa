// WAP to transpose sparse matrix
// The transpose of a sparse matrix is obtained by swapping its rows and columns.

#include <stdio.h>

int main()
{
    int matrix[6][5] = {
        {1, 0, 0, 0, 2},
        {0, 3, 0, 6, 0},
        {4, 0, 0, 0, 0},
        {0, 0, 7, 8, 0},
        {9, 0, 0, 0, 0},
        {0, 0, 10, 0, 0}};

    int r = 6, c = 5, count = 0;

    int alt_matrix[(r * c) + 1][3];

    alt_matrix[0][0] = r;
    alt_matrix[0][1] = c;

    int a = 1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
                alt_matrix[a][0] = i;
                alt_matrix[a][1] = j;
                alt_matrix[a][2] = matrix[i][j];
                a++;
            }
        }
    }

    alt_matrix[0][2] = count;

    // Print alternate matrix
    for (int i = 0; i < count + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", alt_matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose Matrix
    for (int i = 1; i < count + 1; i++)
    {
        int temp = alt_matrix[i][0];
        alt_matrix[i][0] = alt_matrix[i][1];
        alt_matrix[i][1] = temp;
    }

    printf("\n\n\n");

    // Print alternate matrix
    for (int i = 0; i < count + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", alt_matrix[i][j]);
        }
        printf("\n");
    }

    // Sort the alt_matrix
    for (int i = 1; i < count; i++)
    {
        for (int j = i + 1; j < count + 1; j++)
        {
            if (alt_matrix[i][0] > alt_matrix[j][0] ||
                (alt_matrix[i][0] == alt_matrix[j][0] && alt_matrix[i][1] > alt_matrix[j][1]))
            {
                // Swap rows
                int temp[3];
                for (int k = 0; k < 3; k++)
                {
                    temp[k] = alt_matrix[i][k];
                    alt_matrix[i][k] = alt_matrix[j][k];
                    alt_matrix[j][k] = temp[k];
                }
            }
        }
    }

    printf("\n\n\n");

    // Print sorted alternate matrix
    for (int i = 0; i < count + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", alt_matrix[i][j]);
        }
        printf("\n");
    }

    // Convert back to sparse matrix
    int sparse_matrix[6][5] = {0};

    for (int i = 1; i < count + 1; i++)
    {
        int row = alt_matrix[i][0];
        int col = alt_matrix[i][1];
        int value = alt_matrix[i][2];
        sparse_matrix[row][col] = value;
    }

    printf("\n\n\n");

    // Print sparse matrix
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", sparse_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


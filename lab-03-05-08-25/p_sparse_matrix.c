// WAP to convert the sparse array -> alternate representation

#include <stdio.h>

int main(){
    int matrix[6][5] = {
        {1, 0, 0, 0, 2},
        {0, 3, 0, 6, 0},
        {4, 0, 0, 0, 0},
        {0, 0, 7, 8, 0},
        {9, 0, 0, 0, 0},
        {0, 0, 10, 0, 0}
    };

    int r = 6, c = 5, count = 0;

    int alt_matrix[(r*c) + 1][3];

    alt_matrix[0][0] = r;
    alt_matrix[0][1] = c;

    int a = 1;

    for(int i = 0; i<r; i++){
        for (int j = 0; j < c; j++)
        {
            if(matrix[i][j] != 0){
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
    for (int i = 0; i < count+1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", alt_matrix[i][j]);
        }
        printf("\n");
    }
    

}
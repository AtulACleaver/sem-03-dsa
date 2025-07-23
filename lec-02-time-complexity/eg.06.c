// time-complexity problem

#include <stdio.h>

int main(){

    int n = 2;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j > i; j--){
            for(int k=n; k>j; k--){
                printf("i: %d, j: %d, k: %d\n", i, j, k);
            }
        }
    }

    return 0;
}


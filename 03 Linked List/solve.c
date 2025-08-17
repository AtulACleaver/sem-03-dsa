// List of all binary numbers divisible by 3

#include <stdio.h>

int main(){
    for(int i = 0; i < 100; i++){
        if(i % 3 == 0){
            // Print the number in binary
            int n = i;
            char bin[32];
            int idx = 0;
            if(n == 0) {
                printf("0\n");
                continue;
            }
            while(n > 0){
                bin[idx++] = (n % 2) + '0';
                n /= 2;
            }
            // Print in reverse order
            for(int j = idx - 1; j >= 0; j--){
                printf("%c", bin[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
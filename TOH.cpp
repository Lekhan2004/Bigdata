#include <stdio.h>

void TOH(int n, char S, char D, char Au) {
    if (n == 1) {
        printf("Move 1 from %c to %c\n", S, D);
        return;
    }
    TOH(n - 1, S, Au, D);
    printf("Move %d from  %c to %c\n", n, S, D);
    TOH(n - 1, Au, D, S);
}

int main() {
    int n = 3; 
    TOH(n, 'A', 'C', 'B');  
    return 0;
}


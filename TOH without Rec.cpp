#include <stdio.h>
 struct Tower{
    int n;
    char S, D, Au;
} ;
void TOH(int n, char S, char D, char Au) {
    Tower stack[n];
    int top = -1;
    Tower T1 = { n, S, D, Au };
    stack[++top] = T1;
    while (top >= 0) {
        Tower t = stack[top--];
        n = t.n;
        S = t.S;
        D = t.D;
        Au = t.Au;
        if (n == 1) {
            printf("Move disk 1 from rod %c to rod %c\n", S, D);
        } else {
            Tower T3 = { n - 1, Au, D, S };
            stack[++top] = T3;
            Tower T2 = { 1, S, D, Au };
            stack[++top] = T2;
            Tower T4 = { n - 1, S, Au, D };
            stack[++top] = T4;
        } } 
}
int main() {
    int n = 3;  
    TOH(n, 'A', 'C', 'B');  
    return 0;
}

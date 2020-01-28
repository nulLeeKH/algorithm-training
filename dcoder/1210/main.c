#include <stdio.h>

void hanoi(int n, char a, char b, char c);

int main() {
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
}

void hanoi(int n, char a, char b, char c) {
    if (n==1) printf("1 : %c -> %c\n", a, c);
    else {
        hanoi(n-1, a, c, b);
        printf("%d : %c -> %c\n", n, a, c);
        hanoi(n-1, b, a, c);
    }
}
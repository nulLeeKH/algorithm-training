#include <stdio.h>

int land(int i, int j, int k);

int a[1000][1000]={{-1,},}, b=0, c, d, e[9] = {0,};

int main() {
    int i, j, n;
    scanf("%d", &n);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (a[i][j] != -1) {
                c = 0;
                d=land(i, j, a[i][j]);
                if (c >= 3) e[d-1]=1;
            }
        }
    }

    for (i=0 ; i<9 ; i++) {
        b+=e[i];
    }

    printf("%d", b);
    return 0;
}

int land(int i, int j, int k) {
    if (a[i][j] == k) {
        c++;
        a[i][j] = -1;
        land(i-1, j, k);
        land(i, j-1, k);
        land(i, j+1, k);
        land(i+1, j, k);
    }
    return k;
}
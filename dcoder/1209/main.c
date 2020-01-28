#include <stdio.h>

int check();

int c[100][100], a, b;

int main()
{
    int i, j, d=0;
    scanf("%d %d", &a, &b);

    for (i=0 ; i<a ; i++) {
        for (j=0 ; j<b ; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    while(1) {
        if (check() == 1) d++;
        else {
            printf("%d", d);
            return 0;
        }

        for (i=0 ; i<a ; i++) {
            j=0;
            while (c[i][j]==0 && j<b) {
                j++;
            }
            if (j<b) c[i][j] = 2;
        }
        for (i=0 ; i<a ; i++) {
            j=b-1;
            while (c[i][j]==0 && j>=0) {
                j--;
            }
            if (j>=0) c[i][j] = 2;
        }
        for (i=0 ; i<b ; i++) {
            j=0;
            while (c[j][i]==0 && j<a) {
                j++;
            }
            if (j<a) c[j][i] = 2;
        }
        for (i=0 ; i<b ; i++) {
            j=a-1;
            while (c[j][i]==0 && j>=0) {
                j--;
            }
            if (j>=0) c[j][i] = 2;
        }

        for (i=0 ; i<a ; i++) {
            for (j=0 ; j<b ; j++) {
                if (c[i][j] == 2) c[i][j]=0;
            }
        }
    }
}


int check() {
    int i, j;
    for (i=0 ; i<a ; i++) {
        for (j=0 ; j<b ; j++) {
            if (c[i][j] == 1) return 1;
        }
    }
    return 0;
}

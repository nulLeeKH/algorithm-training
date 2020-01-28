#include <stdio.h>

int main()
{
    int m, n, r[200], t, i, j, k;
    scanf("%d", &m);

    for (i=0 ; i<m ; i++) {
        scanf("%d", &n);
        for (j=0 ; j<n ; j++) {
            scanf("%d", &r[j]);
            r[j]--;
        }
        for (j=0 ; j<n ; j++) {
            k=j; t=1;
            while (j!=r[k]) {
                t++;
                k = r[k];
            }
            printf("%d ", t);
        }
        printf("\n");
    }
}

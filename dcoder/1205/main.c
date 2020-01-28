#include <stdio.h>

int main()
{
    int a, b, c[100], d, e[100]={0,}, f, g, i, j, k;

    scanf("%d", &a);

    for(i=0 ; i<a ; i++) {
        scanf("%d", &b);

        d=0; g=1;

        for (j=0 ; j<b ; j++) {
            scanf("%d", &c[j]);
        }

        g--;
        for (j=0 ; j<b ; j++) {
            if (c[j] != -1) {
                g++;
                break;
            }
        }

        while (g) {
            f=0; d++;

            for (j=0 ; j<b ; j++) {
                if (c[j] != -1) {
                    f++;
                    e[0] = c[j];
                    c[j]=-1;
                    break;
                }
            }

            for (j=0 ; j<b ; j++) {
                if (c[j] != -1) {
                    for (k=0 ; k<f ; k++) {
                        if (-1<=c[j]-e[k] && c[j]-e[k]<=1) {
                            break;
                        }
                    }
                    if (!(-1<=c[j]-e[k] && c[j]-e[k]<=1)) {
                        e[++f]=c[j];
                        c[j]=-1;
                    }
                }
            }

            g--;
            for (j=0 ; j<b ; j++) {
                if (c[j] != -1) {
                    g++;
                    break;
                }
            }
        }

        printf("%d\n", d);
    }
}
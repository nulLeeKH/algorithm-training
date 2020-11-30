/*
MIT License

Copyright (c) 2020 Lee Kyung-ha <i_am@nulleekh.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
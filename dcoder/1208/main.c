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
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

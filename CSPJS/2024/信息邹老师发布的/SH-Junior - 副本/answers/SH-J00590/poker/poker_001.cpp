#include <bits/stdc++.h>
using namespace std;
int main (void)
{
    freopen ("poker.in", "r", stdin);
    freopen ("poker.out", "w", stdout);
    int n, i, k, o; bool ex [52];
    scanf ("%d", &n);
    for (i=0; i<52; i++) ex [i] = 0;
    for (i=0; i<n; i++)
    {
        char s [5];
        scanf ("%s", s);
        if (s [0] == 'S') k = 0;
        else if (s [0] == 'H') k = 1;
        else if (s [0] == 'D') k = 2;
        else k = 3;
        if (s [1] == 'A') o = 0;
        else if (s [1] == 'T') o = 9;
        else if (s [1] == 'J') o = 10;
        else if (s [1] == 'Q') o = 11;
        else if (s [1] == 'K') o = 12;
        else o = s [1] - '1';
        ex [k * 13 + o] = 1;
    }
    int cnt = 0;
    for (i=0; i<52; i++) if (ex [i] == 0) cnt++;
    printf ("%d\n", cnt);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main (void)
{
    freopen ("sticks.in", "r", stdin);
    freopen ("sticks.out", "w", stdout);
    int t;
    scanf ("%d", &t);
    while (t--)
    {
        int n, k, i;
        scanf ("%d", &n);
        k = n % 7; n /= 7;
        if (n == 0)
        {
            if (k == 1) puts ("-1");
            else if (k == 2) puts ("1");
            else if (k == 3) puts ("7");
            else if (k == 4) puts ("4");
            else if (k == 5) puts ("2");
            else if (k == 6) puts ("6");
        }
        else
        {
            if (k == 0) for (i=0; i<n; i++) putchar ('8');
            else if (k == 1)
            {
                putchar ('1'); putchar ('0');
                for (i=1; i<n; i++) putchar ('8');
            }
            else if (k == 2)
            {
                putchar ('1');
                for (i=0; i<n; i++) putchar ('8');
            }
            else if (k == 3)
            {
                if (n == 1)
                {
                    putchar ('2');
                    putchar ('2');
                }
                else
                {
                    putchar ('2'); putchar ('0'); putchar ('0');
                    for (i=2; i<n; i++) putchar ('8');
                }
            }
            else if (k == 4)
            {
                putchar ('2'); putchar ('0');
                for (i=1; i<n; i++) putchar ('8');
            }
            else if (k == 5)
            {
                putchar ('2');
                for (i=0; i<n; i++) putchar ('8');
            }
            else if (k == 6)
            {
                putchar ('8'); putchar ('0');
                for (i=1; i<n; i++) putchar ('8');
            }
            putchar ('\n');
        }
    }
}

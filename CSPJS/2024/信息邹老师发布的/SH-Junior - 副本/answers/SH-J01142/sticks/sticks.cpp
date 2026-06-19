#include <bits/stdc++.h>
using namespace std;
const int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string s;
void dfs(int no, int len, int sticks)
{
    if (no > len)
        return;
    if (no == len)
    {
        for (int i = ((no == 1) ? 1 : 0); i <= 9; ++i)
        {
            if (c[i] == sticks)
            {
                s += i + '0';
                break;
            }
        }
        return;
    }
    int i;
    for (i = ((no == 1) ? 1 : 0); i <= 9; ++i)
    {
        if (1.0*(sticks - c[i]) / (len - no) <= 7.0)
        {
            s += i + '0';
            break;
        }
    }
    dfs(no + 1, len, sticks - c[i]);
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        s = "";
        scanf("%d", &n);
        int minlen = ceil(n / 7.0); // 最短的字符串长度
        dfs(1, minlen, n);
        if (s == "")
            cout << -1 << endl;
        else
            cout << s << endl;
    }
    return 0;
}
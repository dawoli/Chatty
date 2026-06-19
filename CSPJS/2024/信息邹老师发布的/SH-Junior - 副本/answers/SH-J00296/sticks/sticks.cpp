#include <iostream>
#include <cstring>
using namespace std;
int sticks[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;
void sol1(int n)
{
    if (n < 2)
    {
        cout << -1 << endl;
        return;
    }
    else if (n == 2)
    {
        cout << 1 << endl;
        return;
    }
    else if (n == 3)
    {
        cout << 7 << endl;
        return;
    }
    else if (n == 4)
    {
        cout << 4 << endl;
        return;
    }
    else if (n == 5)
    {
        cout << 2 << endl;
        return;
    }
    else if (n == 6)
    {
        cout << 6 << endl;
        return;
    }
    else if (n % 7 == 0)
    {
        for (int i = 0; i < n / 7; i ++)
        {
            cout << 8;
        }
        cout << endl;
        return;
    }
    for (int i = 1; ; i ++)
    {
        if (i >= 100000)
        {
            cout << -1 << endl;
            return;
        }
        char s[10];
        sprintf(s, "%d", i);
        int sc = 0;
        for (int i = 0; i < strlen(s); i ++)
        {
            sc += sticks[s[i] - '0'];
        }
        if (sc == n)
        {
            cout << i << endl;
            return;
        }
    }
}

int calc_sticks(int x1)
{
	char x[100000];
	sprintf(x, "%d", x1);
    int sum = 0;
    for (int i = 0; i < strlen(x); i ++)
    {
        sum += sticks[x[i] - '0'];
    }
    return sum;
}
void dfs(int d, int num)
{
    int cs = calc_sticks(num);
    if (cs == n)
    {
        cout << num << endl;
        return;
    }
    else if (cs > n)
    {
        return;
    }
    int start = 0;
    if (d == 1)
    {
        start ++;
    }
    for (int i = start; i <= 9; i ++)
    {
        dfs(d + 1, num * 10 + i);
    }
}

void sol2(int n)
{
    if (n % 7 == 0)
    {
        for (int i = 0; i < n / 7; i ++)
        {
            cout << 8;
        }
        cout << endl;
        return;
    }
    else if (n % 7 == 1 && n != 1)
    {
        dfs(0, n);
    }
    else
    {
        sol1(n);
    }
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t --)
    {
        cin >> n;
        sol2(n);
    }
    return 0;
}

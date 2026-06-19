#include <bits/stdc++.h>
using namespace std;
int id[1007], num[1007];
bool f[17][27];
void init(string s)
{
    if (isdigit(s[1]))
        f[id[s[0]]][s[1] - '0'] = 1;
    else
        f[id[s[0]]][num[s[1]]] = 1;
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    id['D'] = 1;
    id['C'] = 2;
    id['H'] = 3;
    id['S'] = 4;
    num['A'] = 1;
    num['T'] = 10;
    num['J'] = 11;
    num['Q'] = 12;
    num['K'] = 13;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        init(s);
    }
    int ct = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            ct += !f[i][j];
    cout << ct;
    return 0;
}
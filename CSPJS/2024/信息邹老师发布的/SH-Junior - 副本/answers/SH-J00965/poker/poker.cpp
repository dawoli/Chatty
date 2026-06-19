#include <bits/stdc++.h>
using namespace std;

string s[60];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1,s + n + 1);
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (s[i] != s[i - 1]) cnt++;
    }
    cout << 52 - cnt << endl;
    return 0;
}

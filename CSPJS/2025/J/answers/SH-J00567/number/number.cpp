#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdio>
#include <array>

using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    char c;
    array<int, 10> cnt;
    fill(cnt.begin(), cnt.end(), 0);
    
    while (cin.get(c))
    {
        if (isdigit(c))
        {
            ++cnt[c - '0'];
        }
    }
    
    for (int i = 9; i >= 0; --i)
    {
        for (int j = 1; j <= cnt[i]; ++j)
        {
            cout << i;
        }
    }

    cout << endl;

    return 0;
}

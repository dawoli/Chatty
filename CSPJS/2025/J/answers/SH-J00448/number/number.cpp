#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int a[1000010];
int a_index = 1;

bool cmp(int x, int y)
{
    return x > y;
}

signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a[a_index++] = s[i] - '0';
        }
    }
    a_index--;

    sort(a+1, a+1+a_index, cmp);

    for (int i = 1; i <= a_index; i++)
    {
        cout << a[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
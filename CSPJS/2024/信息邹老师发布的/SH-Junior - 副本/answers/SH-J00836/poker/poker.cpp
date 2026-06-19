#include<iostream>
#include<cstdio>
using namespace std;

bool f[300][300];

int main()
{
    freopen("poker.in" , "r" , stdin);
    freopen("poker.out" , "w" , stdout);
    int n , cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char col , num;
        cin >> col >> num;
        if (!f[col][num])
        {
            cnt++;
            f[col][num] = true;
        }
    }
    cout << 52 - cnt << endl;
    return 0;
}

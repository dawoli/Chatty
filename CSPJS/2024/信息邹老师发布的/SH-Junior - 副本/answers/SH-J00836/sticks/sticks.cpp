#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[60] , cnt[] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};

int b[] = {-1 , -1 , 1 , 7 , 4 , 2 , 6 , 8 , 10 , 18 , 22 , 20 , 28 , 68 , 88 , 108 , 188 , 200 , 208 , 288 , 688 , 888 , 1088 , 1888 , 2008 , 2088 , 2888 , 6888 , 8888 , 10888 , 18888 , 20088 , 20888 , 28888 , 68888 , 88888 , 108888 , 188888 , 200888 , 208888 , 288888 , 688888 , 888888 , 1088888 , 1888888 , 2008888 , 2088888 , 2888888 , 6888888 , 8888888 , 10888888};

int get(int x)
{
    int ans = 0;
    while (x)
    {
        ans += cnt[x % 10];
        x /= 10;
    }
    return ans;
}

int main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n <= 50)
        {
            cout << b[n] << endl;
            continue;
        }
        else if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        else if (n % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i <= (n - 8) / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else
        {
            int x = n % 7 + 14;
            cout << b[x];
            for (int i = 1; i <= (n - x) / 7; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}

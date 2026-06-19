#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n <= 7)
        {
            if (n == 1) cout << -1 << endl;
            if (n == 2) cout << 1 << endl;
            if (n == 3) cout << 7 << endl;
            if (n == 4) cout << 4 << endl;
            if (n == 5) cout << 2 << endl;
            if (n == 6) cout << 6 << endl;
            if (n == 7) cout << 8 << endl;
        }
        else if (n == 10) cout << 22 << endl;
        else if (n % 7 == 0)
        {
            int t = n / 7;
            for (int i = 1; i <= t; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 1)
        {
            int t = n / 7 - 1;
            cout << 10;
            for (int i = 1; i <= t; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 2)
        {
            int t = n / 7;
            cout << 1;
            for (int i = 1; i <= t; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 3)
        {
            int t = n / 7 - 2;
            cout << 200;
            for (int i = 1; i <= t; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 4)
        {
            int t = n / 7 - 1;
            cout << 20;
            for (int i = 1; i <= t; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 5)
        {
            int t = n / 7;
            cout << 2;
            for (int i = 1; i <= t; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
        else if (n % 7 == 6)
        {
            int t = n / 7;
            cout << 6;
            for (int i = 1; i <= t; i++)
            {
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}

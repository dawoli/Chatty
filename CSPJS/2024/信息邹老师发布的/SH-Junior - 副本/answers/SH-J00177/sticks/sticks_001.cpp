#include <iostream>
#include <cstdio>
using namespace std;

const int a[15] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88},b[7] = {88,108,188,200,208,288,688};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n <= 14) cout << a[n];
        else
        {
            n -= 14;
            cout << b[n % 7];
            for(int i = 1;i <= n / 7;i++) cout << 8;
        }
        cout << endl;
    }
    return 0;
}

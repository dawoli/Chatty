#include <iostream>

using namespace std;

const int maxn = 1e6 + 7;

int a[10] = {6,2,5,5,4,5,6,3,7,6};


long long b[maxn];

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    for(long long i = 1;i <= maxn;i++)// pin chu i yao b[i] ge mubang
    {
        long long t = i;
        long long cnt = 0;
        while(t >= 10)
        {
            int d = t % 10;
            cnt += a[d];
            t /= 10;
        }
        cnt += a[t];
        b[i] = cnt;
    }
    while(T--)
    {
        long long n;
        cin >> n;
        if(n <= 1) cout << -1 <<endl;
        else
        {
            for(long long i = 1;i <= maxn;i++)
            {
                if(b[i] == n)
                {
                    cout << i <<endl;
                    break;
                }
            }
        }
    }
    return 0;
}

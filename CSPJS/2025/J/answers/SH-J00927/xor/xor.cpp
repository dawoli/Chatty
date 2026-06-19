#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k == 0)
    {
        int c1 = 0,cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) {
                    cnt++;
                    c1 = 0;
            }
            else
            {
                c1++;
                if (a[i] == a[i - 1])
                {
                    cnt++;
                    c1 = 0;
                }
            }
        }
        cout << cnt;
        return 0;
    }
    if (k == 1)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
                cnt++;
            else if (a[i] != a[i - 1]) cnt++;
        }
        cout << cnt;
    }
    return 0;
}

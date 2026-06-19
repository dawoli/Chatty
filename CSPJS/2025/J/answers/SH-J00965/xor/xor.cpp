#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],c,sum;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        int s=a[i];
        if (a[i]==k)
        {
            c==i;
            sum++;
            continue;
        }
        for (int j=i+1;j<=n;j++)
        {
            s^=a[j];
            if (s==k)
            {
                c=j;
                sum++;
                i=j;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}

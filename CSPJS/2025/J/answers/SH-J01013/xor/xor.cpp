#include<iostream>
#include<cstdio>
using namespace std;

long long n,k,ans;
long long a[500005];
long long cnt[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]++;
    }
    if(k == 0)
    {
        ans = cnt[0] + cnt[1]/2;
    }
    else if(k == 1)
    {
        ans = cnt[1];
    }
    cout << ans;
    return 0;
}

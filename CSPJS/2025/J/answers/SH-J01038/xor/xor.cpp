#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long s[500005];
long long n,k;
long long sum;
long long r,l;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    long long cnt = 0;
    cin>>n>>k;
    for(long long i = 1;i <= n;i++) cin>>a[i];
    for(l = 1;l <= n;l++)
    {
        for(r = l;r <= n;r++)

        {
            sum=a[l];
            for(long long i = l+1;i <= r;i++) sum^=a[i];
        }
        if(sum==k)
        {
            bool flag=true;
            for(long long i = l;i <= r;i++)
                if(s[i]==1) flag = false;
            if(flag = true)
            {
                cnt++;
                for(long long i = l;i <= r;i++) s[i]=1;
                sum=0;
            }
        }
    }
    cout<<cnt;
    return 0;
}

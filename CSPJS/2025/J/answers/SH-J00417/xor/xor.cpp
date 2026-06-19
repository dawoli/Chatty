#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k;
long long cnt;
int a[N];
int v[N];
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        int xor_sum=0;
        for (int j=i;j>=1;j--)
        {
            xor_sum=xor_sum xor a[j];
            if (xor_sum==k)
            {
                v[i]=j;
                break;
            }
        }
    }
    int maxr=0;
    for (int i=1;i<=n;i++)
    {
        if (v[i]>maxr)
        {
            cnt++;
            maxr=i;
        }   
    }
    printf("%lld\n",cnt);
    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    int a[500005]={},n,k,cnt=0;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int as=0;
    int l=1,r=1;
    while(l<=r&&r<=n)
    {
        as^=a[r];
        if(as==k)
        {
            r++;
            l=r;
            cnt++;
            as=0;
        }
        else r++;
    }
    cout<<cnt;
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    int a[5005]={},n,cnt=0;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                int z=a[i]+a[j]+a[k];
                int maxi=max(a[i],max(a[j],a[k]));
                if(z>2*maxi) cnt++;
                for(int l=k+1;l<=n;l++)
                {
                    z=a[i]+a[j]+a[k]+a[l];
                    maxi=max(max(a[j],a[k]),max(a[i],a[l]));
                    if(z>2*maxi) cnt++;

                    for(int m=l+1;l<=n;l++)
                    {
                        z=a[i]+a[j]+a[k]+a[l]+a[m];
                        maxi=max(max(a[i],max(a[j],a[k])),max(a[l],a[m]));
                        if(z>2*maxi) cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}

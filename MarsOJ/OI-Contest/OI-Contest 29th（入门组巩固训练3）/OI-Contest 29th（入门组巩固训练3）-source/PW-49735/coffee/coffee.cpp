#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T,d[10];
ll c;
int main()
{
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    scanf("%d",&T);
    string xx;
    while(T--)
    {
        c=0ll;
        memset(d,0,sizeof(d));
        ll ds,st;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=8;j++)
            {
                cin>>xx;
                if(xx=="math") d[i]++;
            }
        }
        scanf("%lld%lld",&ds,&st);
        ll x=ds/7;
        ll z=st;
        ll y=d[1]+d[2]+d[3]+d[4]+d[5];
        // for(int i=1;i<=5;i++) cout << d[i] << " ";
        // cout << endl;
        // cout << x << " " << y << "\n";
        c+=x*y;
        // cout << c << "\n";
        int f=ds-x*7;
        while(f--)
        {
            if(z==8) z=1;
            if(z>=1&&z<=5) c+=d[z];
            z++;
        }
        printf("%lld\n",c);
    }
    return 0;
}
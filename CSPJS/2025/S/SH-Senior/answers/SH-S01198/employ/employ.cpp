#include <iostream>
using namespace std;
char c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long mod=998244353;
    int n,m;
    cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]=='0')flag=1;
    }
    if(flag==0){
            long long mx=1;
            //3*4/2
        for(int i=1;i<=n;i++)
        {
            mx*=i;
            mx%=mod;

        }
        cout<<mx;
    }
    else
    {
        cout<<0;

    }
    return 0;
}

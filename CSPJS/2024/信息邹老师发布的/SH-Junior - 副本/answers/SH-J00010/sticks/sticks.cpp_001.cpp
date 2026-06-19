#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long T,n,x;
    cin>>T;
    for(long long t=1;t<=T;t++)
    {
        cin>>n;
        x=n/7;
        for(int i=1;i<=x;i++)
        {
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}

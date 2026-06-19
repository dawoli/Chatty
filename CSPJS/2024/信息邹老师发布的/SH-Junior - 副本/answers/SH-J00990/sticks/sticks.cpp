#include <bits/stdc++.h>
using namespace std;
int a[15]={6,2,5,5,4,5,6,3,7,6};
long long b[100005]={};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<8;
            }
        }
        else if(n%7==1)
        {
            if(n>=8)
            {
                cout<<10;
                n-=8;
                if(n>0)
                {
                    for(int i=1;i<=n/7;i++)
                    {
                        cout<<8;
                    }
                }
            }
            else
            {
                cout<<-1;
            }
        }
        cout<<endl;
    }
    return 0;
}

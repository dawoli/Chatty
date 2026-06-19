#include<bits/stdc++.h>
using namespace std;
long long T;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(long long t=0;t<T;t++)
    {
        int n;
        cin>>n;
        if(n%7==0&&n>7)
        {
            for(int i=0;i<n/7;i++)
            {
                cout<<8;
            }
        }
        else if(n%7==1&&n>7)
        {
            cout<<10;
            for(int i=0;i<n/7-1;i++)
            {
                cout<<8;
            }
        }
        else
        {
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}

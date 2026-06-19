#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int l;
    int a[20005]={};
}ship[20005];
int  b[20005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>ship[i].l;
            for(int j=1;j<=ship[i].l;j++)
            {
                cin>>ship[i].a[j];
                b[ship[i].a[j]]++;
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            if(k==200000)
            {
                if(b[1]!=0 && b[c]!=0)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                if((r+c)%k==0)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

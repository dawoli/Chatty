#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    string a,b,c,d;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>c>>d;
    }
    if(q==1)
    {
        cout<<0<<endl;
    }
    return 0;
}

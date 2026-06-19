#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int d[1000],c[1000],s[1000],h[1000],q=52;
    char a[10000];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a[0]=='D')
        {
            if(d[a[1]-'0']==0)
            {
                d[a[1]-'0']=1;
                q--;
            }
            continue;
        }
        if(a[0]=='C')
        {
            if(c[a[1]-'0']==0)
            {
                c[a[1]-'0']=1;
                q--;
            }
            continue;
        }
        if(a[0]=='S')
        {
            if(s[a[1]-'0']==0)
            {
                s[a[1]-'0']=1;
                q--;
            }
            continue;
        }
        if(a[0]=='H')
        {
            if(h[a[1]-'0']==0)
            {
                h[a[1]-'0']=1;
                q--;
            }
            continue;
        }
    }
    cout<<q;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
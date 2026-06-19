#include <bits/stdc++.h>
using namespace std;
int n,k,q;
int t;
int a[110][10010] = {};
bool check(int r,int c,int rd,int en,int la)
{
    if (rd == 1)
    {
        bool flag = false;
        for (int i=1;i<=n;i++)
        {
            if (a[i][1]==1)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout<<0<<endl;
            exit(0);
        }
    }
    else if (rd > r)
    {
        if (en!=c)
        {
            return 0;
        }
        else
        {
            cout<<1<<endl;
            exit(0);
        }
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            if (i == la)
            {
                continue;
            }
            else
            {
                for (int j=2;j<=k;j++)
                {
                    if (check(i,j,rd++,a[i][j],i) == 0)
                    {
                        continue;
                    }
                    else
                    {
                        cout<<1<<endl;
                    }
                }
            }
        }
        cout<<0<<endl;
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>k>>q;
        int m=0;
        for (int i=1;i<=n;i++)
        {
            int l;
            cin>>l;
            m = l;
            for (int j=1;j<=l;j++)
            {
                cin>>a[i][j];
            }
        }
        for (int i=1;i<=q;i++)
        {
            int c,r;
            cin>>c>>r;
            bool flag = false;
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    if (a[i][j] == c||a[i][j] == r)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }
            if (flag == false)
            {
                cout<<0<<endl;
            }
            else
            {
                check(r,c,1,0,1);
            }
        }
    }
    return 0;
}

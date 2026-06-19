#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
    string s1,s2;
};
Node s[200010];

bool cmp(Node x,Node y)
{
    return x.s1.size()<y.s1.size();
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i].s1 >> s[i].s2;
    }
    sort(s+1,s+n+1,cmp);
    string t1,t2;
    for(int i=1;i<=q;i++)
    {
        cin >> t1 >> t2;
        string t11=t1;
        int ans=0,x=0;
        for(int len=s[1].s1.size();len<=s[n].s1.size();len++)
        {
            x++;
            for(int l=0;l+len-1<t1.size();l++)
            {
                int r=l+len-1;
                bool fg=1;
                for(int i=l;i<=r;i++)
                {
                    if(t1[i]!=s[x].s1[i-l] || s[x].s2[i-l]!=t2[i])
                    {
                        fg=0;break;
                    }
                    t11[i]=s[x].s2[i-l];
                }
                if(fg && t11==t2) ans++;
                t11=t1;
            }
        }
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

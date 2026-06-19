#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

long long t,n,cha[100005];
struct node
{
    long long a,b,c,maxn,like;
}s[100005];

bool cmp1(node x,node y)
{
    return x.a > y.a;
}

int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        long long cnta=0,cntb=0,cntc=0,ans=0;
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> s[i].a >> s[i].b >> s[i].c;
            s[i].maxn = max({s[i].a,s[i].b,s[i].c});
            ans += s[i].maxn;
            if(s[i].maxn == s[i].a)
            {
                cnta ++;
                s[i].like = 1;
            }
            else if(s[i].maxn == s[i].b)
            {
                cntb ++;
                s[i].like = 2;
            }
            else
            {
                cntc ++;
                s[i].like = 3;
            }
        }
        if(cnta<=n/2 && cntb<=n/2 && cntc<=n/2)
        {
            cout << ans << endl;
        }
        else
        {
            if(s[1].b==0 && s[1].c==0)
            {
                ans = 0;
                sort(s+1,s+n+1,cmp1);
                for(int i=1;i<=n/2;i++)
                {
                    ans += s[i].a;
                }
                cout << ans << endl;
            }
            else if(s[1].c == 0)
            {
                if(cnta > cntb)
                {
                    for(int i=1;i<=n;i++)
                    {
                        if(s[i].like == 1)
                        {
                            cha[i] = abs(s[i].a - s[i].b);
                        }
                    }
                }
                else
                {
                    for(int i=1;i<=n;i++)
                    {
                        if(s[i].like == 2)
                        {
                            cha[i] = abs(s[i].b - s[i].a);
                        }
                    }
                }
                sort(cha+1,cha+n+1);
                for(int i=1;i<=abs(cnta-cntb)/2;i++)
                {
                    ans -= cha[i];
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}

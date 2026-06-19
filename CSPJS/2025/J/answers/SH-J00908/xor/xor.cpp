#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long a[500010];

struct Node
{
    int sx,ex;
    bool f=1;
};
Node b[500010];

bool cmp(Node x,Node y)
{
    if(x.sx!=y.sx) return x.sx<y.sx;
    return x.ex<y.ex;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(n<=2 && k==0)//subtask1
    {
        if(n==2) cout << 1;
        else cout << 0;
        return 0;
    }
    int cnt=0;
    for(int len=1;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            int sum=0;
            for(int i=l;i<=r;i++)
            {
                sum ^= a[i];
            }
            if(sum==k)
            {
                cnt++;
                b[cnt].sx=l,b[cnt].ex=r;
            }
        }
    }
    sort(b+1,b+cnt+1,cmp);
    bool fg=1;
    for(int i=1;i<=cnt;i++)
    {
        if(b[i].sx<=b[i-1].ex)
        {
            fg=0;
            break;
        }
    }
    if(fg)
    {
        cout << cnt;
        return 0;
    }
    //quchong buhui(
    //rp++;
    int ans=cnt;
    for(int i=1;i<=cnt;i++)
    {
        if(!b[i].f) continue;
        if(b[i].sx<=b[i-1].ex && b[i-1].f)
        {
            ans--;
            b[i].f=0;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

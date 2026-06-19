#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,k,a[500005];
int posnode =0;
int maxans = -1;
int vis[500005] = {};
long long xwith1(long long a,long long b)
{
    int a1[25] = {},b1[25] = {},c1[25] = {};
    int pos = 0,lena = 0,lenb = 0;
    while(a != 0)
    {
        a1[++pos] = a % 2;
        a/=2;
        lena++;
    }
    pos = 0;
    while(b != 0)
    {
        b1[++pos] = b % 2;
        b/=2;
        lenb++;
    }
    int anslen = max(lena,lenb);
    int anspos = 0;
    for(int i=anslen;i>=1;i--)
    {
        if(a1[i] == b1[i])
        {
            c1[++anspos] = 1;
        }
        else
        {
            c1[++anspos] = 0;
        }
    }
    long long  sum = 1;
    for(int i=1;i<=anspos-1;i++)
    {
        sum *= 2;
    }
    long long ans = 0;
    for(int i=1;i<=anspos;i++)
    {
        if(c1[i] == 1)
        {
            ans += sum;

        }
        sum /= 2;
    }
    return ans;
}
long long xor1(long long a,long long b)
{
    int a1[25] = {},b1[25] = {},c1[25] = {};
    if(a == 0)
    {
        return b-1;
    }
    if(b == 0)
    {
        return a-1;
    }
    if(a == 1)
    {
        return b+1;
    }
    if(b == 1)
    {
        return a+1;
    }
    int pos = 0,lena = 0,lenb = 0;
    while(a != 0)
    {
        a1[++pos] = a % 2;
        a/=2;
        lena++;
    }
    pos = 0;
    while(b != 0)
    {
        b1[++pos] = b % 2;
        b/=2;
        lenb++;
    }
    int anslen = min(lena,lenb);
    int anspos = 0;
    for(int i=anslen;i>=1;i--)
    {
        if(a1[i] == b1[i])
        {
            c1[++anspos] = 0;
        }
        else
        {
            c1[++anspos] = 1;
        }
    }
    long long  sum = 1;
    for(int i=1;i<=anspos-1;i++)
    {
        sum *= 2;
    }
    long long ans = 0;
    for(int i=1;i<=anspos;i++)
    {
        if(c1[i] == 1)
        {
            ans += sum;

        }
        sum /= 2;
    }
    return ans;
}
struct node
{
    int l,r;
}pairk[500005];

void dfs(int ans,int step)
{
    if(step == posnode + 1)
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[i]>1)
                return;
        }
        maxans = max(maxans,ans);
        return;
    }
    dfs(ans,step+1);
    for(int i=pairk[step].l;i<=pairk[step].r;i++)
    {
        vis[i]++;
    }
    dfs(++ans,step+1);

}


int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int lr = a[i];
            for(int l = i+1;l<=j;l++)
            {
                lr = xor1(a[i],lr);
            }
            if(lr == k)
            {
                pairk[++posnode].l = i;
                pairk[posnode].r = j;
            }
        }
    }

    dfs(0,1);
    cout << maxans;
    return 0;
}

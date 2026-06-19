#include <bits/stdc++.h>
using namespace std;
const int P=998244353;
int a[1000005],b[1000005],ans[1000005],fa[1000005],son[1000005][2],tot=0;
int twice[1000005];
void work()
{
    twice[0] = 1;
    for(int i=1;i<=1000000;i++) twice[i] = twice[i-1]*2%P;
}
void dfs(int now)
{
    int sum=0;
    if(son[now][0]) dfs(son[now][0]);
    ans[++tot] = now;
    if(son[now][1]) dfs(son[now][1]);
    if(son[now][0]) sum++;
    if(son[now][1]) sum++;
    if(sum==1) tot++;
}
int main()
{
    // freopen("tree.in","r",stdin);
    // freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;work();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    if(n==1)
    {
        cout<<1<<"\n"<<1;
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        fa[a[i]] = a[i-1];
        son[a[i-1]][0] = a[i];
        if(a[i]==b[1]) break;
    }
    int tmp[1000005]={0},t=fa[b[1]];
    queue<int> q;
    for(int i=2;i<=n;)
    {
        while(!q.empty()) q.pop();
        int tot1=0,x;
        for(int j=i;j<=n;j++) if(b[j]==t){x=j;break;}
        for(int j=i+x-2;j>=i;j--) tmp[++tot1] = b[j];
        int x2=2;q.push(tmp[1]);
        fa[tmp[1]] = b[i+x-2];son[b[i+x-2]][1] = tmp[1];
        for(int j=2;j<=tot1;j+=min(tot1-j,x2))
        {
            for(int k=j;k<=j+x2-1;k+=2)
            {
                int t=q.front();q.pop();
                son[t][0] = tmp[k];
                son[t][1] = tmp[k+1];
                fa[tmp[k]] = t;fa[tmp[k+1]] = t;
                q.push(tmp[k]);q.push(tmp[k+1]);
            }
            x2*=2;
            if(j==tot1) break;
        }
        t = fa[t];i+=x;
    }
    dfs(1);
    cout<<twice[tot]<<"\n";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
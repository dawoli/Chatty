#include<bits/stdc++.h>
using namespace std;
int n,r[100001],ans=-1;
bool mark[100001]={},use[100001]={},flag;
void dfs(int i,int j,int now)
{
    if(r[i]>r[j]){
        now--;
        use[j]=1;
    }
    flag=0;
    for(int a=1;a<=n;a++)
    {
        if(use[a]==0&&mark[a]==0){flag=1;}
    }
    if(flag==0){ans=max(ans,now);return;}
    for(int a=1;a<=n;a++)
    {
        if(use[a]==1||mark[a]==1){continue;}
        for(int b=1;b<=n;b++)
        {
            if(use[b]==1||mark[b]==1){continue;}
            mark[a]=1;
            dfs(a,b,now);
            use[b]=0;
            mark[a]=0;
            mark[b]=0;
        }
    }


}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    dfs(0,0,n);
    cout<<ans;
    return 0;
}

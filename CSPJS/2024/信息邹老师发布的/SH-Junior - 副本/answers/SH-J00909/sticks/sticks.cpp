#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n;
int ans;
int arr[]={6,2,5,5,4,5,6,3,7,6};
int num[MAXN];
void dfs(int weishu,int sum);
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=-1;
        dfs(1,n);
        printf("%d\n",ans);
    }
    return 0;
}
void dfs(int weishu,int sum)
{
    if(sum==0)
    {
        int res=0;
        for(int i=1;i<weishu;i++)
        {
            res=res*10+num[i];
        }
        if(ans==-1)
            ans=res;
        else
            ans=min(ans,res);
        return;
    }
    for(int i=0;i<=9;i++)
    {
        if(weishu==1 && i==0)
            continue;
        if(arr[i]<=sum)
        {
            num[weishu]=i;
            dfs(weishu+1,sum-arr[i]);
            num[weishu]=-1;
        }
    }
}

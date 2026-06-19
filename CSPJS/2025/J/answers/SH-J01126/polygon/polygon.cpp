#include<bits/stdc++.h>
using namespace std;

long long ans;

void dfs(vector<int> &a,int nowat,int n,int maxlong,int totlong,int choice)
{
    if(nowat==n+1)
    {
        if(choice>=3 and totlong>maxlong*2)
        {
            ans++;
            ans%=998244353;
        }
        return ;
    }
    dfs(a,nowat+1,n,max(maxlong,a[nowat]),totlong+a[nowat],choice+1);
    dfs(a,nowat+1,n,maxlong,totlong,choice);
    return ;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(a,1,n,0,0,0);
    cout<<ans<<endl;
    return 0;
}

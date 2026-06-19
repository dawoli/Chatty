#include <bits/stdc++.h>
using namespace std;
int n,m,c[1000];
int ans[1000];
long long sum=0;
string s;
int vis[1000];
long long pre[1000];
void dfs(int num)
{
	if(num==n)
	{
		sum++;
		sum%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0&&num<=ans[i])
		{
			vis[i]=1;
			dfs(num+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int cnt=0;
	if(s[0]=='1')
	{
		pre[0]=0;
	}
	else{
		pre[0]=1;
		cnt++;
	}
	//cout<<pre[0]<<endl;
	for(int i=1;i<n;i++)
	{
		pre[i]=pre[i-1];
		if(s[i]=='0')
		{
			pre[i]++;
			cnt++;
		}
		//cout<<pre[i]<<endl;
	}
	//cout<<cnt<<endl;
	if(n-cnt<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=pre[n-1]&&c[i]>=pre[0])
		{
			ans[i]=upper_bound(pre,pre+n,c[i])-pre-1;
		}
		else if(c[i]>pre[n-1])
		{
			ans[i]=n-1;
		}
		else{
			ans[i]=-1;
		}
		//cout<<ans[i]<<endl;
	}
	dfs(0);
	cout<<sum;
	return 0;
}

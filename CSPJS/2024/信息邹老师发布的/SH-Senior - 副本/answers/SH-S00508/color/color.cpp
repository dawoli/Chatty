#include<iostream>
#include<cstdio>
using namespace std;
int n,maxn=0,a[200001],num_t[200001],num_f[200001];
void dfs(int step,int ans)
{
	if(step==n+1)
	{
		maxn=max(ans,maxn);
		return;
	}
	//yes
	num_t[step]=step;
	num_f[step]=num_f[step-1];
	dfs(step+1,ans+(a[num_t[step-1]]==a[step])*a[step]);
	//no
	num_t[step]=num_t[step-1];
	num_f[step]=step;
	dfs(step+1,ans+(a[num_f[step-1]]==a[step])*a[step]);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxn=0;
		num_t[0]=num_f[0]=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1,0);
		cout<<maxn<<endl;
	}
}

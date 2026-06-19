#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a[200005],maxn=-1;
void dfs(int n,int step,int sr,int sb,int sum)
{
	if(step>n)
	{
		maxn=max(maxn,sum);
		return;
	} 
	int dr=0,db=0;
	if(a[step]==a[sr])dr=a[step];
	if(a[step]==a[sb])db=a[step];
	dfs(n,step+1,step,sb,sum+dr);
	dfs(n,step+1,sr,step,sum+db);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		a[0]=-1;
		for(int i = 1;i <= n;i++)
		{
			cin>>a[i];
		}
		maxn=-1;
		dfs(n,1,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}

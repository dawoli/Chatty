#include<bits/stdc++.h>
using namespace std;
int f[210][110][110];
int n;
struct node{int a,b,c;}a[100010];
bool cmp1(node a,node b){return a.a>b.a;}
int dfs(int step,int i,int j)
{
	if (step>n)
	if (i>n/2)return 0; 
	if (j>n/2)return 0; 
	if (step-i-j>n/2)return 0; 
	if (f[step][i][j]>0)return f[step][i][j]-1;
	int ans=max({dfs(step+1,i+1,j)+a[step].a,
				 dfs(step+1,i,j+1)+a[step].b,
				 dfs(step+1,i,j)+a[step].c
			   });
	f[step][i][j]=ans;
	return ans;
}
int main()
{
	freopen("club2.in","r",stdin);
	freopen("club2.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		memset(f,0,sizeof f);
		cin>>n;
		bool flaga=1;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if (a[i].b!=0||a[i].c!=0)flaga=0;
		}
		if (flaga)
		{
			sort(a+1,a+n+1,cmp1);
			int ansa=0;
			for (int i=1;i<=n/2;i++)
			{
				ansa+=a[i].a;
			}
			cout<<ansa<<endl;
			continue;
		}
		cout<<dfs(1,0,0)<<endl;
	}
}

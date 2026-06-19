#include <iostream>
#include <cstdio>
using namespace std;
int n,k,q,r,c,T,a[100005][4006],f;
int check(int aa,int b,int p,int x,int y,int z)
{
	for(int ii = 1;ii<=b-aa;ii++)
	{
		if(a[p][aa+ii]=a[z][x+ii]) return 0;
	}
	return 1;
}
int dfs(int round,int num,int s,int e,int per)
{
	if(round==r&&num==c)return 1;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=a[i][0];j++)
		{
			for(int p = j+1;p<=k+j;p++)
			{
				if(a[i][j]!=a[per][e])continue;
				if(round==0&&a[i][p]!=1)continue;
				if((e-s)==p-j)if(check(s,e,per,j,p,i))continue;
				f=f||dfs(round+1,a[i][a[i][0]],j,p,i);
			}
		}
	}
	return a[n][a[n][0]+a[n][0]];
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i][0];
			for(int j = 1;j<=a[i][0];j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i = 1;i<=q;i++)
		{
			cin>>r>>c;
			dfs(0,0,0,0,0);
			if(i!=q)cout<<dfs(0,0,0,0,0)+i%2<<endl;
			else cout<<(i+1)%2-dfs(0,0,0,0,0)<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

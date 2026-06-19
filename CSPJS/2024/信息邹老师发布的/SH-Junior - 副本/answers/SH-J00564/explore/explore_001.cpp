#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,k;
long long ans=1;
int x0,y0,d0;
char a[1002][1002];
int a1[1002][1002];
void judge(int k,int d0)
{
	
	if (k==0)
		return;
	
	if (d0==0)
		y0++;
	if (d0==1)
		x0++;
	if (d0==2)
		y0--;
	if (d0==3)
		x0--;
	if (a1[x0][y0]==1)
	{
	
		k--;
		judge(k,d0);
	}
	else
	{
			
		if (a[x0][y0]!='x'&&x0>=1&&x0<=n&&y0>=1&&y0<=m)
		{
				
			ans++;
			a1[x0][y0]=1;
		}
		else
		{
		
			if (d0==0)
				y0--;
			if (d0==1)
				x0--;
			if (d0==2)
				y0++;
			if (d0==3)
				x0++;
			d0=(d0+1)%4;
		}
		k--;
		judge(k,d0);
	}	
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>n>>m>>k;
	cin>>x0>>y0>>d0;
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	a1[x0][y0]=1;
	judge(k,d0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

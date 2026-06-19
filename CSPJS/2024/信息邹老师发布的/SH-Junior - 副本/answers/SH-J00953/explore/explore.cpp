#include<bits/stdc++.h>
using namespace std;
int t,ans[10],n,m,k,x,y,d;
int go(int p);
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		go(i);
	for(int i=1;i<=t;i++)
		cout<<ans[i]<<endl;
	return 0;
} 

int go(int p)
{
	cin>>n>>m>>k>>x>>y>>d;
	char a[n+1][m+1];
	bool q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	a[x][y]='*';
	for(int i=1;i<=k;i++)
	{
		q=false;
		if(q==false && d==0 && y+1<=m && (a[x][y+1]=='.' || a[x][y+1]=='*')) {y++;a[x][y]='*';q=true;}
		if(q==false && d==1 && x+1<=n && (a[x+1][y]=='.' || a[x+1][y]=='*')) {x++;a[x][y]='*';q=true;}
		if(q==false && d==2 && y-1>=1 && (a[x][y-1]=='.' || a[x][y-1]=='*')) {y--;a[x][y]='*';q=true;}
		if(q==false && d==3 && x-1>=1 && (a[x-1][y]=='.' || a[x-1][y]=='*')) {x--;a[x][y]='*';q=true;}
		if(q==false) d=(d+1)%4;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='*')
				ans[p]++;
	return 0;
}

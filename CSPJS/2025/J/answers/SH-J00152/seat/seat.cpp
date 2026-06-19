#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int f[100][100];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y,int i)
{
	if(i>n*m)
		return;
	f[x][y]=a[i];
	if(x+1<=n&&f[x+1][y]==0)
		dfs(x+1,y,i+1);
	else if(x-1>0&&f[x-1][y]==0)
		dfs(x-1,y,i+1);
	else
		dfs(x,y+1,i+1);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int temp=a[1];
	sort(a+1,a+m*n+1,cmp);
	dfs(1,1,1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f[i][j]==temp)
			{
				cout<<j<<' '<<i;
				return 0;
			}
	return 0;
 } 

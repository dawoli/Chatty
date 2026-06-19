#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n,m,k;
ll sx,sy,sd;
char a[1000][1000];
ll bfs(ll x,ll y,ll d)
{
	ll cnt=0;
	while(k--)
	{
		if(d==0) 
		{
		  if(a[x][y+1]=='.'&&x>=1&&x<=n&&y+1>=1&&y+1<=m) {cnt++;y++;}
		  else
		  {
		  	d=(d+1)%4;
			//y--;
		  } 
		}
		if(d==1) 
		{
		  if(a[x+1][y]=='.'&&x+1>=1&&x+1<=n&&y>=1&&y<=m){cnt++;x++;}
		  else
		  {
		  	d=(d+1)%4;
			//x--;
		  } 
		}
		if(d==2) 
		{
		  if(a[x][y-1]=='.'&&x>=1&&x<=n&&y-1>=1&&y-1<=m){cnt++,y--;} 
		  else
		  {
		  	d=(d+1)%4;
			//y++;
		  } 
		}
		if(d==3) 
		{
		  if(a[x-1][y]=='.'&&x-1>=1&&x-1<=n&&y>=1&&y<=m){cnt++;x--;}
		  else
		  {
		  	d=(d+1)%4;
			//x++;
		  } 
		}
	}
    return cnt;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
    	cin>>n>>m>>k;
    	cin>>sx>>sy>>sd;
    	for(ll i=1;i<=n;i++)
    	  for(ll j=1;j<=m;j++)
    	  {
    	  	cin>>a[i][j];
		  }
		cout<<bfs(sx,sy,sd)<<endl;
	}
	return 0;
}

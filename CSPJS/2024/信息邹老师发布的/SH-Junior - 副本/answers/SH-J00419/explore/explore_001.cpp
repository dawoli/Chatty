#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mp[1005][1005]; //0 x  1 没走过空地  2 走过 
int T,n,m,k;
int nowx,nowy,nowd;
int ans;
	
void mod(int &num)
{
	if(num>=4)num-=4;
	return ;
}

void clear()
{
	ans=0;
	for(int i=0;i<=m+1;i++)
	{
		mp[0][i]=0;
		mp[n+1][i]=0;
	}
	for(int i=0;i<=n+1;i++)
	{
		mp[i][0]=0;
		mp[i][m+1]=0;
	}
	return ;
}

void in()
{
	char c;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>c;
		if(c=='x')mp[i][j]=0;
		else mp[i][j]=1;
	}
	return ;
}

void test_out()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	return ;
}

bool go(int &x,int &y,int &d)
{
	if(d==0)
	{
		if(!mp[x][y+1])return false;
		else
		{
			ans+=(++mp[x][++y]==2);
			return true;
		}
	}
	if(d==1)
	{
		if(!mp[x+1][y])return false;
		else
		{
			ans+=(++mp[++x][y]==2);
			return true;
		}
	}
	if(d==2)
	{
		if(!mp[x][y-1])return false;
		else
		{
			ans+=(++mp[x][--y]==2);
			return true;
		}
	}
	if(d==3)
	{
		if(!mp[x-1][y])return false;
		else
		{
			ans+=(++mp[--x][y]==2);
			return true;
		}
	}
}

void solve()
{
	mp[nowx][nowy]++;
	ans++;
	while(k--)
	{
		if( ! go(nowx,nowy,nowd) )
		{
			mod(++nowd);
		}
	}
	cout<<ans<<endl;
	return ;
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>nowx>>nowy>>nowd;
		clear();
		in();
		//test_out();
		solve();
	}
	return 0;
}

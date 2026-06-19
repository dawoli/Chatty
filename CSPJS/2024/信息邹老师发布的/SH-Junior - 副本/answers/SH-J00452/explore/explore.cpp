#include<bits/stdc++.h>
using namespace std;
long long m,n,k,t,x_0,y_0,d_0;
char mp_0[1001][1001];
bool vis[1001][1001];
bool check(long long x,long long y,long long d)
{
	if((d==0&&y+1>m)||(d==0&&mp_0[x][y+1]=='x'))
	{

		return false;
	}
		
	else
		if(d==1&&x+1>n||(d==1&&mp_0[x+1][y]=='x'))
		{
			return false;
		}
			
		else
			if((d==2&&y-1<1)||(d==2&&mp_0[x][y-1]=='x'))
			
			{
				return false;
			}
			else
				if((d==3&&x-1<1)||(d==3&&mp_0[x-1][y]=='x'))
				{
					return false;
				}
	return true;
}
void sub(long long x,long long y,long long d)
{
	if(k==0)
		return;
	else
	{
		if(check(x,y,d)==false)
		{
			k--;
			
			sub(x,y,(d+1)%4);
		}
		else
		{			
			k--;
			if(d==0)
			{
	
				vis[x][y+1]=true;
				sub(x,y+1,d);
			}
			else
			{
				if(d==1)
				{
			
					vis[x+1][y]=true;
					sub(x+1,y,d);
					
		
					
				}
				else
				{
					if(d==2)
					{
			
						vis[x][y-1]=true;
	
						sub(x,y-1,d);
						
						
			
						
					}
					else
					{
						if(d==3)
						{
				
							vis[x-1][y]=true;
	
							sub(x-1,y,d);
							
			
						}
					}
				}
			}
				
		}
	}
}
void tu_in(long long n,long long m)
{
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			cin>>mp_0[i][j];
		}
	}
}
long long checkm()
{
	long long sum=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(vis[i][j]==true)
				sum++;
		}
	}
	return sum;
};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>n>>m>>k;	
		cin>>x_0>>y_0>>d_0;
		tu_in(n,m);
		vis[x_0][y_0]=true;
		sub(x_0,y_0,d_0);
			cout<<checkm()<<endl;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=m;j++)
			{
				vis[i][j]=0;
			}
		}
	
	}

	
	return 0;
}

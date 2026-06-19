#include <bits/stdc++.h>
using namespace std;
char ma[1005][1005];
bool mb[1005][1005];
int T,n,m,k,d,cnt[10],x,y;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int q=1;q<=n;q++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>ma[q][j];
				mb[q][j]=true;
			}
		}
		mb[x][y]=false; 
		for(int p=k;p>=1;p--)
		{
			if(d==0 && ma[x][y+1]=='.' && y+1<=m)
			{	
				y=y+1;
				if(mb[x][y]==true) cnt[i]++;
				mb[x][y]=false;
				continue;
			}
			else if(d==1 && ma[x+1][y]=='.' && x+1<=n)
			{
				x=x+1;
				if(mb[x][y]==true) cnt[i]++;
				mb[x][y]=false;	
				continue;
			}
			else if(d==2 && ma[x][y-1]=='.' && y-1>=1)
			{
				y=y-1;
				if(mb[x][y]==true) cnt[i]++;
				mb[x][y]=false;	
				continue;
			}
			else if(d==3 && ma[x-1][y]=='.' && x-1>=1)
			{
				x=x-1;
				if(mb[x][y]==true) cnt[i]++;
				mb[x][y]=false;	
				continue;
			}
			else
			{
				d=(d+1)%4;
			}	
		}
		cout<<cnt[i]+1<<endl; 
	}
	return 0;
 } 

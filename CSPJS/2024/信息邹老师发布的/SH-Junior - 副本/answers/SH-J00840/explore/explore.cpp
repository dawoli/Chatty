#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,sum,f=0;
char Map[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1  ; i<=t ; i++)
	{
		sum=0;
		f=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1 ; j<=n ; j++)
			for(int w=1 ; w<=m ; w++)
				cin>>Map[j][w];
		while(k--)
		{
			f=0;
			if(d==0&&y+1<=m&&Map[x][y+1]!='x')
			{
				if(Map[x][y+1]=='-')
				{
					Map[x][y]='-';
					y+=1;
					f=1;
				}
				else
				{
					Map[x][y]='-';
					sum++;
					y+=1;
					f=1;
				}
			}
			if(d==1&&x+1<=n&&Map[x+1][y]!='x')
			{
				if(Map[x+1][y]=='-')
				{
					Map[x][y]='-';
					x+=1;
					f=1;
				}
				else
				{
					Map[x][y]='-';
					sum++;
					x+=1;
					f=1;
				}
			}
			if(d==2&&y-1>=1&&Map[x][y-1]!='x')
			{
				if(Map[x][y-1]=='-')
				{
					Map[x][y]='-';
					y-=1;
					f=1;
				}
				else 
				{
					Map[x][y]='-';
					sum++;
					y-=1;
					f=1;
				}
			}
			if(d==3&&x-1>=1&&Map[x-1][y]!='x')
			{
				if(Map[x-1][y]=='-')
				{
					Map[x-1][y]='-';
					x-=1;
					f=1;
				}
				else
				{
					Map[x][y]='-';
					sum++;
					x-=1;
					f=1;	
				}
			}
			if(f==0)
			{
				d=(d+1)%4;
			}
		}
		cout<<sum+1<<endl;
	}
}



#include<bits/stdc++.h>
using namespace std;
char p[6][1005][1005]={'x'};
bool a[6][1005][1005]={0};
int t,n,m,k,x,y,d,cnt=0;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		//cout<<endl;
		cnt=0;
		cin>>n>>m>>k>>x>>y>>d;
		a[i][x][y]=1;cnt++;
		for(int j=1;j<=n;j++)
		{
			for(int s=1;s<=m;s++)
			{
				cin>>p[i][j][s];
			}
		}
		for(int j=1;j<=k;j++)
		{
			if(d==0)
			{
				if(p[i][x][y+1]=='.')
				{
					y++;
					if(a[i][x][y]==0)
					{
						a[i][x][y]=1;cnt++;
						//cout<<"y"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
						continue;
					}
					else
					{
                		//cout<<"w"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
						continue;
					}
				}
				else
				{
					//cout<<"e"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
					d=1;continue;
				}
			}
			if(d==1)
			{
				if(p[i][x+1][y]=='.')
				{
					x++;
					if(a[i][x][y]==0)
					{
						a[i][x][y]=1;cnt++;
						//cout<<"y"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
						continue;
					}
					else
					{
                		//cout<<"w"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
						continue;
					}
				}
				else
				{
					//cout<<"e"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
					d=2;continue;
				}
			}
			if(d==2)
			{
				if(p[i][x][y-1]=='.')
				{
					y--;
					if(a[i][x][y]==0)
					{
						a[i][x][y]=1;cnt++;
						//cout<<"y"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
						continue;
					}
					else
					{
                		//cout<<"w"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
						continue;
					}
				}
				else
				{
					//cout<<"e"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
					d=3;continue;
				}
			}
			if(d==3)
			{
				if(p[i][x-1][y]=='.')
				{
					x--;
					if(a[i][x][y]==0)
					{
						a[i][x][y]=1;cnt++;
						//cout<<"y"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
						continue;
					}
					else
					{
                		//cout<<"w"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
						continue;
					}
				}
				else
				{
					//cout<<"e"<<" "<<d<<" "<<cnt<<" "<<x<<" "<<y<<endl;
					d=0;continue;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

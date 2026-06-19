#include <iostream>
#include <algorithm>
using namespace std;




string gr[1005];//gr[x][y]表示地图(x,y) 
bool vis[1005][1005];

int main()
{
	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int r=1;r<=t;r++)
	{
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=1000;j++)
			{
				vis[i][j]==false;
			}
			gr[i]="";
		}
		int n,m,k;
		cin>>n>>m>>k;
		
		int x=0,y=0,d=0;
		cin>>x>>y>>d;
		vis[x][y]=true;
		for(int i=1;i<=n;i++)
		{
			cin>>gr[i];
			
		}
		for(int i=1;i<=k;i++)
		{
			int xn=x,yn=y;
			if(d==0)yn++;
			if(d==1)xn++;
			if(d==2)yn--;
			if(d==3)xn--;
			
			if(xn>0&&xn<=n&&yn>0&&yn<=m)
			{
				
				if(gr[xn][yn]!='x')
				{
					x=xn;
					y=yn;
					vis[x][y]=true;
				}
				else
				{
					d=(d+1)%4;
					
					continue;
				}
			}
			else
			{
				d=(d+1)%4;
				
				continue;
			}
			//cout<<x<<" "<<y<<" "<<d<<endl;//
			
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				//cout<<vis[i][j]<<endl;//调试 
				if(vis[i][j]==true)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;

		
	}
	
	
	return 0;
}
//
// 
// 
// 
// // // // 



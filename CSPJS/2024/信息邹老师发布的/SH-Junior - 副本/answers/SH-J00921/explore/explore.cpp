#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,T;
int x0,y0,d0;
bool a[1005][1005];
bool vst[1005][1005];
int dx[4]{0,1,0,-1};
int dy[4]{1,0,-1,0};
long long ansans[10];
void dfs(int kf,int xf,int yf,int df)
{
	//cout<<"#   "<<xf<<" "<<yf<<" "<<df<<" "<<kf<<endl;
	vst[xf][yf]=1;
	if(kf>=k+1)
	{
		return;
	}
	int t=df;
	if(xf+dx[t]<=n and xf+dx[t]>=1 and yf+dy[t]<=m and yf+dy[t]>=1 and a[xf+dx[t]][yf+dy[t]]==1)
	{
		dfs(kf+1,xf+dx[t],yf+dy[t],t);
		return ;
	}
	dfs(kf+1,xf,yf,(t+1)%4);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		ans=0;
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) 
			{
				vst[i][j]=0;
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) 
			{
				char ch;
				cin>>ch;
				if(ch=='.')
				{
					a[i][j]=1;
				}
			}
		}
		dfs(1,x0,y0,d0);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) 
			{
				if(vst[i][j]==1)
				{
					ans++;
				}
			}
		}
		ansans[ii]=ans;
	}
	for(int i=1;i<=T;i++)
	{
		cout<<ansans[i]<<endl;
	}
	return 0;
} 

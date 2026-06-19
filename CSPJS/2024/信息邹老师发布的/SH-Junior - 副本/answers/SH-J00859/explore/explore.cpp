#include <bits/stdc++.h>
using namespace std;
char mapp[2005][2005];
bool vis[2005][2005];
long long k,n,m,ans;
long long dfs(long long xx,long long yy,long long dd,long long step)
{
	long long x=xx,y=yy,d=dd;
	while(step<=k){
		long long nx=x,ny=y;
		if(d==0)ny++;
		else if(d==1)nx++;
		else if(d==2)ny--;
		else if(d==3)nx--;
		if(nx>0&&nx<=n&&ny>0&&ny<=m&&mapp[nx][ny]!='x')
		{
			if(!vis[nx][ny]){
				ans++;
//				cout<<nx<<" "<<ny<<endl;
				vis[nx][ny]=1;
			}
			x=nx,y=ny;
			//cout<<nx<<" "<<ny<<" "<<d<<" "<<step<<" "<<mapp[nx][ny]<<endl;
			step++;	
		
		}else
		{
			d=(d+1)%4;
			step++;
		}	
		
	}
	return ans;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long T;
	cin>>T;
	while(T--)
	{
		memset(mapp,0,sizeof(mapp));
		ans=1;
		cin>>n>>m>>k;
		long long x0,y0,d0;
		memset(vis,0,sizeof(vis));
		cin>>x0>>y0>>d0;
		vis[x0][y0]=1;
		for(long long i=1;i<=n;i++)
		{
			cin>>mapp[i]+1;
		}
//		for(long long i=1;i<=n;i++)
//		{
//			for(long long j=1;j<=m;j++)
//			cout<<mapp[i][j];
//		}
		long long anss=dfs(x0,y0,d0,1);
		cout<<anss<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


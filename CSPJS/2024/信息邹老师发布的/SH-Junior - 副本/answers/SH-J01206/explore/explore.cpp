#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int T,n,m,k,x,y,d,ans;
int vst[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mp[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				vst[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		vst[x][y]=1;
		ans=1;
		while(k--){
			int xp=x+dx[d];
			int yp=y+dy[d];
			if(xp>=1&&xp<=n&&yp>=1&&yp<=m&&mp[xp][yp]=='.'){
				if(!vst[xp][yp]) ans++;
				vst[xp][yp]=1;
				x=xp;
				y=yp;
			}
			else d=(d+1)%4; 
		}
		cout<<ans<<endl;
	}
	return 0;
}

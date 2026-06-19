#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7;

char mp[N][N];

int g[N][N];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(mp,0,sizeof(mp));
		memset(g,0,sizeof(g));
		int n,m,k,x,y,d;//d=0ÓÒ d=1ÏÂ d=2×ó d=3ÉÏ¡£
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)cin>>mp[i][j];
		}
		int ans=1;g[x][y]=1;
		for(int i=1;i<=k;i++){
			if(d==0)y++;
			if(d==1)x++;
			if(d==2)y--;
			if(d==3)x--;
			if(x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]=='.'){
				if(g[x][y]==0)ans++,g[x][y]=1;
			}
			else{
				if(d==0)y--;
				if(d==1)x--;
				if(d==2)y++;
				if(d==3)x++;
				d=(d+1)%4;
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
} 

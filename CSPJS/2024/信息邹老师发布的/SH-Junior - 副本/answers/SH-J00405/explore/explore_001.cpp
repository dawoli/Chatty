#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char c[1010][1010];
bool f[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cin>>n>>m>>k>>x>>y>>d;
		f[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>c[i][j];
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&c[nx][ny]=='.')
				x=nx,y=ny,f[nx][ny]=1;
			else
				d++,d%=4;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(f[i][j])
					ans++;
		cout<<ans<<endl;
	}
	return 0;
} 

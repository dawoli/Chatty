#include <bits/stdc++.h>
using namespace std;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,m,k;cin>>n>>m>>k;
		int x,y,d;cin>>x>>y>>d;int ans=1;
		char c[n+1][m+1];bool b[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				b[i][j]=0;
			}
		}
		b[x][y]=1;
		while(k--){
			int tx=x+fx[d],ty=y+fy[d];
			if(tx<=0||tx>n||ty<=0||ty>m||c[tx][ty]=='x'){
				d++;
				d%=4;
			}else{
				x=tx;y=ty;
				if(b[x][y]==0) ans++;
				b[x][y]=1;
			}
		}
		cout<<ans<<endl;
	}
} 

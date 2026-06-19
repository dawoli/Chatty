#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,q[4][2]={0,1,1,0,0,-1,-1,0};
char a[1010][1010];
bool visit[1010][1010]={0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				visit[i][j]=false;
			}
		}
		visit[x][y]=true;
		while(k--){
			int xx=x+q[d][0],yy=y+q[d][1];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!='x'){
				if(visit[xx][yy]!=1){
					ans++;
					visit[xx][yy]=1;
				}
				x=xx,y=yy;
			}else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

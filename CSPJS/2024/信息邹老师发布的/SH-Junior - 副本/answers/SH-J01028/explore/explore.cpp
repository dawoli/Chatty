#include<iostream>
using namespace std;
int t,n,m,k,x,y,d,vis[1010][1010];
char a[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		for(int zhou=1;zhou<=n;zhou++){
			for(int jin=1;jin<=m;jin++){
				vis[zhou][jin]=0;
			}
		}
		cin>>n>>m>>k>>x>>y>>d;
		long long ans=0;
		int xx,yy;
		vis[x][y]=1;
		for(int z=1;z<=n;z++){
			for(int w=1;w<=m;w++){
				cin>>a[z][w];
			}
		}
		for(int j=1;j<=k;j++){
			xx=x,yy=y;
			if(d==0){
				yy++;
			}else if(d==1){
				xx++;
			}else if(d==2){
				yy--;
			}else if(d==3){
				xx--;
			}
			if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&a[xx][yy]=='.'){
				if(vis[xx][yy]==0){
					vis[xx][yy]=1;
				}
				x=xx,y=yy;
			}else{
				d=(d+1)%4;
			}
		}
		for(int zhou=1;zhou<=n;zhou++){
			for(int jin=1;jin<=m;jin++){
				if(vis[zhou][jin]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

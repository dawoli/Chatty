#include <bits/stdc++.h>
using namespace std;
bool inmap(int x,int y,int n,int m){
	return x>=1 && x<=n && y>=1 && y<=m;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		int n,m,k,sx,sy,d,ans=1,nx,ny;
		bool vis[1005][1005]={};
		char a[1005][1005]={};
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for (int i=1;i<=k;i++){
			if (d==0){
				nx=sx;
				ny=sy+1;
			}
			else if (d==1){
				nx=sx+1;
				ny=sy;
			}
			else if (d==2){
				nx=sx;
				ny=sy-1;
			}
			else if (d==3){
				nx=sx-1;
				ny=sy;
			}
			if (inmap(nx,ny,n,m) && a[nx][ny]=='.'){
				if (!vis[nx][ny]) 
				{
					ans++;
					vis[nx][ny]=1;
					//cout<<nx<<" "<<ny<<" "<<d<<endl;//
				}
				sx=nx;
				sy=ny;
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

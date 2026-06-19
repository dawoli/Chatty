#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,vis[1005][1005],ans[10],xx,yy,an=0;
char ditu[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n>>m>>k>>x>>y>>d;
		xx=x;
		yy=y;
		for(int j=1;j<=n;j++){
			for(int q=1;q<=m;q++){
				cin >> ditu[j][q];
				vis[j][q]=0;
			}
		}
		vis[x][y]=1;
		an=1;
		for(int j=1;j<=k;j++){
			if(d==0){
				yy+=1;
			}else if(d==1){
				xx+=1;
			}else if(d==2){
				yy-=1;
			}else if(d==3){
				xx-=1;
			}
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&ditu[xx][yy]=='.'){
				x=xx;
				y=yy;
			}else{
				d=(d+1)%4;
				xx=x;
				yy=y;
			}
			if(vis[x][y]==0){
				an++;
				vis[x][y]=1;
			}
		}
		ans[i]=an;
	}
	for(int i=1;i<=t;i++){
		cout << ans[i]<<endl;
	}
	return 0;
}

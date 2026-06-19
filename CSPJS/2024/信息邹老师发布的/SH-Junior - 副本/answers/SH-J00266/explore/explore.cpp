#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,vis[1010][1010];
int bx[4]={0,1,0,-1},by[4]={1,0,-1,0};
char a[1010][1010];
int ans,kk_1;
int xx_0,yy_0,dd_0;
void expl_0(int x,int y,int d){
	while(kk_1<k){
		vis[x][y]=1;
		int to_x=x+bx[d],to_y=y+by[d];
		if(to_x<0||to_x>=n||to_y<0||to_y>=m||a[to_x][to_y]=='x'){
			d=(d+1)%4;
		}
		else{
			x=to_x;
			y=to_y;
			vis[x][y]=1;
		}
		kk_1++;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int q=1;q<=T;q++){
		cin>>n>>m>>k;
		cin>>xx_0>>yy_0>>dd_0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		xx_0--;
		yy_0--;
		kk_1=0;
		expl_0(xx_0,yy_0,dd_0);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(vis[i][j]==1){
					ans++;
					vis[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

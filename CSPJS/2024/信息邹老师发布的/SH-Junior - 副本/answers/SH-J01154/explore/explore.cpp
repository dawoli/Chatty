#include<bits/stdc++.h>
using namespace std;
int mvx[4]={0,1,0,-1},mvy[4]={1,0,-1,0}; 
int t,n,m,k,x,y,d,ans;
char mp[1005][1005];
void input(){
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
}
void solveK1(){
	if(x+mvx[d]<=n&&x+mvx[d]>=1&&y+mvy[d]<=m&&y+mvy[d]>=1&&mp[x+mvx[d]][y+mvy[d]]=='.') cout<<2<<endl;
	else cout<<1<<endl;
}
void solve(){
	int nx,ny;
	mp[x][y]='o'; ans=1;
	while(k--){
		nx=x+mvx[d]; ny=y+mvy[d];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
			if(mp[nx][ny]=='.'){
				x=nx; y=ny; mp[x][y]='o'; ans++;
			}
			else if(mp[nx][ny]=='o'){
				x=nx; y=ny;
			}
			else
				d=(d+1)%4;
		}
		else
			d=(d+1)%4;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		input();
		if(k==1) solveK1();
		else solve();
	}
	return 0;
}

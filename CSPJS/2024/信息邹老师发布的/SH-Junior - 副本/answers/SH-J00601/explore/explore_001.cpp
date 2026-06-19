#include<bits/stdc++.h>
#define kMaxN 1005
using namespace std;
const int f[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char buf[kMaxN];
int n,m,k;
int x,y,d;
int ans=0;
int mat[kMaxN][kMaxN];
bool b[kMaxN][kMaxN];
inline bool check(int x,int y){
	return !((mat[x][y])||((x<1)||(x>n)||(y<1)||(y>m)));
}
inline void solve(){
	ans=1;
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++){
		cin>>(buf+1);
		for(int j=1;j<=m;j++){
			mat[i][j]=(buf[j]=='x');
			b[i][j]=0;
		}
	}
	b[x][y]=1;
	for(int i=0;i<k;i++){
		int nx,ny;
		nx=x+f[d][0];
		ny=y+f[d][1];
		if(check(nx,ny)){
			x=nx;
			y=ny;
			if(!b[x][y]){
				b[x][y]=1;
				ans++;
			}
		}
		else{
			d=(d+1)%4;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


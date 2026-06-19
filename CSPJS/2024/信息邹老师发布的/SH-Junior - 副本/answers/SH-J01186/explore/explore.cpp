#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,h,cnt,mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}},dx,dy;
char c[6][1009][1009];
bool v[6][1009][1009];
bool go(int p,int q){
	if(p>=1&&p<=n&&q>=1&&q<=m&&c[h][p][q]=='.') return 1;
	return 0;
}
void solve(int xx,int yy,int dd,int kk){
	if(v[h][xx][yy]==0){
		cnt++;
		v[h][xx][yy]=1;
	}
	if(kk==0) return;
	dx=xx+mv[dd][0];
	dy=yy+mv[dd][1];
	while(go(dx,dy)==0){
		kk--;
		if(kk==0) return;
		dd=(dd+1)%4;
		dx=xx+mv[dd][0];
		dy=yy+mv[dd][1];
	}
	solve(dx,dy,dd,kk-1);
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(h=1;h<=T;h++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>c[h][i][j];
		cnt=0;
		solve(x,y,d,k);
		cout<<cnt<<endl;
	}
	return 0;
}

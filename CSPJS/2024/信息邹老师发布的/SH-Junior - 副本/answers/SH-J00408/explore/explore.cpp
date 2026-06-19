#include<bits/stdc++.h>
#define N 1010
using namespace std;
typedef long long ll;
ll _,n,m,k,_x,_y,_d;
ll dx[5]={0,1,0,-1};
ll dy[5]={1,0,-1,0};
char mp[N][N];
bool vst[N][N];
void init(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			vst[i][j]=false;
}
void solve(){
	cin>>n>>m>>k>>_x>>_y>>_d;
	init();
	for(int i=1;i<=n;++i){
		string p;cin>>p;
		for(int j=0;j<=(int)p.size();++j)
			mp[i][j+1]=p[j];
	}vst[_x][_y]=true;
	while(k--){
		ll tx=_x+dx[_d],ty=_y+dy[_d];
		if(tx<1||ty<1||tx>n||ty>m||mp[tx][ty]=='x')
			_d=(_d+1)%4;
		else _x=tx,_y=ty;
		vst[_x][_y]=true;
	}ll Ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			Ans+=vst[i][j];
	cout<<Ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>_;
	while(_--) solve();
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
void solve(){
	ll n,m,k,x,y,d,cnt=1;
	bool vis[1009][1009];
	char mp[1009][1009];
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=0;i<=1008;i++)
		for(int j=0;j<=1008;j++)
			vis[i][j]=0;
	vis[x][y]=1;
	for(int i=0;i<=k-1;i++){
		ll xx,yy;
		if(d==0){
			xx=x;
			yy=y+1;
		}
		if(d==1){
			xx=x+1;
			yy=y;
		}
		if(d==2){
			xx=x;
			yy=y-1;
		}
		if(d==3){
			xx=x-1;
			yy=y;
		}
		if(xx<=0||xx>=n+1||yy<=0||yy>=m+1||mp[xx][yy]=='x'){
			d=(d+1)%4;
		}
		else{
			x=xx;
			y=yy;
			if(vis[x][y]==0)
				cnt++;
			vis[x][y]=1;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int a=0;a<=T-1;a++)
		solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int sx,sy,d;
char a[1009][1009];
bool check(int x,int y){
	int tx=x,ty=y;
	if(d==0) ty++;
	else if(d==1) tx++;
	else if(d==2) ty--;
	else tx--;
	if(tx<1 or tx>n or ty<1 or ty>m or a[tx][ty]=='x')
		return 0;
	return 1;
}
void solve(){
	memset(a,0,sizeof(a));
	bool vis[1009][1009]={};
	cin>>n>>m>>k;
	cin>>sx>>sy>>d;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	vis[sx][sy]=1;
	int nx=sx,ny=sy;
	int ans=0;
	for(int i=1;i<=k;i++){
		if(check(nx,ny)){
//			vis[nx][ny]=1;
			if(d==0) ny++;
			else if(d==1) nx++;
			else if(d==2) ny--;
			else nx--;
			vis[nx][ny]=1;
		}
		else{
			d++;
			d%=4;
		}
	//	cout<<d<<" "<<nx<<" "<<ny<<"\n";
	}
//	if(a[nx][ny]!='x') ans++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j]){
				ans++;
			//	cout<<i<<" "<<j<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
}
signed main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

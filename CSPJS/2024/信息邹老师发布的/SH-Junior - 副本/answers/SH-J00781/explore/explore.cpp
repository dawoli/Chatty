#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
ll T;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
ll cnt;
char a[N][N];
bool vst[N][N];
void dfs(ll x,ll y,ll d,ll k,ll n,ll m){
	if(!vst[x][y]){
		cnt++;
		vst[x][y]=1;
	}
	if(k==0){
		cout<<cnt<<endl;
		cnt=0;
		return ;
	}
	ll nx=x+dx[d];
	ll ny=y+dy[d];
	if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
		dfs(nx,ny,d,k-1,n,m);
	}
	else{
		dfs(x,y,(d+1)%4,k-1,n,m);
	}
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(ll U=1;U<=T;U++){
		ll x,y,d;
		ll n,m,k;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				vst[n][m]=0;
				cin>>a[i][j];
			}
		}
		dfs(x,y,d,k,n,m);
	}
	return 0;
}

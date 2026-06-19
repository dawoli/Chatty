#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
ll n,m,k,x,y,d;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
char mp[N][N];
bool vis[N][N];
void init(){
	for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++){
		vis[i][j]=0;
	}
}
void solve(){
	init();
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cin>>mp[i][j];
	vis[x][y]=1;
	for(ll i=1;i<=k;i++){
		ll newx=x+dx[d],newy=y+dy[d];
		if(newx<=n&&newx>=1&&newy<=m&&newy>=1&&mp[newx][newy]=='.'){
			x=newx; y=newy;
			vis[newx][newy]=1;
		}
		else d=(d+1)%4;
	}
	ll cnt=0;
	for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cnt+=vis[i][j];
	cout<<cnt<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
	while(t--) solve(); 
    return 0;
}

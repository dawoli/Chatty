#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=1e3+10;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
ll n,m,k;
char mp[N][N];
ll vis[N][N];
ll cur_x,cur_y,d;
inline void clean(){
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			vis[i][j]=0;
}
inline bool inRange(ll x,ll y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
inline void solve()
{
	clean();
	cin>>n>>m>>k;
	cin>>cur_x>>cur_y>>d;
	vis[cur_x][cur_y]=1;
	for(ll i=1;i<=n;i++){
		string s;
		cin>>s;
		s=' '+s;
		for(ll j=1;j<=m;j++)
			mp[i][j]=s[j];
	}
	while(k--){
		ll idx=cur_x+dx[d],idy=cur_y+dy[d];
		if(!inRange(idx,idy)||mp[idx][idy]=='x'){
			d=(d+1)%4;
			continue;
		}
		cur_x=idx,cur_y=idy;
		vis[cur_x][cur_y]=1;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			ans+=vis[i][j];
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	ll T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n1;
ll m1;
ll k;
ll x;
ll y;
ll to;
ll ans;
ll m[10009][10009];
ll vst[10009][10009];
void input(){
	cin>>n1>>m1>>k>>x>>y>>to;
	for(ll i=1;i<=n1;i++){
		for(ll j=1;j<=m1;j++){
			char c;
			cin>>c;
			if(c=='x')m[i][j]=1;
			else m[i][j]=0;
		}
	}
}
void solve(){
	for(ll i=1;i<=n1;i++)for(ll j=1;j<=m1;j++)vst[i][j]=0;
	ans=0;
	for(ll i=1;i<=k;i++){
		vst[x][y]=1;
		if(to==0)y++;
		if(to==1)x++;
		if(to==2)y--;
		if(to==3)x--;
		if(!(x>=1&&x<=n1&&y>=1&&y<=m1&&(m[x][y]==0))){
			if(to==0)y--;
			if(to==1)x--;
			if(to==2)y++;
			if(to==3)x++;
			to++;
		}
		vst[x][y]=1;
		to=to%4;
//		cout<<x<<" "<<y<<" "<<to<<endl
	}
	for(ll i=1;i<=n1;i++)for(ll j=1;j<=m1;j++){
		if(vst[i][j]==1)ans++;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll o;
	cin>>o;
	for(ll i=0;i<o;i++){
		input();
		solve();
	}
	return 0;
}

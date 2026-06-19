#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define ld long double
#define ull unsigned long long
#define cll const long long
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x)) 
using namespace std;
bool st; 
cll N=100009;
ll n,s[N][3],mx[N];
void work(){
	cin>>n; ll ans=0,cnt[3]={};
	rep(i,1,n){
		rep(j,0,2)cin>>s[i][j];
		mx[i]=max_element(s[i],s[i]+3)-s[i];
		cnt[mx[i]]++,ans+=s[i][mx[i]];
	}
	ll t=(n>>1); if(cnt[0]<=t&&cnt[1]<=t&&cnt[2]<=t)cout<<ans<<"\n";
	else{
		vector<ll> v;
		ll x=max_element(cnt,cnt+3)-cnt; ll y=cnt[x]-t;
		rep(i,1,n)if(mx[i]==x)v.push_back(s[i][x]-max(s[i][(x+1)%3],s[i][(x+2)%3]));
		sort(all(v));
		rep(i,0,y-1)ans-=v[i];
		cout<<ans<<"\n";
	}
}
bool ed;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll T=1;cin>>T;
	while(T--)work();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509,MOD=998244353;
ll n,m,c[N],ans=0;
bool vis[N];
string s;

ll A(ll x){
	ll ans=1;
	for(ll i=1;i<=x;i++) (ans*=i)%=MOD;
	return ans;
}
void solveA(){
	cout<<A(n)<<endl;
}
void dfs(ll x,ll cnt,ll pat,ll length){
	length++;
	if(pat<c[x]&&s[x-1]=='1')cnt++;
	else pat++;
	if(cnt==m){
//		ll cntnotvis=0;
//		for(ll i=1;i<=n;i++) if(vis[i]==0) cntnotvis++;
		if(n>length) (ans+=A(n-length))%=MOD;
		return ;
	}
	for(ll i=1;i<=n;i++) {
		if(vis[i]) continue;
		vis[i]=1;
		dfs(i,cnt,pat,length);
		vis[i]=0;
	}
}
void solveBF(){
	for(ll i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,0,0,0);	
		vis[i]=0;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++) cin>>c[i];
//	if(m==1){
//		solve1();
//		return 0;
//	}
	bool isA=1;
	for(ll i=0;i<s.size();i++)
		if(s[i]!='1') {
			isA=0;
			break;
		}
	if(isA){
		solveA();
		return 0;
	}
	solveBF();
//	cout<<A(10)<<endl;
	return 0;
}

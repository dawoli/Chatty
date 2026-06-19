#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
int n,m,c[509];
bool ok[509],isTypeA=1;
namespace TypeA{
	void solve(){
	}
}
namespace BF{
	ll dcnt,fact[509];
	bool inp[509];
	ll dfs(int x){
		if(x>n){
			return n-dcnt>=m;
		}
		if(x-dcnt-1>=m){
//			cout<<x<<' '<<dcnt<<':';
//			for(int i=1;i<=n;i++) cout<<p[i]<<' ';
//			cout<<endl;
			return fact[n-x+1];
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(inp[i]) continue;
			inp[i]=1;
			if(!ok[x]||dcnt>=c[i]) dcnt++;
			(ans+=dfs(x+1))%=M;
			if(!ok[x]||dcnt>=c[i]) dcnt--;
			inp[i]=0;
		}
		return ans;
	}
	void solve(){
		fact[0]=1;
		for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%M;
		cout<<dfs(1)<<'\n';
	}
}//brute force which provides AC on 2 test cases aka. 8pts
namespace MeqN{
	void solve(){
		for(int i=1;i<=n;i++) if(!ok[i]||!c[i]){
			cout<<0<<' ';
			return;
		}
		ll ans=1;
		for(int i=1;i<=n;i++) (ans*=i)%=M;
		cout<<ans<<'\n';
	}
}//provides AC on 1 test case aka. 4pts
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char cc;
	for(int i=1;i<=n;i++){
		cin>>cc;
		ok[i]=(cc=='1');
		if(!ok[i]) isTypeA=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n) MeqN::solve();
	else BF::solve();
//	if(isTypeA) TypeA::solve();
	return 0;
}

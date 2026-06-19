#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509;
const ll MOD=998244353;
ll n,m,c[N],flag=1,ans,p[N],cnt[N],sum[N],cnt_ok,cnt_0,state[N]; 
string s;
void dfs(ll x){
	if(x==n+1){
		cnt_ok=0;
		for(ll i=1;i<=n;i++)
			if(state[i]) cnt_ok++;
		if(cnt_ok>=m){
			ll res=1,cnt0=0;
			for(ll i=1;i<=n;i++){
				if(state[i]==0){
					if(s[i]==0) cnt0++;
					else{
						res*=(sum[cnt0]-cnt0);
						cnt0++;
					}
				}
				else{
					res*=(n-sum[cnt0]-(i-1)-cnt0);
				}
			}
			ans=(ans+res)%MOD;
		}
		return;
	}
	if(s[x]=='0'){
		state[x]=0;
		dfs(x+1);
	}
	else{
		state[x]=0;
		dfs(x+1);
		state[x]=1;
		dfs(x+1);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>s;
	s=" "+s;
	for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(ll i=1;i<=n;i++){
		if(s[i]=='0'){
			flag=0;
			break;
		}
	}
	for(ll i=1;i<=n;i++)
		if(c[i]==0) cnt_0++;
	if(n<=18){
		for(ll i=1;i<=n;i++) p[i]=i;
		do{
			cnt_ok=0;
			for(ll i=1;i<=n;i++){
				if(i-1-cnt_ok>=c[p[i]]||s[i]=='0') continue;
				else cnt_ok++;
			}
			if(cnt_ok>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		printf("%lld",ans);
	}
	else if(m==n){
		if(flag&&cnt_0==0){
			ans=1;
			for(ll i=1;i<=n;i++) ans=(ans*i)%MOD;
		}
		else ans=0;
		printf("%lld",ans);
	}
	else{
		for(ll i=1;i<=n;i++) cnt[c[i]]++;
		sum[0]=cnt[0];
		for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+cnt[i];
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
} 

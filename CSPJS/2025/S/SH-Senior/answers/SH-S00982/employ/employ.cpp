#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
ll n,m,ans,k,sum;
bool s[509];
ll c[509];
ll d[509];
ll ok[29];
bool vst[29];
void solve1(){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(c[i]){
			cnt++;
		}
	}
	if(cnt<m){
		cout<<0;
		return;
	}
	ll p=0,pp=1,q=0,t=1;
	for(ll i=0;i<=n-m;i++){
		for(ll j=1;j<=n;j++){
			if(c[j]<=i){
				p=j;
			}
			else{
				break;
			}
		}
		for(ll j=n-p;j>=1;j--){
			t*=j;
			t%=Mod;
		}
		q++;
		ans+=t*pp;
		ans%=Mod;
		pp*=p-q+1;
		pp%=Mod;
	}
	cout<<ans;
}
void solve2(){
	if(k>c[n]){
		cout<<0;
		return;
	}
	ll p=0,pp=1,q=0,t;
	for(ll i=1;i<=n;i++){
		if(s[i]==0){
			continue;
		}
		t=1;
		for(ll j=1;j<=n;j++){
			if(c[j]<i){
				p=j;
			}
			else{
				break;
			}
		}
		t=n-p;
		q++;
		for(ll j=n-q;j>=1;j--){
			t*=j;
			t%=Mod;
		}
		ans+=t*pp;
		ans%=Mod;
		pp*=p-q+1;
		pp%=Mod;
	}
	cout<<ans;
}
void dfs(ll step){
	if(step==n+1){
		ll now=0,lose=0;
		for(ll i=1;i<=n;i++){
			if(s[i]==0){
				lose++;
			}
			if(lose>=c[ok[i]]){
				lose++;
			}
			else{
				now++;
			}
		}
		if(now>=m){
			ans++;
		}
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vst[i])continue;
		ok[step]=i;
		dfs(step+1);
	}
}
void solve3(){
	dfs(1);
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	k=n+1;
	for(ll i=1;i<=n;i++){
		char x;
		cin>>x;
		if(x=='1'){
			s[i]=1;
		}
		else{
			s[i]=0;
		}
		if(s[i]==0){
			flag=0;
		}
		if(s[i]==1){
			k=min(k,i);
			sum++;
		}
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	if(n<=11){
		solve3();
		return 0;
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	if(m==n){
		if(!flag){
			cout<<0;
			return 0;
		}
		if(c[1]>0){
			ans=1;
			for(ll i=n;i>=1;i--){
				ans*=i;
				ans%=Mod;
			}
			cout<<ans;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(flag){
		solve1();
		return 0;
	}
	if(m==1){
		solve2();
		return 0;
	}
	return 0;
}

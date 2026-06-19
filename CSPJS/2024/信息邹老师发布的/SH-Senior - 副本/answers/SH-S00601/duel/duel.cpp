#include<bits/stdc++.h>
#define N 100002
using namespace std;
typedef long long ll;
ll n,r[N],cnt[N],id[N],m,ans,s[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>r[i];
		++cnt[r[i]];
	}
	sort(r+1,r+n+1);
	for(ll i=1;i<=n;++i)
		if(r[i]!=r[i-1])id[++m]=r[i];
	for(ll i=1;i<=m;++i){
		s[i]=s[i-1]+cnt[id[i]];
//		cout<<s[i]<<' ';
	}
//	cout<<'\n';
	for(ll i=2;i<=m;++i){
		if(cnt[id[i]]>=s[i-1]){
			s[i]-=s[i-1]+ans;
			ans+=s[i-1];
//			cout<<s[i]<<' '<<ans<<"_\n";
		}else{
			s[i]-=cnt[id[i]]+ans;
			ans+=cnt[id[i]];
//			cout<<s[i]<<' '<<ans<<'\n';
		}
	}
	cout<<n-ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100007;
ll n,cnt[N],a,ans;
int main(){
	ios::sync_with_stdio(false);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a;++cnt[a];
		ans=max(ans,cnt[a]);
	}
	cout<<ans<<endl;
	return 0;
}

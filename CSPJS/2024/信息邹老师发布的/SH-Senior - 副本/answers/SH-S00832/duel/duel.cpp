#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=100009,R=100009;
ll a[N],cnt[R];
ll n;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)cnt[a[i]]++;
	
	sort(a+1,a+n+1);
	ll now_loc=0,ans=0;
	for(ll i=1;i<=n;i++){
		while(cnt[now_loc]==0&&now_loc<R)now_loc++;
		if(a[i]<=now_loc)continue;
		else ans++,cnt[now_loc]--;
	}
	cout<<n-ans<<endl;
	
	return 0;
}

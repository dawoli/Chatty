#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll n,r[N],h,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>r[i];
	sort(r+1,r+n+1);
	h=1;
	ans=n;
	for(ll t=2;t<=n;t++){
		if(r[t]>r[h]){
			ans--;
			h++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
ll r[N],cnt[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>r[i];
	ll mx=0;
	for(ll i=1;i<=n;i++)
		cnt[r[i]]++;
	for(ll i=1;i<=n;i++)
		mx=max(mx,cnt[r[i]]);
	cout<<mx<<endl;
	return 0;
}

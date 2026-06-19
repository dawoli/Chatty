#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll n;
ll a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ll r=1;
	ll ans=n;
	for(int l=1;l<=n;l++){
		while(a[l]>=a[r]&&r<=n)
			r++;
		if(r==n+1)
			break;
		r++;
		ans--;
	}
	cout<<ans;
	return 0;
}


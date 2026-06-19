#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(ll x1,ll x2){
	return x1>x2;
}

const ll biao=1e6+10;
ll a[biao],n,m; 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	ll aa=a[1],loc;
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++) if(a[i]==aa) loc=i;
	
	ll c=(loc+n-1)/n,r=c*n-loc+1;
	if(c%2) r=n-r+1;
	if(!r) r=n;
	cout<<c<<" "<<r;
	
	return 0;
}

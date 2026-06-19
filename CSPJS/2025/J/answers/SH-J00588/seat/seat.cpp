#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=19;
ll n,m,a[N*N],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	b=1;
	for(ll i=1;i<=n*m;++i){
		cin>>a[i];
		if(a[i]>a[1])b++;
	}
	ll l=(b-1)/n+1;
	cout<<l<<" ";
	if(l&1){
		cout<<(b-1)%n+1<<"\n";
	}
	else{
		cout<<n-(b-1)%n<<"\n";
	}
	return 0;
}

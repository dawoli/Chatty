#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll a,ans=0;
	cin>>a;
	for(int i=0;i<n*m-1;i++){
		ll tmp;
		cin>>tmp;
		if(tmp>a){
			ans++;
		} 
	}
	if(ans/n%2==0){
		cout<<ans/n+1<<' '<<ans%n+1;
	}else{
		cout<<ans/n+1<<' '<<n-ans%n;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll m;
ll k;
ll cnt;
ll x[10009];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n*m;i++){
		cin>>x[i];
	}
	k=x[0];
	sort(x,x+n*m);
	for(ll i=0;i<n*m/2;i++){
		swap(x[i],x[n*m-i-1]);
	}
	for(ll i=0;i<n*m;i++){
		if(x[i]==k)cnt=i;
	}
	cout<<cnt/n+1<<" ";
	if((cnt/n+1)%2){
		cout<<cnt%n+1;
	}else cout<<n-cnt%n;
	return 0;
}

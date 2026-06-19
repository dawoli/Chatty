#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n;
ll a[21]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++){
		cin>>n;
		ll d=n%7;
		if(n<21){
			cout<<a[n]<<endl;
			continue;
		}
		if(d==0){
			for(ll i=1;i<=n/7;i++){
				cout<<8;
			}
		}
		else if(d==1){
			cout<<10;
			for(ll i=1;i<=(n-8)/7;i++){
				cout<<8;
			}
		}
		else if(d==2){
			cout<<1;
			for(ll i=1;i<=(n-2)/7;i++){
				cout<<8;
			}
		}
		else if(d==3){
			cout<<200;
			for(ll i=1;i<=(n-19)/7;i++){
				cout<<8;
			}
		}
		else if(d==4){
			cout<<20;
			for(ll i=1;i<=(n-13)/7;i++){
				cout<<8;
			}
		}
		else if(d==5){
			cout<<2;
			for(ll i=1;i<=(n-5)/7;i++){
				cout<<8;
			}
		}
		else{
			cout<<6;
			for(ll i=1;i<=(n-6)/7;i++){
				cout<<8;
			}
		}
		cout<<endl;
	}
	return 0;
} 

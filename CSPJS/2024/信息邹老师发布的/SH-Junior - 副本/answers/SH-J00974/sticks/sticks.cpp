#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n==1)cout<<"-1";
		else{
			ll x=n%7;
			if(x==0){
				for(ll i = 7;i <= n;i+=7)cout<<8;
			}
			if(x==1){
				cout<<10;
				n-=8;
				for(ll i = 7;i <= n;i+=7)cout<<8;
			}
			if(x==2){
				cout<<1;
				n-=2;
				for(ll i = 7;i <= n;i+=7)cout<<8;
			}
			if(x==3){
				if(n==3)cout<<7;
				if(n==10)cout<<22;
				if(n>=17){
					cout<<200;
					n-=17;
					for(ll i = 7;i <= n;i+=7)cout<<8;
				}
			}
			if(x==4){
				if(n==4)cout<<4;
				else{
					cout<<20;
					n-=10;
					for(ll i = 7;i <= n;i+=7)cout<<8;
				}
			}
			if(x==5){
				cout<<2;
				n-=5;
				for(ll i = 7;i <= n;i+=7)cout<<8;
			}
			if(x==6){
				cout<<6;
				n-=6;
				for(ll i = 7;i <= n;i+=7)cout<<8;
			}
		}
		cout<<'\n'; 
	}
	return 0;
}

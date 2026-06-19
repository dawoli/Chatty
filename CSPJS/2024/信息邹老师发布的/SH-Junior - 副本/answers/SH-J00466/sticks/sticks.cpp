#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=19;
ll st[N]={6,2,5,5,4,5,6,3,7,6};
ll n;
void solven7(){
	for(ll i=1;i<=n/7;i++)
		cout<<8;
	cout<<endl;
}
void solve(){
	if(n%7==0){
		for(ll i=1;i<=n/7;i++)
			cout<<8;
		cout<<endl;
	}
	else if(n%7==2){
		cout<<1;
		for(ll i=1;i<=(n-2)/7;i++)
			cout<<8;
		cout<<endl;
	}
	else if(n%7==3){
		if(n==3){
			cout<<7<<endl;
		}
		else if(n==10){
			cout<<22<<endl;
		}
		else{
			cout<<200;
			for(ll i=1;i<=(n-17)/7;i++)
				cout<<8;
			cout<<endl;
		}
	}
	else if(n%7==1){
		if(n==1){
			cout<<-1<<endl;
		}
		else{
			cout<<10;
			for(ll i=1;i<=(n-8)/7;i++)
				cout<<8;
			cout<<endl;
		}
	}
	else if(n%7==4){
		if(n==4){
			cout<<4<<endl;
		}
		else{
			cout<<20;
			for(ll i=1;i<=(n-11)/7;i++)
				cout<<8;
			cout<<endl;
		}
	}
	else if(n%7==5){
		cout<<2;
		for(ll i=1;i<=(n-5)/7;i++)
			cout<<8;
		cout<<endl;
	}
	else if(n%7==6){
		cout<<6;
		for(ll i=1;i<=(n-6)/7;i++)
			cout<<8;
		cout<<endl;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0)
			solven7();
		else
			solve();
	}
	return 0;
}

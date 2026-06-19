#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll sticks[15]={6,2,5,5,4,5,6,3,7,6};
ll st(ll w){
	ll cnt=0;
	while(w>0){
		cnt+=sticks[w%10];
		w/=10;
	}
	return cnt;
}
ll sum(ll a){
	if(a<=1){
		cout<<-1;
		return 0;
	}
	if(a<=20){
		for(int i=1;;i++)
			if(st(i)==a){
				cout<<i;
				return 0;
			}
	}
	else{
		if(a%7==0){
			a-=0;
		}
		if(a%7==1){
			a-=8;
			cout<<10;
		}
		if(a%7==2){
			a-=2;
			cout<<1;
		}
		if(a%7==3){
			a-=17;
			cout<<200;
		}
		if(a%7==4){
			a-=11;
			cout<<20;
		}
		if(a%7==5){
			a-=5;
			cout<<2;
		}
		if(a%7==6){
			a-=6;
			cout<<6;
		}
		while(1){
			a-=7;
			if(a>=0)cout<<8;
			else break;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll s;
		cin>>s;
		sum(s);
		cout<<endl;
	}
	return 0;
}

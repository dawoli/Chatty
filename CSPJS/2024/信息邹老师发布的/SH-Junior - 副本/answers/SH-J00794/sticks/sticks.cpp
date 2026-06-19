#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll add(ll ans,ll kk){
	ll k=kk;
	ll t=ans%10;
	if(ans==0){
		return k;
	}
	if(t==1){
		k+=2;
	}else if(t==7){
		k+=3;
	}else if(t==4){
		k+=4;
	}else if(t==2 || t==3 || t==5){
		k+=5;
	}else if(t==0 || t==6 || t==9){
		k+=6;
	}else{
		k+=7;
	}
	ans=ans/10;
	add(ans,k);
}
void solve8(ll n){
	ll ans=n/7;
	for(ll i=1;i<=ans;i++){
		cout<<8;
	}
	cout<<endl;
}
void solve108(ll n){
	ll ans=n/7;
	cout<<10;
	for(ll i=2;i<=ans;i++){
		cout<<8;
	}
	cout<<endl;
}
void solvebf(ll n){
	ll ans=1;
	while(1){
		if(add(ans,0)==n){
			cout<<ans<<endl;
			break;
		}else{
			ans++;
		}
	}
}
void solve(ll n){
	solvebf(n);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll t,n;
	cin>>t;
	for(ll k=1;k<=t;k++){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
		}else if(n%7==0){
			solve8(n);
		}else if(n<=50){
			solvebf(n);
		}else if(n%7==1){
			solve108(n);
		}else{
			solve(n);
		}
	}
	return 0;
}

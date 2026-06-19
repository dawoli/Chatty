#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
using namespace std;
ll n;
int d[10]={6,2,5,5,4,5,6,3,7,6}; 
void solve(){
	cin>>n;
	if(n<=1){
		cout<<-1<<'\n';
		return;
	}
	rep(i,1,9)
		if(d[i]==n){
			cout<<i<<'\n';
			return;
		}
	int l=n/7,a=n%7;
	if(a==0){//
		rep(i,1,l)cout<<8;
	}
	else if(a==1){//
		cout<<1<<0;
		rep(i,1,l-1)cout<<8;
	}
	else if(a==2){//
		cout<<1;
		rep(i,1,l)cout<<8;
	}
	else if(a==3){//
		if(n==10)cout<<22;
		else{
			cout<<200;
			rep(i,1,l-2)cout<<8;
		}
	}
	else if(a==4){//
		cout<<20;
		rep(i,1,l-1)cout<<8;
	}
	else if(a==5){//
		cout<<2;
		rep(i,1,l)cout<<8;
	}
	else if(a==6){//
		cout<<6;
		rep(i,1,l)cout<<8;
	}
	cout<<'\n';
}
signed main(){
	int TEST;
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>TEST;
	while(TEST--)
		solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

//const int need[]={6,2,5,5,4,5,6,3,7,6};
const int num[]={0,-1,1,7,4,2,6,8,0,18,22,20,28,60};
int T,n;

void solve(){
	if (n<=7) cout<<num[n];
	else if (n%7==0){
		auto digits=n/7;
		for (int i=0; i<digits; i++){
			cout<<8;
		}
	}
	else if (n%7==1){
		auto digits=n/7;
		cout<<10;
		for (int i=1; i<digits; i++){
			cout<<8;
		}
	}
	else {
		auto digits=n/7;
		n-=(digits-1)*7;
		cout<<num[n];
		for (int i=1; i<digits; i++){
			cout<<8;
		}
	}
	
	cout<<'\n';
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>T;
	for (int i=0; i<T; i++){
		cin>>n;
		solve();
	}
}

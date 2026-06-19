#include<bits/stdc++.h>
using namespace std;
int t,n;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n<7) {
			if(n==1) cout<<-1<<"\n";
			if(n==2) cout<<1<<"\n";
			if(n==3) cout<<7<<"\n";
			if(n==4) cout<<4<<"\n";
			if(n==5) cout<<2<<"\n";
			if(n==6) cout<<6<<"\n";
		}
		else if(n%7==0) {
			for(int i=1;i<=n/7;++i) cout<<8;
			cout<<"\n";
		}
		else {
			if(n%7==1) cout<<10;
			if(n%7==2) cout<<18;
			if(n%7==3) cout<<23;
			if(n%7==4) cout<<20;
			if(n%7==5) cout<<28;
			if(n%7==6) cout<<68;
			for(int i=1;i<n/7;++i) cout<<8;
			cout<<"\n";
		}
	}
	return 0;
}

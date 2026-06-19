#include<bits/stdc++.h>
using namespace std;
int t,n;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) {
		cin>>n;
		if(n%7==0) {
			for(int i=1;i<=n/7;i++) {
				cout<<8;
			}
		}
		if(n%7==1) {
			cout<<16;
			if(n!=8) {
				for(int i=1;i<n/7;i++) {
					cout<<8;
				}
			}
		}
		if(n%7!=0 and n%7!=1) {
			cout<<-1;
		}
	}
	return 0;
}

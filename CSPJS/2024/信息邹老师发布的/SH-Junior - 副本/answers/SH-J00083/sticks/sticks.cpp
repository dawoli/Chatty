#include <cstdio>
#include <iostream>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int ans[21]={0,-1,1,7,4,2,
				6,8,10,18,22,
				20,28,68,88,108,
				188,200,208,288,688};
int n;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t; cin>>t;
	while(t--) {
		cin>>n;
		if(n<=20) {cout<<ans[n]<<endl; continue;}
		if(n%7==0) {
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
			continue;
		}
		int w=n/7+1;
		cout<<ans[14+n%7];
		for(int i=1;i<=w-3;i++) cout<<8;
		cout<<endl;
	}
	return 0;
}

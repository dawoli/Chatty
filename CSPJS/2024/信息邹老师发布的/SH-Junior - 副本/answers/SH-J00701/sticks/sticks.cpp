#include<bits/stdc++.h>
using namespace std;
long long T,n,ans[]= {0,-1,1,7,4,2,6,8,10,18,22,20};
void solve(long long x) {
	if(x%7==0)
		for(long long i=1; i<=x/7; i++)
			cout<<8;
	if(x%7==1) {
		cout<<10;
		for(long long i=1; i<=x/7-1; i++)
			cout<<8;
	}
	if(x%7==2) {
		cout<<1;
		for(long long i=1; i<=x/7; i++)
			cout<<8;
	}
	if(x%7==3) {
		cout<<200;
		for(long long i=1; i<=x/7-2; i++)
			cout<<8;
	}
	if(x%7==4) {
		cout<<20;
		for(long long i=1; i<=x/7-1; i++)
			cout<<8;
	}
	if(x%7==5) {
		cout<<2;
		for(long long i=1; i<=x/7; i++)
			cout<<8;
	}
	if(x%7==6) {
		cout<<6;
		for(long long i=1; i<=x/7; i++)
			cout<<8;
	}
	cout<<endl;
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		if(n<=1) {
			cout<<-1<<endl;
			continue;
		} 
		if(n<=10) {
			cout<<ans[n]<<endl;
			continue;
		}
		solve(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

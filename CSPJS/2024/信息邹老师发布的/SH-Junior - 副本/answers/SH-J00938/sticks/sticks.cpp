#include<bits/stdc++.h>
using namespace std;

int need[10]={6,2,5,5,4,5,6,3,7,6}, t, n;
int num[30]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>t;
	for(int nxx=1;nxx<=t;nxx++) {
		cin>>n;
		if(n<=21) {
			cout<<num[n]<<endl;
			continue;
		}
		if(n%7==1) {
			cout<<"10";
			for(int i=1;i<=n/7-1;i++) cout<<'8';
			cout<<endl;
		}
		if(n%7==2) {
			cout<<"1";
			for(int i=1;i<=n/7;i++) cout<<'8';
			cout<<endl;
		}
		if(n%7==3) {
			cout<<"200";
			for(int i=1;i<=n/7-2;i++) cout<<'8';
			cout<<endl;
		}
		if(n%7==4) {
			cout<<"20";
			for(int i=1;i<=n/7-1;i++) cout<<'8';
			cout<<endl;
		}
		if(n%7==5) {
			cout<<"2";
			for(int i=1;i<=n/7;i++) cout<<'8';
			cout<<endl;
		}
		if(n%7==6) {
			cout<<"6";
			for(int i=1;i<=n/7;i++) cout<<'8';
			cout<<endl;
		}
		if(n%7==0) {
			for(int i=1;i<=n/7;i++) cout<<'8';
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

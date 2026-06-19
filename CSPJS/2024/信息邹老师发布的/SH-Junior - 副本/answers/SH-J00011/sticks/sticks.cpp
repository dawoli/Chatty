#include<bits/stdc++.h>
using namespace std;

int used[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
int m[10]={0,0,1,7,4,2,6,8};

int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n%7==0) {
			for(int i=1;i<=n/7;i++) cout<<'8';
			cout<<'\n';
			continue;
		}else if(n==1) {
			cout<<"-1\n";
		}else if(n==3) {
			cout<<"7\n";
		}else if(n==4) {
			cout<<"4\n";
		}else {
			int x=n%7;
			if(n/7==0) {
				if(x==6) cout<<6<<'\n';
				else cout<<m[x]<<'\n';
				continue;
			}
			if(x==0) {
				for(int i=1;i<=n/7;i++) cout<<'8';
				cout<<'\n';continue;
			}
			if(x==2||x==5||x==6) {
				cout<<m[x];for(int i=1;i<=n/7;i++) cout<<'8';
				cout<<'\n';continue;
			}
			if(x==3) {
				if(n/7==1) {
					cout<<"22\n";
				}else {
					cout<<"200";for(int i=3;i<=n/7;i++) cout<<'8';
					cout<<'\n';
				}
				continue;
			}
			cout<<m[x+1]<<'0'; 
			for(int i=2;i<=n/7;i++) cout<<'8';
			cout<<'\n';
		}
	}
	return 0;
}

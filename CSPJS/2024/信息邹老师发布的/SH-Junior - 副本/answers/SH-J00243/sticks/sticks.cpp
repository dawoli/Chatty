#include <iostream>
#include <cstdio>
using namespace std;
int t,n,num[7]={0,-1,1,7,4,2,6};
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n<7) {
			cout<<num[n]<<endl;
			continue;
		}
		if(n%7==0) {
			for(int i=0;i<n;i+=7) {
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1) {
			cout<<10;
			for(int i=8;i<n;i+=7) {
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==2) {
			cout<<1;
			for(int i=2;i<n;i+=7) {
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==3) {
			cout<<22;
			for(int i=10;i<n;i+=7) {
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==4) {
			cout<<20;
			for(int i=11;i<n;i+=7) {
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==5) {
			cout<<2;
			for(int i=5;i<n;i+=7) {
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==6) {
			cout<<6;
			for(int i=6;i<n;i+=7) {
				cout<<8;
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

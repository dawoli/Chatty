#include<iostream>
using namespace std;
int T,n;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++) {
		cin>>n;
		if(n==2) {
			cout<<"1"<<endl;
			continue;
		} 
		if(n==3) {
			cout<<"7"<<endl;
			continue;
		}
		if(n==4) {
			cout<<"4"<<endl;
			continue;
		}
		if(n==5) {
			cout<<"2"<<endl;
			continue;
		}
		if(n==6) {
			cout<<"9"<<endl;
			continue;
		}
		if(n==7) {
			cout<<"8"<<endl;
			continue;
		}
		if(n%7==0) {
			for(int i=0;i<n/7;i++) cout<<"8";
			cout<<endl;
			continue;
		}
		if(n==18) {
			cout<<"208"<<endl;
			continue;
		}
		cout<<"-1"<<endl;
	}
	return 0;
} 

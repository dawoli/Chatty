#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n;
		if(n==0||n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0)
			for(int j=1;j<=n/7;++j)
				cout<<8;
		if(n%7==1){
			cout<<10;
			for(int j=1;j<=n/7-1;++j)
				cout<<8;
		}
		if(n%7==2){
			cout<<1;
			for(int j=1;j<=n/7;++j)
				cout<<8;
		}
		if(n%7==3){
			if(n==3)
				cout<<7;
			if(n==10)
				cout<<22;
			if(n>10){
				cout<<200;
				for(int j=1;j<=n/7-2;++j)
					cout<<8;
			}
		}
		if(n%7==4){
			if(n==4)
				cout<<4;
			if(n>4){
				cout<<20;
				for(int j=1;j<=n/7-1;++j)
					cout<<8;
			}
		}
		if(n%7==5){
			cout<<2;
			for(int j=1;j<=n/7;++j)
				cout<<8;
		}
		if(n%7==6){
			cout<<6;
			for(int j=1;j<=n/7;++j)
				cout<<8;
		}
		cout<<endl;
	}
	return 0;
}

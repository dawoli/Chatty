#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		if(n==1){
			cout<<"-1"<<endl;
			continue;
		}
		if(n%7==0){
			int a=n/7;
			for(int j=0;j<a;j++) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==1){
			cout<<10;
			int a=n/7-1;
			for(int j=0;j<a;j++) cout<<8;
			cout<<endl;
			continue; 
		}
		if(n%7==2){
			cout<<1;
			int a=n/7;
			for(int j=0;j<a;j++) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==3){
			if(n==3){
				cout<<7<<endl;
				continue;
			}
			if(n==10){
				cout<<22<<endl;
				continue;
			}
			cout<<200;
			int a=n/7-2;
			for(int j=0;j<a;j++) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==4){
			if(n==4){
				cout<<4<<endl;
				continue;
			}
			cout<<20;
			int a=n/7-1;
			for(int j=0;j<a;j++) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==5){
			cout<<2;
			int a=n/7;
			for(int j=0;j<a;j++) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==6){
			cout<<6;
			int a=n/7;
			for(int j=0;j<a;j++) cout<<8;
			cout<<endl;
			continue;
		}
	}
	return 0;
}

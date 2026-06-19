#include<bits/stdc++.h>
using namespace std;
int T,n,y;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		y=n%7;
		if(y==0){
			for(int j=1;j<=n/7;j++)	cout<<8;
		}
		if(y==1){
			cout<<10;
			for(int j=1;j<=(n-8)/7;j++) cout<<8;
		}
		if(y==2){
			cout<<1;
			for(int j=1;j<=(n-2)/7;j++) cout<<8;
		}
		if(y==3){
			if(n==3) cout<<7;
			else if(n==10) cout<<22;
			else{
				cout<<200;
				for(int j=1;j<=(n-17)/7;j++) cout<<8;
			}
		}
		if(y==4){
			if(n==4) cout<<4;
			else{
				cout<<20;
				for(int j=1;j<=(n-11)/7;j++) cout<<8;
			}
		}
		if(y==5){
			cout<<2;
			for(int j=1;j<=(n-5)/7;j++) cout<<8;
		}
		if(y==6){
			cout<<6;
			for(int j=1;j<=(n-6)/7;j++) cout<<8;
		}
		cout<<endl;
	}
	return 0;
}

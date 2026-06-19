#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<8){
			if(n==1)cout<<-1<<endl;
			if(n==2)cout<<1<<endl;
			if(n==3)cout<<7<<endl;
			if(n==4)cout<<4<<endl;
			if(n==5)cout<<2<<endl;
			if(n==6)cout<<6<<endl;
			if(n==7)cout<<8<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==1){
			cout<<10;
			for(int i=1;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
} 

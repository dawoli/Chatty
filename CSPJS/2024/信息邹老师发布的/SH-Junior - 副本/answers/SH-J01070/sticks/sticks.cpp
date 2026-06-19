#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int x=n/7;
		if(n%7==0){
			for(int i=1;i<=x;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==1){
			if(n==1) cout<<-1<<endl;
			else{
				cout<<10;
				for(int i=1;i<=x-1;i++) cout<<8;
				cout<<endl;
			}
		}
		else if(n%7==2){
			cout<<1;
			for(int i=1;i<=x;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==3){
			if(n==3) cout<<7<<endl;
			else if(n==10) cout<<22<<endl;
			else {
				cout<<200;
				for(int i=1;i<=x-2;i++) cout<<8;
				cout<<endl;
			}
		}
		else if(n%7==4){
			if(n==4) cout<<4<<endl;
			else{
				cout<<20;
				for(int i=1;i<=x-1;i++) cout<<8;
				cout<<endl;
			} 
		}
		else if(n%7==5){
			cout<<2;
			for(int i=1;i<=x;i++) cout<<8;
			cout<<endl;
		}
		else{
			cout<<6;
			for(int i=1;i<=x;i++) cout<<8;
			cout<<endl;
		}
	}
}

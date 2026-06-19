#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1) cout<<-1<<endl;
		else if(n==2) cout<<1<<endl;
		else if(n==3) cout<<7<<endl;
		else if(n==4) cout<<4<<endl;
		else if(n==5) cout<<2<<endl;
		else if(n==6) cout<<6<<endl;
		else if(n==7) cout<<8<<endl;
		else if(n==10) cout<<22<<endl;
		else{
			if(n%7==0){
				for(int i=1;i<=n/7;i++){
					cout<<8;
				}
				cout<<endl;
			}
			if(n%7==1){
				cout<<10;
				for(int i=2;i<=n/7;i++) cout<<8;
				cout<<endl;
			}
			if(n%7==2){
				cout<<1;
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
			}
			if(n%7==3){
				cout<<200;
				for(int i=3;i<=n/7;i++) cout<<8;
				cout<<endl;
			}
			if(n%7==4){
				cout<<20;
				for(int i=2;i<=n/7;i++) cout<<8;
				cout<<endl;
			}
			if(n%7==5){
				cout<<2;
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
			}
			if(n%7==6){
				cout<<6;
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
			}
		}
	}
}

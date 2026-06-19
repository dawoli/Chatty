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
		if(n<7){
			if(n==1) cout<<-1<<endl;
			if(n==2) cout<<1<<endl;
			if(n==3) cout<<7<<endl;
			if(n==4) cout<<4<<endl;
			if(n==5) cout<<2<<endl;
			if(n==6) cout<<6<<endl;
		}
		else if(n%7==0){
			for(int k=0;k<n/7;k++){
				cout<<'8';
			}cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			for(int k=0;k<n/7-1;k++){
				cout<<8;
			}cout<<endl;
		}
		else if(n%7==2){
			cout<<1;
			for(int k=0;k<n/7;k++){
				cout<<8;
			}cout<<endl;
		}
		else if(n%7==3){
			cout<<19;
			for(int k=0;k<n/7-1;k++){
				cout<<8;
			}cout<<endl;
		}
		else if(n%7==4){
			cout<<20;
			for(int k=0;k<n/7-1;k++){
				cout<<8;
			}cout<<endl;
		}
		else if(n%7==5){
			cout<<2;
			for(int k=0;k<n/7;k++){
				cout<<8;
			}cout<<endl;
		}
		else{
			 cout<<68;
			 for(int k=0;k<n/7-1;k++){
				cout<<8;
			}cout<<endl;
		}
	}
}

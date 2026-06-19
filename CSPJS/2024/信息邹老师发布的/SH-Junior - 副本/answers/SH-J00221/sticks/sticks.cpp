#include<bits/stdc++.h>
using namespace std;
long long g[10]={6,2,5,5,4,5,6,3,7,6};
long long t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1;
		}
		else if(n==4){
			cout<<4;
		}
		else if(n==3){
			cout<<7;
		}
		else if(n==10){
			cout<<22;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=n/7-1;i++){
				cout<<8;
			}
		}
		else if(n%7==2){
			cout<<1;
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
		}
		else if(n%7==3){
			cout<<200;
			for(int i=1;i<=n/7-2;i++){
				cout<<8;
			}
		}
		else if(n%7==4){
			cout<<20;
			for(int i=1;i<=n/7-1;i++){
				cout<<8;
			}
		}
		else if(n%7==5){
			cout<<2;
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
		}
		else if(n%7==6){
			cout<<6;
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
		}
		cout<<endl;
	}
} 

#include<bits/stdc++.h>
using namespace std;
long long nd[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		if(n<=7){
			if(n==1) cout<<-1<<endl;
			if(n==2) cout<<1<<endl;
			if(n==3) cout<<7<<endl;
			if(n==4) cout<<4<<endl;
			if(n==5) cout<<2<<endl;
			if(n==6) cout<<6<<endl;
			if(n==7) cout<<8<<endl;
		}
		else if(n<=50 and n>7){
			for(long long i=1;i<=50000;i++){
				long long cck=0;
				long long temp=i;
				while(temp){
					cck+=nd[temp%10];
					temp/=10;
				}
				if(cck==n){
					cout<<i<<endl;
					break;
				}
			}
		}
		else{
			if(n%7==0){
				for(long long i=1;i<=n/7;i++){
					cout<<8;
				}
				cout<<endl;
			}
			else if(n%7==1){
				for(long long i=1;i<=n/7-1;i++){
					cout<<8;
				}
				cout<<22<<endl;
			} 
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	int t;cin>>t;
	while(t--){
		cin>>n;
		if(n==0||n==1){cout<<-1<<endl;continue;}
		if(n==2){cout<<1<<endl;continue;}
		if(n==3){cout<<7<<endl;continue;}
		if(n==4){cout<<4<<endl;continue;}
		if(n==5){cout<<2<<endl;continue;}
		if(n==6){cout<<6<<endl;continue;}
		if(n==7){cout<<8<<endl;continue;}
		if(n%7==0){
			ll p=n/7;
			for(ll i=1;i<=p;i++)cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==1){
			ll p=(n-8)/7;
			cout<<10;
			for(ll i=1;i<=p;i++)cout<<8;
			cout<<endl;continue;
		}
		if(n%7==2){
			ll p=(n-2)/7;
			cout<<1;
			for(int i=1;i<=p;i++)cout<<8;
			cout<<endl;	continue;
		}
		if(n%7==3){
			ll p=(n-10)/7;
			cout<<23;
			for(int i=1;i<=p;i++)cout<<8;
			cout<<endl;continue;
		}
		if(n%7==4){
			ll p=(n-11)/7;cout<<20;
			for(int i=1;i<=p;i++)cout<<8;
			cout<<endl;continue; 
		}
		if(n%7==5){
			ll p=(n-5)/7;cout<<2;
			for(int i=1;i<=p;i++)cout<<8;
			cout<<endl;continue;
		}
		if(n%7==6){
			ll p=(n-6)/7;cout<<6;
			for(int i=1;i<=p;i++)cout<<8;
			cout<<endl;continue; 
		}
	}
	return 0;
}

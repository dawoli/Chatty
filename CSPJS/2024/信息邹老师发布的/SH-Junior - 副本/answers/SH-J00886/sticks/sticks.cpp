#include<bits/stdc++.h>
using namespace std;
int st[10];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		int n;
		cin>>n;
		if(n/7>0){	
			if(n%7==0){
				for(int i=1;i<=n/7;i++)cout<<8;
			}
			else if(n%7==1){
				cout<<1;
				cout<<0;
				for(int i=1;i<n/7;i++)cout<<8;
			}
			else if(n%7==2){
				cout<<1;
				for(int i=1;i<=n/7;i++)cout<<8;
			}
			else if(n%7==3){
				cout<<22;
				for(int i=1;i<n/7;i++)cout<<8;
			}
			else if(n%7==4){
				cout<<20;
				for(int i=1;i<n/7;i++)cout<<8;
			}
			else if(n%7==5){
				cout<<2;
				for(int i=1;i<=n/7;i++)cout<<8;
			}
			else if(n%7==6){
				cout<<6;
				for(int i=1;i<=n/7;i++)cout<<8;
			}
		}
		else{
			if(n==1)cout<<-1;
			if(n==2)cout<<1;
			if(n==3)cout<<7;
			if(n==4)cout<<4;
			if(n==5)cout<<2;
			if(n==6)cout<<6;
		}
		cout<<endl;
	}
	return 0;
}

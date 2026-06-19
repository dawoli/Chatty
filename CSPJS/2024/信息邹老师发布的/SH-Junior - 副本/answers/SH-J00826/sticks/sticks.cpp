#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		if(n==0||n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int j=0;j<n/7;j++){
				cout<<8;
			}
		}else if(n%7==1){
			cout<<10;
			for(int j=0;j<(n-8)/7;j++){
				cout<<8;
			}
		}else if(n%7==2){
			cout<<1;
			for(int j=0;j<(n-2)/7;j++){
				cout<<8;
			}
		}else if(n%7==3){
			if(n/7==0){
				cout<<7;
			}else if(n/7==1){
				cout<<22;
			}else{
				cout<<200;
				for(int j=0;j<(n-17)/7;j++){
					cout<<8;
				}
			}
		}else if(n%7==4){
			if(n==4){
				cout<<4;
			}else{
				cout<<20;
				for(int j=0;j<(n-11)/7;j++){
					cout<<8;
				}
			}
		}else if(n%7==5){
			cout<<2;
			for(int j=0;j<(n-5)/7;j++){
				cout<<8;
			}
		}else{
			cout<<6;
			for(int j=0;j<(n-6)/7;j++){
				cout<<8;
			}	
		}
		cout<<endl;
	}
}


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
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==2){
			cout<<1<<endl;
			continue;
		}
		if(n==3){
			cout<<7<<endl;
			continue;
		}
		if(n==4){
			cout<<4<<endl;
			continue;
		}
		if(n==5){
			cout<<2<<endl;
			continue;
		}
		if(n==6){
			cout<<6<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=7;i<=n;i+=7){
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==1){
			cout<<10<<endl;
			for(int i=7;i<=n-14;i+=7){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks1.in","r",stdin);
	freopen("sticks.out","w", stdout);
	long long int n;
	long long int T;
	cin >> T;
	for (int x=0;x<T;x++) {
		cin >> n;
		if (n<2){
			cout<<-1;
		}
		else if (n>=2 && n<=7){
			if (n==2) cout<<1;
			if (n==3) cout<<7;
			if (n==4) cout<<4;
			if (n==5) cout<<5;
			if (n==6) cout<<6;
			if (n==7) cout<<8;
		}
		else if (n%7==0){
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
		}
		else if (n%7==6){
			cout<<6;
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
		}
		else if (n%7==1){
			cout<<10;
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}
		}
		else if (n%7==4){
			cout<<20;
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}
		}
		else if (n%7==2){
			cout<<18;
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}
		}
		else if (n%7==3){
			cout<<40;
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}
		}
		else if (n%7==5){
			cout<<28;
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}
		}
		else{
			cout<<-1;
		}
		if(x!=T-1){
			cout<<"\n";
		}
	}
	return 0;
}

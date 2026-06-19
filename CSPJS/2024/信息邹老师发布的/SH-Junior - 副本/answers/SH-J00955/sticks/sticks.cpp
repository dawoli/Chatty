#include<bits/stdc++.h>
using namespace std;
int n,t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for (int l=1;l<=t;l++){
		cin>>n;
		if (n<=1) {
		cout<<-1<<endl;
		continue;
	}	
	if (n==2) {
		cout<<1<<endl;
		continue;
	}
	if (n==3) {
		cout<<7<<endl;
		continue;
	}
	if (n==4) {
		cout<<4<<endl;
		continue;
	}
	if (n==5) {
		cout<<2<<endl;
		continue;
	}
	if (n==6) {
		cout<<6<<endl;
		continue;
	}
	if (n==7) {
		cout<<8<<endl;
		continue;
	}
		
		if (n%7==0){
			for (int i=n;i>0;i=i-7){
				cout<<8;
			}
			cout<<endl;
			continue;
		}//ok
		if (n%7==1){
			cout<<10;
			for (int i=n-8;i>0;i=i-7){
				cout<<8;
			}
			cout<<endl;
			continue;
		}//ok
		if (n%7==2){
			cout<<1;
			for (int i=n-2;i>0;i=i-7){
				cout<<8;
			}
			cout<<endl;
			continue;
		}//ok
		if (n%7==3){
			cout<<22;
			for (int i=n-10;i>0;i=i-7){
				cout<<8;
			}
			cout<<endl;
			continue;
		}//ok
		if (n%7==4){
			cout<<20;
			for (int i=n-11;i>0;i=i-7){
				cout<<8;
			}
			cout<<endl;
			continue;
		}//ok
		if (n%7==5){
			cout<<2;
			for (int i=n-5;i>0;i=i-7){
				cout<<8;
			}
			cout<<endl;
			continue;
		}//ok
		if (n%7==6){
			cout<<6;
			for (int i=n-6;i>0;i=i-7){
				cout<<8;
			}
			cout<<endl;
			continue;
		}//ok
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

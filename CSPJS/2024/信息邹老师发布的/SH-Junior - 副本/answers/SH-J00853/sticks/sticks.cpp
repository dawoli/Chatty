#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n<=1){
			cout<<-1<<endl;
		}
		if(n%7==0&&n>1){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==1&&n>1){
			cout<<1;
			for(int i=1;i<=(n-1)/7-1;i++){
				cout<<8;
			}
			cout<<0<<endl;
		}
		if(n%7==2&&n>20){
			cout<<1;
			for(int i=1;i<=(n-2)/7;i++){
				cout<<8;
			}
			cout<<endl;
		} 
		if(n==2){
			cout<<1<<endl;
		}
		if(n==3){
			cout<<7<<endl;
		}
		if(n==4){
			cout<<4<<endl;
		}
		if(n==5){
			cout<<2<<endl;
		}
		if(n==6){
			cout<<6<<endl;
		}
		if(n==10){
			cout<<22<<endl;
		}
		if(n==11){
			cout<<20<<endl;
		}
		if(n==12){
			cout<<28<<endl;
		}
		if(n==13){
			cout<<80<<endl;
		}
		if(n==17){
			cout<<200<<endl;
		}
		if(n==18){
			cout<<208<<endl;
		}
		if(n==19){
			cout<<288<<endl;
		}
		if(n==20){
			cout<<688<<endl;
		}
		
	}
	return 0;
}

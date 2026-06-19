#include<bits/stdc++.h>
using namespace std;

int n,T;


int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		if(n==1) cout<<-1<<endl;
		if(n%7==0&&n>=100){
			for(int j=0;j<n/7;j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7==1&&n>=100){
			cout<<10;
			for(int j=0;j<n/7-1;j++){
				cout<<8;
		}
		cout<<endl;
		continue;
	}
	if(n==2) cout<<1<<endl;
	if(n==3) cout<<7<<endl;
	if(n==4) cout<<4<<endl;
	if(n==5) cout<<2<<endl;
	if(n==6) cout<<6<<endl;
	if(n==7) cout<<8<<endl;
	if(n==8) cout<<10<<endl;
	if(n==9) cout<<24<<endl;
	if(n==10) cout<<22<<endl;
	if(n==11) cout<<20<<endl;
	if(n==12) cout<<28<<endl;
	if(n==13) cout<<80<<endl;
	if(n==14) cout<<88<<endl;
	if(n==15) cout<<108<<endl;
	if(n==16) cout<<188<<endl;
	if(n==17) cout<<200<<endl;
	if(n==18) cout<<208<<endl;
	if(n==19) cout<<288<<endl;
	if(n==20) cout<<688<<endl;
	if(n>=20){
		if(n%7==1){
			cout<<108;
			for(int i=0;i<n/7-3;i++){
				cout<<8;
			}
		}
		if(n%7==2){
			cout<<188;
			for(int i=0;i<n/7-3;i++){
				cout<<8;
			}
		}
		if(n%7==3){
			cout<<200;
			for(int i=0;i<n/7-3;i++){
				cout<<8;
			}
		}
		if(n%7==4){
			cout<<208;
			for(int i=0;i<n/7-3;i++){
				cout<<8;
			}
		}
		if(n%7==5){
			cout<<288;
			for(int i=0;i<n/7-3;i++){
				cout<<8;
			}
		}
		if(n%7==6){
			cout<<688;
			for(int i=0;i<n/7-3;i++){
				cout<<8;
			}
		}
		if(n%7==0){
			cout<<888;
			for(int i=0;i<n/7-3;i++){
				cout<<8;
			}
		}
		
	}
}
	return 0;
}

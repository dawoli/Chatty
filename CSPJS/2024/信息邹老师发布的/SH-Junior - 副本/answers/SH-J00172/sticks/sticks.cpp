#include<bits/stdc++.h>
using namespace std;
long long T,N;
long long Stick[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>N;
		if(N<2){cout<<-1<<endl;continue;}
		if(N%7==0){
			for(int i=1;i<=N/7;i++) cout<<8;
		}
		else if(N%7==1){
			cout<<10;
			for(int i=1;i<=(N-8)/7;i++) cout<<8;
		}
		else if(N%7==2){
			cout<<1;
			for(int i=1;i<=(N-2)/7;i++) cout<<8;
		}
		else if(N%7==3){
			if(N==3) cout<<7;
			else if(N==10) cout<<22;
			else{
				cout<<200;
				for(int i=1;i<=(N-17)/7;i++) cout<<8;
			}
		}
		else if(N%7==4){
			if(N==4) cout<<4;
			else{
				cout<<20;
				for(int i=1;i<=(N-11)/7;i++) cout<<8;
			}
		}
		else if(N%7==5){
			cout<<2;
			for(int i=1;i<=(N-5)/7;i++) cout<<8;
		}
		else{
			cout<<6;
			for(int i=1;i<=(N-6)/7;i++) cout<<8;
		}
		cout<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n==1) cout<<-1<<endl;
		else if(n==2) cout<<1<<endl;
		else if(n==3) cout<<7<<endl;
		else if(n==4) cout<<4<<endl;
		else if(n==5) cout<<2<<endl;
		else if(n==6) cout<<6<<endl;
		else if(n==7) cout<<8<<endl;
		else if(n==8) cout<<10<<endl;
		else if(n==9) cout<<18<<endl;
		else if(n==10) cout<<22<<endl;
		else if(n==11) cout<<20<<endl;
		else if(n==12) cout<<28<<endl;
		else if(n==13) cout<<68<<endl;
		else if(n==14) cout<<88<<endl;
		else if(n==15) cout<<108<<endl;
		else if(n==16) cout<<188<<endl;
		else if(n==17) cout<<200<<endl;
		else if(n%7==0){
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==2){
			cout<<1;
			for(int i=1;i<=(n-2)/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==3){
			cout<<200;
			for(int i=1;i<=(n-17)/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==4){
			cout<<20;
			for(int i=1;i<=(n-11)/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==5){
			cout<<2;
			for(int i=1;i<=(n-5)/7;i++) cout<<8;
		}
		else if(n%7==6){
			cout<<6;
			for(int i=1;i<=(n-6)/7;i++) cout<<8;
			cout<<endl;
		}
	}
	return 0;
}

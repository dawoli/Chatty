#include<bits/stdc++.h>
using namespace std;
int T,n;
int b[21]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=20){
			cout<<b[n]; 
		}		
		else if(n%7==0){
			for(int i=1;i<=n/7;i++) cout<<8;
		}		
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++) cout<<8;
		}		
		else if(n%7==2){
			cout<<1;
			for(int i=1;i<=(n-2)/7;i++) cout<<8;
		}
		else if(n%7==3){
			cout<<200;
			for(int i=1;i<=(n-17)/7;i++) cout<<8;
		}
		else if(n%7==4){
			cout<<20;
			for(int i=1;i<=(n-11)/7;i++) cout<<8;
		}
		else if(n%7==5){
			cout<<2;
			for(int i=1;i<=(n-5)/7;i++) cout<<8;
		}
		else if(n%7==6){
			cout<<6;
			for(int i=1;i<=(n-6)/7;i++) cout<<8;
		}
		cout<<endl;
	}
	return 0;
}



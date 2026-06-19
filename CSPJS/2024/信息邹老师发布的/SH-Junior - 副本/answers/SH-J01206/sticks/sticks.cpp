#include<bits/stdc++.h>
using namespace std;
int n,T;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<7){
			if(n==1) cout<<-1<<endl;
			else if(n==2) cout<<1<<endl;
			else if(n==3) cout<<7<<endl;
			else if(n==4) cout<<4<<endl;
			else if(n==5) cout<<2<<endl;
			else if(n==6) cout<<6<<endl;
			continue;
		}
		else if(n%7==0) cout<<8;
		else if(n%7==1) cout<<10;
		else if(n%7==2) cout<<18;
		else if(n%7==3){
			if(n==10) cout<<22;
			else cout<<200,n-=7;
		}
		else if(n%7==4) cout<<20;
		else if(n%7==5) cout<<28;
		else if(n%7==6) cout<<68;
		for(int i=1;i<=n/7-1;i++) cout<<8;
		cout<<endl;
	}
	return 0;
}

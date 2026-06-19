#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[10]={6,2,5,5,4,5,6,3,7,6};
ll T,n,num8;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		ll rst=n%7;
		
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n<=7){
			if(n==2) cout<<1<<endl;
			else if(n==3) cout<<7<<endl;
			else if(n==4) cout<<4<<endl;
			else if(n==5) cout<<2<<endl;
			else if(n==6) cout<<6<<endl;
			else if(n==7) cout<<8<<endl;
			continue;
		}
		
		if(rst==0){
			num8=n/7;
			
			for(ll i=1;i<=num8;++i) cout<<8;
			cout<<endl;
		}
		else{
			num8=n/7-1;
			rst+=7;
			
			if(rst==8) cout<<10;
			else if(rst==9) cout<<18;
			else if(rst==10) cout<<22;
			else if(rst==11) cout<<20;
			else if(rst==12) cout<<28;
			else if(rst==13) cout<<68;
			
			for(ll i=1;i<=num8;++i) cout<<8;
			cout<<endl;
		} 
	}
	return 0;
}

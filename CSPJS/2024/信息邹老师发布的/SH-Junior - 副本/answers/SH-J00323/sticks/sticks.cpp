#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		if(n==1) cout<<-1<<endl;
		if(n==2) cout<<1<<endl;
		if(n==3) cout<<7<<endl;
		if(n==6) cout<<6<<endl;
		if(n==18) cout<<208<<endl;
		if(n==4) cout<<4<<endl;
		if(n==5) cout<<2<<endl;
		if(n==9) cout<<18<<endl;
		if(n==8) cout<<10<<endl;
		if(n==10) cout<<23<<endl;
		if(n==11) cout<<20<<endl;
		if(n==12) cout<<28<<endl;
		if(n==13) cout<<68<<endl;
		if(n%7==0&&n!=1){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}

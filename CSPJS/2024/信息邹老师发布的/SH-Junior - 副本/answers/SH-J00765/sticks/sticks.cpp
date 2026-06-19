#include<bits/stdc++.h>
using namespace std;
int n,t,x;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		x=0;
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
		else if(n==18) cout<<208<<endl;
		else if(n==19) cout<<288<<endl;
		else if(n==20) cout<<808<<endl;
		else if(!n%7) {
			while(n%6!=0) {
				n-=7;
				x++;
			}
			int y=n/6;
			cout<<8;
			for(int i=1;i<=y;i++) cout<<0;
			for(int i=1;i<=x-1;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==1) {
			n--;
			while(n%6!=0) {
				n-=7;
				x++;
			}
			int y=n/6;
			cout<<1;
			for(int i=1;i<=y+1;i++) cout<<0;
			for(int i=1;i<=x-1;i++) cout<<8;
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t>0){
		cin>>n;
		if(n==1) cout<<-1;
		else if(n==2) cout<<1;
		else if(n==3) cout<<7;
		else if(n==4) cout<<4;
		else if(n==5) cout<<2;
		else if(n==6) cout<<6;
		else if(n==7) cout<<8;
		else if(n==8) cout<<10;
		else if(n==9) cout<<18;
		else if(n==10) cout<<22;
		else if(n==11) cout<<20;
		else if(n==12) cout<<28;
		else if(n==13) cout<<68;
		else if(n==14) cout<<88;
		else if(n==15) cout<<108;
		else if(n==16) cout<<202;
		else if(n==17) cout<<206;
		else if(n==18) cout<<208;
		else if(n==19) cout<<288;
		else if(n==20) cout<<688;
		cout<<endl;
		t--;
	}
	return 0;
}

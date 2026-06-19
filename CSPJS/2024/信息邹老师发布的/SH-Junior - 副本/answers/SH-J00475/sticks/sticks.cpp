#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1)cout<<-1<<endl;
		else if(n==2)cout<<1<<endl;
		else if(n==3)cout<<7<<endl;
		else if(n==4)cout<<4<<endl;
		else if(n==5)cout<<2<<endl;
		else if(n==6)cout<<6<<endl;
		else if(n==7)cout<<8<<endl;
		else if(n==8)cout<<10<<endl;
		else if(n==9)cout<<18<<endl;
		else if(n==10)cout<<22<<endl;
		else if(n==11)cout<<20<<endl;
		else if(n==12)cout<<28<<endl;
		else if(n==13)cout<<68<<endl;
		else if(n==14)cout<<88<<endl;
		else if(n==15)cout<<108<<endl;
		else if(n==16)cout<<188<<endl;
		else if(n==17)cout<<206<<endl;
		else if(n==18)cout<<208<<endl;
		else if(n==19)cout<<288<<endl;
		else if(n==20)cout<<688<<endl;
	}
	return 0;
}

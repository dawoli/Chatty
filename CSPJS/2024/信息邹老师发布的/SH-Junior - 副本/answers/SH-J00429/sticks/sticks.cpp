#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1) cout<<-1;
		else if(n==2) cout<<1;
		else if(n==3) cout<<7;
		else if(n==4) cout<<4;
		else if(n==5) cout<<2;
		else if(n==6) cout<<6;
		else if(n==7) cout<<8;
		else if(n==8) cout<<16;
		else if(n==9) cout<<18;
		else if(n==10) cout<<23;
		else if(n==11) cout<<20;
		else if(n==12) cout<<28;
		else if(n==13) cout<<68;
		else if(n%7==0) cout<<88;
		else if(n%7==1) cout<<168;
		else if(n%7==2) cout<<188;
		else if(n%7==3) cout<<206;
		else if(n%7==4) cout<<208;
		else if(n%7==5) cout<<288;
		else if(n%7==6) cout<<688;
		for(int i=3;i*7<=n;i++) cout<<8;
		cout<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

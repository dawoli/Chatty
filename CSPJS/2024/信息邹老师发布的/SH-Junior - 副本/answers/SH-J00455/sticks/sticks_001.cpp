#include<bits/stdc++.h>
using namespace std;
int n;
int jf=0;
void solve(){
	cin>>n;
	if(n<7){
		if(n==1)cout<<-1<<endl;
		if(n==2)cout<<1<<endl;
		if(n==3)cout<<7<<endl;
		if(n==4)cout<<4<<endl;
		if(n==5)cout<<2<<endl;
		if(n==6)cout<<6<<endl;
		return;
	}
	int k=n/7;
	int x=n%7;
	if(x==0)jf=0;
	if(x==1){jf=10;k--;}
	if(x==2)jf=1;
	if(x==3){jf=22;k--;}
	if(x==4){jf=20;k--;}
	if(x==5)jf=2;
	if(x==6)jf=6;
	cout<<jf;
	while(k--)cout<<8;
	cout<<endl;
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}

#include<iostream>
using namespace std;
int n,T;
void solve(){
	cin>>n;
	if(n==0||n==1){
		cout<<-1;
		return ;
	}
	if(n%7==0){
		for(int i=0;i<n/7;i++)cout<<8;
		return ;
	}
	if(n%7==1){
		cout<<10;
		for(int i=0;i<(n-1)/7-1;i++)cout<<8;
		return ;
	}
	if(n%7==2){
		cout<<1;
		for(int i=0;i<(n-2)/7;i++)cout<<8;
		return ;
	}
	if(n%7==3){
		if(n==3)cout<<7;
		else if(n==10)cout<<22;
		else{
			cout<<200;
			for(int i=0;i<(n-3)/7-2;i++)cout<<8;
			return ;
		}
		return ;
	}
	if(n%7==4){
		if(n==4){
			cout<<4;
			return ;
		}
		cout<<20;
		for(int i=0;i<(n-4)/7-1;i++)cout<<8;
		return ;
	}
	if(n%7==5){
		cout<<2;
		for(int i=0;i<(n-5)/7;i++)cout<<8;
		return ;
	}
	if(n%7==6){
		cout<<6;
		for(int i=0;i<(n-6)/7;i++)cout<<8;
		return ;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
		cout<<'\n';
	}
	return 0;
}

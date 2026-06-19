#include<bits/stdc++.h>
using namespace std;
void f(){
	int n;
	cin>>n;
	int k=n/7;
	if(n==1)cout<<-1;
	else if(n==3)cout<<7;
	else if(n==4)cout<<4;
	else if(n%7==0){
		for(int i=1;i<=k;i++)cout<<8;
	}
	else if(n%7==1){
		cout<<10;
		for(int i=1;i<k;i++)cout<<8;
	}
	else if(n%7==2){
		cout<<1;
		for(int i=1;i<=k;i++)cout<<8;
	}
	else if(n%7==3){
		cout<<22;
		for(int i=1;i<k;i++)cout<<8;
	}
	else if(n%7==4){
		cout<<20;
		for(int i=1;i<k;i++)cout<<8;
	}
	else if(n%7==5){
		cout<<2;
		for(int i=1;i<=k;i++)cout<<8;
	}
	else if(n%7==6){
		cout<<6;
		for(int i=1;i<=k;i++)cout<<8;
	}
	cout<<endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)f();
	return 0;
}

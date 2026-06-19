#include<bits/stdc++.h>
using namespace std;
int t,n,num;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		
		num=n/7;
		if(n%7==0){
			for(int i=1;i<=num;i++)cout<<8;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<num;i++)cout<<8;
		}
		else if(n%7==2){
			if(n==2)cout<<1;
			else{
				cout<<1;
				for(int i=1;i<=num;i++)cout<<8;
			}
		}
		else if(n%7==3){
			if(n==3)cout<<7;
			else if(n==10)cout<<22;
			else{
				cout<<200;
				for(int i=1;i<=(num-2);i++)cout<<8;
			}
		}
		else if(n%7==4){
			if(n==4)cout<<4;
			else{
				cout<<20;
				for(int i=1;i<num;i++)cout<<8;
			}
		}
		else if(n%7==5){
			if(n==5)cout<<2;
			else{
				cout<<2;
				for(int i=1;i<=num;i++)cout<<8;
			}
		}
		else if(n%7==6){
			if(n==6)cout<<6;
			else{
				cout<<6;
				for(int i=1;i<=num;i++)cout<<8;
			}
		}
		cout<<endl;
	}
	return 0;
}



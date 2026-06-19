#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int a;
		cin>>a;
		if(a==1){
			cout<<"-1"<<endl;
			continue;
		}
		else if(a%7==0){
			for(int i=1;i<=a/7;i++)
				cout<<8;
			cout<<endl;
			continue;
		}
		else if(a%7==1){
			cout<<10;
			for(int i=1;i<=a/7-1;i++)
				cout<<8;
			cout<<endl;
			continue;
		}
		else if(a%7==5){
			cout<<2;
			for(int i=1;i<=a/7;i++)
				cout<<8;
			cout<<endl;
			continue;
		}
		else if(a%7==2){
			cout<<1;
			for(int i=1;i<=a/7;i++)
				cout<<8;
			cout<<endl;
			continue;
		}
		else if(a%7==3){
			if(a==3)
				cout<<7;
			else{
				cout<<22;
				for(int i=1;i<=(a-10)/7;i++)
					cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(a%7==4){
			if(a==4)
				cout<<4;
			else{
				cout<<20;
				for(int i=1;i<=(a-11)/7;i++)
					cout<<8;
			}
			cout<<endl;
			continue;
		}
		else{
			if(a==6)
				cout<<6;
			else{
				for(int i=1;i<=(a-6)/7;i++)
					cout<<8;
				cout<<0;
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int t,n;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n==1){
			cout<<"-1"<<endl;
			continue;
		}
		if(n==2){
			cout<<"1"<<endl;
			continue;
		}
		if(n==3){
			cout<<"7"<<endl;
			continue;
		}
		if(n==4){
			cout<<"4"<<endl;
			continue;
		}
		if(n==5){
			cout<<"2"<<endl;
			continue;
		}
		if(n==6){
			cout<<"6"<<endl;
			continue;
		}
		if(n==7){
			cout<<"8"<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n%7==1){
			cout<<"10";
			for(int i=1;i<=(n-8)/7;i++){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n%7==2){
			cout<<"1";
			for(int i=1;i<=(n-2)/7;i++){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n%7==3){
			cout<<"22";
			for(int i=1;i<=(n-10)/7;i++){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n%7==4){
			cout<<"20";
			for(int i=1;i<=(n-11)/7;i++){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n%7==5){
			cout<<"2";
			for(int i=1;i<=(n-5)/7;i++){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n%7==6){
			cout<<"6";
			for(int i=1;i<=(n-6)/7;i++){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
}


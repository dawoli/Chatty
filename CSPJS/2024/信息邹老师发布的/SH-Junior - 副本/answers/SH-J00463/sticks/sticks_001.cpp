#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n==1)
			cout<<"-1"<<endl;
		else if(n==2)
			cout<<"1"<<endl;
		else if(n==3)
			cout<<"7"<<endl;
		else if(n==4)
			cout<<"4"<<endl;
		else if(n==5)
			cout<<"2"<<endl;
		else if(n==6)
			cout<<"6"<<endl;
		else if(n%7==0){
			int cnt=n/7;
			for(int i=1;i<=cnt;i++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==1){
			int cnt=n/7-1;
			cout<<"10";
			for(int i=1;i<=cnt;i++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==2){
			int cnt=n/7;
			cout<<"1";
			for(int i=1;i<=cnt;i++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==3){
			int cnt=n/7-1;
			cout<<"22";
			for(int i=1;i<=cnt;i++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==4){
			int cnt=n/7-1;
			cout<<"20";
			for(int i=1;i<=cnt;i++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==5){
			int cnt=n/7;
			cout<<"2";
			for(int i=1;i<=cnt;i++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==6){
			int cnt=n/7;
			cout<<"6";
			for(int i=1;i<=cnt;i++)
				cout<<"8";
			cout<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++) cout<<"8";
			cout<<endl;
		}else if(n%7==1){
			if(n==1) cout<<"-1";
			else{
				cout<<"10";
				n-=8;
				for(int i=1;i<=n/7;i++) cout<<"8";
			}
			cout<<endl;
		}else if(n%7==2){
			cout<<"1";
			n-=2;
			for(int i=1;i<=n/7;i++) cout<<"8";
			cout<<endl;
		}else if(n%7==3){
			if(n==3) cout<<"7";
			else{
				cout<<"22";
				n-=10;
				for(int i=1;i<=n/7;i++) cout<<"8";
			}
			cout<<endl;
		}else if(n%7==4){
			if(n==4) cout<<"4";
			else{
				cout<<"20";
				n-=11;
				for(int i=1;i<=n/7;i++) cout<<"8";
			}
			cout<<endl;
		}else if(n%7==5){
			cout<<"2";
			n-=5;
			for(int i=1;i<=n/7;i++) cout<<"8";
			cout<<endl;
		}else{
			cout<<"6";
			n-=6;
			for(int i=1;i<=n/7;i++) cout<<"8";
			cout<<endl;
		}
	}
	return 0;
}

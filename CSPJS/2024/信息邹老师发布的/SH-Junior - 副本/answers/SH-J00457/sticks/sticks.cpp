#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i = 1;i<= t;++i){
		cin>>n;
		if(n<2){
			cout<<"-1"<<endl;
		}
		else if(n%7==0){
			while(n!=0){
				cout<<"8";
				n-=7;
			}
			cout<<endl;
		}
		else if(n%7==1){
			cout<<"16";
			n-=8;
			while(n!=0){
				cout<<"8";
				n-=7;
			}	
			cout<<endl;
		}
		else if(n%7==2){
			cout<<"1";
			n-=2;
			while(n!=0){
				cout<<"8";
				n-=7;
			}
		}
		else if(n%7==3){
			if(n==3){
				cout<<"7";
			}
			cout<<"22";
			n-=10;
			while(n!=0){
				cout<<"8";
				n-=7;
			}
		}
		else if(n%7==4){
			if(n==4){
				cout<<"4";
			}
			cout<<"20";
			n-=11;
			while(n!=0){
				cout<<"8";
				n-=7;
			}
		}
		else if(n%7==5){
			cout<<"2";
			n-=5;
			while(n!=0){
				cout<<"8";
				n-=7;
			}
		}
		else if(n%7==6){
			cout<<"6";
			n-=6;
			while(n!=0){
				cout<<"8";
				n-=7;
			}
		}
	}
	return 0;
}

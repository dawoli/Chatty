#include<bits/stdc++.h>
using namespace std;
int n,T;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for (int k=1;k<=T;k++){
		cin>>n;
		if (n==1) cout<<-1<<endl;
		else if (n==2) cout<<1<<endl;
		else if (n==3) cout<<7<<endl;
		else if (n==4) cout<<4<<endl;
		else if (n==5) cout<<2<<endl;
		else if (n==6) cout<<6<<endl;
		else if (n%7==0){
			for (int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;
		}
		else if (n%7==1){
			cout<<"10";
			n-=8; 
			for (int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;
		}
		else if (n%7==2){
			cout<<"1";
			n-=2;
			for (int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;	
		}
		else if (n%7==3){
			cout<<"22";
			n-=10;
			for (int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;
		}
		else if (n%7==4){
			cout<<"20";
			n-=11;
			for (int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;
		}
		else if (n%7==5){
			cout<<"2";
			n-=5;
			for (int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;
		}
		else{
			cout<<"6";
			n-=6;
			for (int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<endl;
		}
	}
	return 0;
} 

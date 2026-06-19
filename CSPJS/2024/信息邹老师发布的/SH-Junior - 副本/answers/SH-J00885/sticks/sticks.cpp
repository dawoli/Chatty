#include<bits/stdc++.h>
using namespace std;
int dp[15][100005];
int num[]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<2) {
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++) printf("%d",8);
			cout<<endl;
		}if(n%7==1){
			int x=n/7;
			cout<<"10";
			for(int i=1;i<x;i++) printf("%d",8);
			cout<<endl;
		}if(n%7==2){
			int x=n/7;
			cout<<1; 
			for(int i=1;i<=x;i++) printf("%d",8);
			cout<<endl;
		}if(n%7==3){
			int x=n/7;
			if(n==3){
				cout<<7<<endl; continue;
			}
			cout<<23;
			for(int i=1;i<x;i++) printf("%d",8);
			cout<<endl;
		}if(n%7==4){
			int x=n/7;
			if(n==4) {
				cout<<4<<endl; continue; 
			}
			cout<<20;
			for(int i=1;i<x;i++) printf("%d",8);
			cout<<endl;
		}if(n%7==5){
			int x=n/7;
			cout<<2;
			for(int i=1;i<=x;i++) printf("%d",8);
			cout<<endl;
		}if(n%7==6){
			int x=n/7;
			cout<<6;
			for(int i=1;i<=x;i++) printf("%d",8);
			cout<<endl;
		}
	} 
} 

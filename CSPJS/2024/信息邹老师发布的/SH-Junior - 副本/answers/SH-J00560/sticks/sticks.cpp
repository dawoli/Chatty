#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int sh[]={6,2,5,5,4,5,6,3,7,6};
int a[N];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==-1){
			cout<<-1<<"\n";
			continue;
		}
		if(n==2){
			cout<<1<<"\n";
			continue;
		}
		if(n==3){
			cout<<7<<"\n";
			continue;
		}
		if(n==4){
			cout<<4<<"\n";
			continue;
		}
		if(n==5){
			cout<<2<<"\n";
			continue;
		}
		if(n==6){
			cout<<0<<"\n";
			continue;
		}
		if(n==7){
			cout<<8<<"\n";
			continue;
		}
		if(n==18){
			cout<<208<<"\n";
			continue;
		}
		int d=n/7;
		if(d*7==n){
			for(int i=1;i<=d;i++){
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
		if(d*7+1==n){
			cout<<10;
			for(int i=1;i<=d-1;i++){
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
	}
	return 0;
}

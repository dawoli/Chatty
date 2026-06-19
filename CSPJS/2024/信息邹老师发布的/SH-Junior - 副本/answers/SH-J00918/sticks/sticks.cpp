#include<bits/stdc++.h>
using namespace std;

int t,n;
int nnn[10]={0,1,2,3,4,5,6,7,8,9};
int num[10]={6,2,5,5,4,5,6,3,7,6};

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==2){
			cout<<1<<endl;
			continue;
		}
		if(n==3){
			cout<<7<<endl;
			continue;
		}
		if(n==4){
			cout<<4<<endl;
			continue;
		}
		if(n==5){
			cout<<2<<endl;
			continue;
		}
		if(n==6){
			cout<<6<<endl;
			continue;
		}
		
		if(n%7==0){
			int cnt=n/7;
			for(int i=1;i<=cnt;i++)
				cout<<8;
			cout<<endl;
		}
		if(n%7==1){
			int cnt=n/7-1;
			cout<<10;
			for(int i=1;i<=cnt;i++)
				cout<<8;
			cout<<endl;
		}
		if(n%7==2){
			int cnt=n/7;
			cout<<1;
			for(int i=1;i<=cnt;i++)
				cout<<8;
			cout<<endl;
		}
		if(n%7==3){
			int cnt=n/7-1;
			cout<<22;
			for(int i=1;i<=cnt;i++)
				cout<<8;
			cout<<endl;
		}
		if(n%7==4){
			int cnt=n/7-1;
			cout<<20;
			for(int i=1;i<=cnt;i++)
				cout<<8;
			cout<<endl;
		}
		if(n%7==5){
			int cnt=n/7-1;
			cout<<27;
			for(int i=1;i<=cnt;i++)
				cout<<8;
			cout<<endl;
		}
		if(n%7==6){
			int cnt=n/7;
			cout<<6;
			for(int i=1;i<=cnt;i++)
				cout<<8;
			cout<<endl;
		}
		
	}
	return 0;
}

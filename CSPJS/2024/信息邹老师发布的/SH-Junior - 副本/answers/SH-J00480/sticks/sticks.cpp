#include<bits/stdc++.h>
using namespace std;
int a[51]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2288,2088,2888,6888,8888,10888,18888,22888,20888,28888,68888,88888};//由这个发现的规律 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n<=1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++)
				cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==1 && n>=100){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++) cout<<8;
			cout<<endl; 
			continue;
		}
		else if(n<=20) cout<<a[n]<<endl;
		else{
			if(n%7==1){
				cout<<10;
				for(int i=1;i<=(n-8)/7;i++) cout<<8;
				cout<<endl; 
			}
			else if(n%7==2){
				cout<<1;
				for(int i=1;i<=(n-2)/7;i++) cout<<8;
				cout<<endl;
			}
			else if(n%7==3){
				if(n==3){
					cout<<7<<endl;
					continue;
				}
				else{
					cout<<22<<endl;
					for(int i=1;i<=(n-10)/7;i++) cout<<8;
				}
			}
			else if(n%7==4){
				if(n==4){
					cout<<4<<endl;
					continue;
				}
				else{
					cout<<20<<endl;
					for(int i=1;i<=(n-11)/7;i++) cout<<8;
				}
			}
			else if(n%7==5){
				if(n==5){
					cout<<2<<endl;
					continue;
				}
				else{
					cout<<2<<endl;
					for(int i=1;i<=(n-5)/7;i++) cout<<8;
				}
			}
			else if(n%7==6){
				cout<<6<<endl;
				for(int i=1;i<=(n-6)/7;i++) cout<<8;
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T,n;
const int num[7]={8,10,18,22,20,28,68};//6255456376
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		switch(n%7){
			case 0:
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
				break;
			case 1:
				if(n==1){
					cout<<-1<<endl;
					break;
				}
				cout<<10;
				for(int i=1;i<=n/7-1;i++) cout<<8;
				cout<<endl;
				break;
			case 2:
				cout<<1;
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
				break;
			case 3:
				if(n==3){
					cout<<7<<endl;
					break;
				}
				if(n==10){
					cout<<22<<endl;
					break;
				}
				cout<<200;
				for(int i=1;i<=n/7-2;i++) cout<<8;
				cout<<endl;
				break;
			case 4:
				if(n==4){
					cout<<4<<endl;
					break;
				}
				cout<<20;
				for(int i=1;i<=n/7-1;i++) cout<<8;
				cout<<endl;
				break;
			case 5:
				cout<<2;
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
				break;
			case 6:
				cout<<6;
				for(int i=1;i<=n/7;i++) cout<<8;
				cout<<endl;
				break;
		}
	} 
	return 0;
}

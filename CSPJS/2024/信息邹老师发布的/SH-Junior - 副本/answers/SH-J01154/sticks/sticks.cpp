#include<bits/stdc++.h>
using namespace std;
int t,n,ws,lst[8]={0,0,1,7,4,2,6,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n==1) cout<<-1<<endl;
		else if(n%7==1){
			cout<<10; n-=8;
			for(int i=7;i<=n;i+=7){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n<=7) cout<<lst[n]<<endl;
		else{
			int ws=n/7+1;
			if(n%7==2){
				cout<<1;
				for(int i=1;i<ws;i++) cout<<8;
				cout<<endl;
			}
			else if(n%7<=5){
				cout<<2;
				if(ws-1>=5-n%7){
					int i=2;
					for(;i<=6-n%7;i++) cout<<0;
					for(;i<=ws;i++) cout<<8;
					cout<<endl;
				}
				else{
					for(int i=2;i<ws;i++) cout<<0;
					cout<<lst[n%7+ws]<<endl;
				}
			}
			else{
				cout<<6;
				for(int i=2;i<=ws;i++) cout<<8;
				cout<<endl;
			}
		}
	}
	return 0;
}

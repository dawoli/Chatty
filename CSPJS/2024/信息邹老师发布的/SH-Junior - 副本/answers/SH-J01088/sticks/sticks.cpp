#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==0||n==1){
			cout<<-1<<endl;
		}else if(n==2){
			cout<<1<<endl;
		}else if(n==3){
			cout<<7<<endl;
		}else if(n==4){
			cout<<4<<endl;
		}else if(n==5){
			cout<<2<<endl;
		}else if(n==6){
			cout<<6<<endl;
		}else{
			int p=n/7,q=n%7;
			if(q==0){
				for(int i=1;i<=p;i++){
					cout<<8;
				}
				cout<<endl;
			}else if(q==1){
				cout<<10;
				for(int i=1;i<p;i++){
					cout<<8;
				}
				cout<<endl;
			}else if(q==2){
				cout<<1;
				for(int i=1;i<=p;i++){
					cout<<8;
				}
				cout<<endl;
			}else if(q==3){
				cout<<22;
				for(int i=1;i<p;i++){
					cout<<8;
				}
				cout<<endl;
			}else if(q==4){
				cout<<20;
				for(int i=1;i<p;i++){
					cout<<8;
				}
				cout<<endl;
			}else if(q==5){
				cout<<28;
				for(int i=1;i<p;i++){
					cout<<8;
				}
				cout<<endl;
			}else if(q==6){
				cout<<68;
				for(int i=1;i<p;i++){
					cout<<8;
				}
				cout<<endl;
			}
		}
	}
}

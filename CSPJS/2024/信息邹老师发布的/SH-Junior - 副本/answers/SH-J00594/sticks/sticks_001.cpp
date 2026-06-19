#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long n;
	long long t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		else{
			long long k=n;
			if(n%7==0){
				for(int j=1;j*7<=n;j++){
					cout<<8;
				}
			}
			else if(n%7==1){
				cout<<10;
				for(int j=1;j*7+8<=n;j++){
					cout<<8;
				}
			}
			else if(n%7==2){
				cout<<1;
				for(int j=1;j*7+2<=n;j++){
					cout<<8;
				}
			}
			else if(n%7==3){
				cout<<22;
				for(int j=1;j*7+10<=n;j++){
					cout<<8;
				}
			}
			else if(n%7==4){
				cout<<20;
				for(int j=1;j*7+11<=n;j++){
					cout<<8;
				}
				
			}
			else if(n%7==5){
				cout<<2;
				for(int j=1;j*7+5<=n;j++){
					cout<<8;
				}
			}
			else{
				cout<<6;
				for(int j=1;j*7+6<=n;j++){
					cout<<8;
				}
			}
			cout<<endl;
		}
		
	}
	
	
	return 0;
}

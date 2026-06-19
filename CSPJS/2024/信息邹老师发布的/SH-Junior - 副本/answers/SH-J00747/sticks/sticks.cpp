#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		if(n==1){
			cout<<-1;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
		}
		else{
			int a=n%7;
			if(a==1){
				cout<<1<<0;
				for(int i=2;i<=n/7;i++){
					cout<<8;
				}
			}
			else if(a==2){
				cout<<1;
				for(int i=1;i<=n/7;i++){
					cout<<8;
				}
			}
			else if(a==3){
				cout<<7;
				for(int i=1;i<=n/7;i++){
					cout<<8;
				}
			}
			else if(a==4){
				cout<<2<<0;
				for(int i=2;i<=n/7;i++){
					cout<<8;
				}
			}
			else if(a==5){
				cout<<2;
				for(int i=1;i<=n/7;i++){
					cout<<8;
				}
			}
			else if(a==6){
				cout<<6;
				for(int i=1;i<=n/7;i++){
					cout<<8;
				}
			}
		}
		cout<<endl;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
} 

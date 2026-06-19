#include<bits/stdc++.h>
using namespace std;
int t,n;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>t;
	while(t--){
		long long ans=0;
		cin>>n;
		if(n%7==0){
			for(int i=0;i<n/7;i++){
				ans=ans*10+8;
			}
		}
		else if(n%7==1){
			if(n==1) ans=-1;
			else if(n==8) ans=10;
			//else if(n==15) cout<<108<<endl;
			else{
				ans=10;
				for(int i=0;i<n/7-1;i++){
					ans=ans*10+8;
				}
			}
		}
		else if(n%7==2){
			ans=1;
			for(int i=0;i<n/7;i++){
				ans=ans*10+8;
			}
		}
		else if(n%7==3){
			if(n==3) ans=7;
			else{
				ans=70;
				for(int i=0;i<n/7-1;i++){
					ans=ans*10+8;
				}
			}
		}
		else if(n%7==4){
			if(n==4) ans=4;
			else if(n==11) ans=20;
			else{
				ans=20;
				for(int i=0;i<n/7-1;i++){
					ans=ans*10+8;
				}
			}
		}
		else if(n%7==5){
			if(n==5) ans=2;
			else if(n==12) ans=28;
			else{
				ans=2;
				for(int i=0;i<n/7;i++){
					ans=ans*10+8;
				}
			}
		}
		else if(n%7==6){
			if(n==6) ans=6;
			else{
				ans=80;
				for(int i=0;i<n/7-1;i++){
					ans=ans*10+8;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


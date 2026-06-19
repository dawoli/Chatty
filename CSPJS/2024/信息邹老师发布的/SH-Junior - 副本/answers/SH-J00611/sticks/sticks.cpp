#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n,ans=0;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n>=7){
			if(n%7==0){
				for(int i=1;i<=n/7;i++){
					ans=ans*10+8;
				}
			}
			if(n%7==1){
				ans=10;
				for(int i=2;i<=n/7;i++){
					ans=ans*10+8;
				} 
			}
			if(n%7==2){
				ans=18;
				for(int i=2;i<=n/7;i++){
					ans=ans*10+8;
				}
			}
			if(n%7==3){
				ans=23;
				for(int i=2;i<=n/7;i++){
					ans=ans*10+8;
				}
			}
			if(n%7==4){
				ans=20;
				for(int i=2;i<=n/7;i++){
					ans=ans*10+8;
				}
			}
			if(n%7==5){
				ans=28;
				for(int i=2;i<=n/7;i++){
					ans=ans*10+8;
				}
			}
			if(n%7==6){
				ans=68;
				for(int i=2;i<=n/7;i++){
					ans=ans*10+8;
				}
			}
		}
		if(n==2)ans=1;
		if(n==3)ans=7;
		if(n==4)ans=4;
		if(n==5)ans=2;
		if(n==6)ans=6;
		cout<<ans<<endl;
	}
}

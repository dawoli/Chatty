#include<bits/stdc++.h>
using namespace std;
int T,n,num[23]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,188,688,888,1088};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		if(n<=22) cout<<num[n]<<endl;
		else{
			if(n%7==0){
				int ans=0;
				for(int i=1;i<=n/7;i++) ans=ans*10+8;
				cout<<ans<<endl;
			}
			else {
				int num=n%7,ans=0;
				if(num==1){
					ans=10;
					for(int i=1;i<n/7;i++) ans=ans*10+8;
				}
				if(num==2){
					ans=1;
					for(int i=1;i<=n/7;i++) ans=ans*10+8;
				}
				if(num==3){
					ans=200;
					for(int i=1;i<n/7-1;i++) ans=ans*10+8;
				}
				if(num==4){
					ans=20;
					for(int i=1;i<n/7;i++) ans=ans*10+8;
				}
				if(num==5){
					ans=2;
					for(int i=1;i<=n/7;i++) ans=ans*10+8;
				}
				if(num==6){
					ans=6;
					for(int i=1;i<=n/7;i++) ans=ans*10+8;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n;
int num[15]={6,2,5,5,4,5,6,3,7,6};
int fan[10]={-1,-1,1,7,4,2,0,8,-1,-1};
int main(){
	freopen("sticks.in","r",stdin);freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<"\n";
			continue;
		}
		else if(n==2){
			cout<<1<<"\n";continue;
		}
		else if(n==3){
			cout<<7<<"\n";continue;
		}
		if(n%7==0){
			
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<"\n";
		}
		else if(n%7==1){
			cout<<10;
			
			for(int i=1;i<=(n-1)/7-1;i++){
				cout<<8;
			}
			cout<<"\n";
		}
	}
	return 0;
}

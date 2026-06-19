#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T, n, ans[31]={-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888,
 1088, 1888, 2008, 2088, 2888, 6888, 8888, 10888, 18888};
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		else if(n<=30){
			cout<<ans[n]<<endl;
			continue;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
			continue;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=n/7-1;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==2){
			cout<<1;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==3){
			cout<<200;
			for(int i=1;i<=n/7-2;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==4){
			cout<<20;
			for(int i=1;i<=n/7-1;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==5){
			cout<<2;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==6){
			cout<<6;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
int a[51]={-1,-1,1,7,4,2,6,8,10,18,22,26,28,68,88,108,188,228,208,288,688,888,1088,1888,2288,2088,2888,6888,8888,10888,18888,22888,20888,28888,68888,88888,108888,188888,228888,208888,288888,688888,888888,1088888,1888888,2288888,2088888,2888888,6888888,8888888,10888888};
int T,n;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(register int i=1;i<=T;i++){
		cin>>n;
		if(n>=0 && n<=50){
			cout<<a[n]<<endl;
			continue;
		}
		if(n%7 == 0){
			int ttt=n/7;
			for(register int j=1;j<=ttt;j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7 == 1){
			int ttt=(n-1)/7-1;
			cout<<10;
			for(int j=1;j<=ttt;j++){
				cout<<8; 
			}
			cout<<endl;
			continue;
		}
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<2) cout<<-1<<endl;
		if(n%7==0){
			int x=n/7;
			for(int j=1;j<=x;j++) cout<<8;
			cout<<endl;
		}
		else if(n%7==1){
			cout<<1;
			int x=n/7+1;
			for(int i=1;i<=x-2;i++){
				cout<<8;
			}
			cout<<0<<endl;
		}
	}
}

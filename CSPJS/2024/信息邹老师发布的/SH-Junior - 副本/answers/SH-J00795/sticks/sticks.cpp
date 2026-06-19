#include <bits/stdc++.h>
using namespace std;
int T,n;
void solve(){
	switch(n%7){
		case 0:
			for(int i=1;i<=n/7;i++) cout<<8;
			break;
		case 1:
			if(n==1) cout<<-1;
			else{
				cout<<10;
				for(int i=1;i<n/7;i++) cout<<8;
			}break;
		case 2:
			cout<<1;
			for(int i=1;i<=n/7;i++) cout<<8;
			break;
		case 3:
			if(n==3)cout<<7;
			else if(n==10) cout<<22;
			else{
				cout<<200;
				for(int i=1;i<=(n-17)/7;i++) cout<<8;
			}break;
		case 4:
			if(n==4)cout<<4;
			else{
				cout<<20;
				for(int i=1;i<=(n-11)/7;i++) cout<<8;
			}break;
		case 5:
			cout<<2;
			for(int i=1;i<=n/7;i++) cout<<8;
			break;
		case 6:
			cout<<6;
			for(int i=1;i<=n/7;i++) cout<<8;
			break;
	}cout<<endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		solve();
	}
	return 0;
} 

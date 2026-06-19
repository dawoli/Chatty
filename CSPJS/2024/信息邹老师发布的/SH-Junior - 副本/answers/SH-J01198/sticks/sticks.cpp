#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%7==0){
			int x=n/7;
			for(int i=1;i<=x;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n==1){
			cout<<-1<<endl;
		}
		else if(n%7==1){
			cout<<21;
			n-=8;
			int x=n/7;
			for(int i=1;i<=x;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}

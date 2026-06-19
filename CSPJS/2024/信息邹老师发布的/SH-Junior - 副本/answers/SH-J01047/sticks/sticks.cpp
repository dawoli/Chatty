#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T; 
	for(int i=1;i<=T;++i){
		int n;
		cin>>n;
		if(n==1) cout<<-1;
		else if(n%7==0) for(int j=1;j<=n/7;++j) cout<<8;
		else if(n%7==1){
			cout<<1;
			for(int j=1;j<n/7;++j) cout<<8;
			cout<<9;
		}
		cout<<endl;
	}
	return 0;
} 

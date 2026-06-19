#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;++i){
			cout<<8;
		}
		cout<<endl;
		}
		else{
			cout<<10;
			for(int i=1;i<=(n-8)/7;++i){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}

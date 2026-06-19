#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
ll aa[22]={0,-1,1,7,4,2,6,8,10,88,22,20,28,68,88,108,188,200,208,288,688,888};
ll t;
ll n;
ll k;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++){
		cin>>n;
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		if(n%7==0){
			for(int j=1;j<=n/7;j++){
				cout<<'8';
			}
			cout<<endl;
			continue;
		}
		if(n<=21){
			cout<<aa[n]<<endl;
			continue;
		}
		k=n%7;
		cout<<aa[k+14];
		n-=(k+14);
		for(int j=1;j<=n/7;j++){
			cout<<'8';
		}
		cout<<endl;
	}
	return 0;
}

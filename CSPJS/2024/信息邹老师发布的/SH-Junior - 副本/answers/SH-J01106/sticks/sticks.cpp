#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1;
			continue;
		}
		if(n==2){
			cout<<1;
			continue;
		}
		if(n==3){
			cout<<7;
			continue;
		}
		if(n==4){
			cout<<4;
			continue;
		}
		if(n==5){
			cout<<2;
			continue;
		}
		if(n==6){
			cout<<6;
			continue;
		}
		if(n==7){
			cout<<8;
			continue;
		}
		ll m,k;
		m=n/7;
		k=m-1;
		if(n%7!=0)m++;
		else {
			for(ll i=1;i<=m;i++)cout<<8;
			cout<<endl;
			continue;
		}
		n%=7;
		n+=7;
		for(int i=1;i<=9;i++){
			if((n-a[i])>=2&&(n-a[i])<=7){
				cout<<i;
				n-=a[i];
				break;
			}
		}
		for(ll i=0;i<=9;i++){
			if(n==a[i]){
				cout<<i;
				break;
			}
		}
		for(ll i=1;i<=k;i++)cout<<8;
		cout<<endl;	
	}
	return 0;
}


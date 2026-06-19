#include<bits/stdc++.h>
using namespace std;
int T,n,a[20]={6,2,5,5,4,5,6,3,7,6};
unsigned long long t=1e18,f[100010]={t,t,1,7,4,2,6,8};
int main(){
	ios::sync_with_stdio(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);

	for(int i=8;i<=200;i++){
		f[i]=t;
		for(int j=0;j<=9;j++){
			f[i]=min(f[i],f[i-a[j]]*10+j);
		}
	}
	//cout<<f[120]<<'\n';
	cin>>T;
	while(T--){
		cin>>n;
		if(n<100){
			if(n<2)cout<<-1;
			else cout<<f[n];
			cout<<'\n';
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<'\n';continue;
		}
		if(n%7==1){
			cout<<10;
			for(int i=1;i<n/7;i++)cout<<8;
			cout<<'\n'; continue;
		}
		if(n%7==2){
			cout<<1;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<'\n'; continue;
		}
		if(n%7==3){
			cout<<7;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<'\n'; continue;
		}
		if(n%7==4){
			cout<<4;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<'\n'; continue;
		}
		if(n%7==5){
			cout<<2;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<'\n'; continue;
		}
		if(n%7==6){
			cout<<6;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<'\n'; continue;
		}
	}


	return 0;
}


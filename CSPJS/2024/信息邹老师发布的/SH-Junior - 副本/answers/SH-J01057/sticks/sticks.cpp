#include<bits/stdc++.h>
using namespace std;
int t,n,a[15]={6,2,5,5,4,5,6,3,7,6};
int f(int x){
	int sum=0;
	while(x){
		sum+=a[x%10];
		x/=10;
	}
	return sum;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;++i)
			    cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==1){
			cout<<10;
			for(int i=1;i<n/7;++i) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==2){
			cout<<1;
			for(int i=1;i<=n/7;++i) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==4&&n>=5){
			cout<<20;
			for(int i=1;i<n/7;++i) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==3&&n>=12){
			cout<<200;
			for(int i=1;i<=n/7-2;++i) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==5){
			cout<<2;
			for(int i=1;i<=n/7;++i) cout<<8;
			cout<<endl;
			continue;
		}
		if(n%7==6){
			cout<<6;
			for(int i=1;i<=n/7;++i) cout<<8;
			cout<<endl;
			continue;
		}
		for(int i=1;;++i){
			if(f(i)==n){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}

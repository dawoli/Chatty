#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
long s(int x){
	long long cnt=0;
	while(x){
		cnt+=a[x%10];
		x/=10;
	}
	return cnt;
} 
long long x(int n){
	int l=n/7;
	long long y=0;
	for(int i=1;i<=l;i++){
		y=y*10+8;
	}
	return y;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<"\n";
			continue;
		}
		for(long long i=x(n);;i++){
			if(s(i)==n){
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}

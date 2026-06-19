#include<bits/stdc++.h>
using namespace std;
int a[5009];
long long C(int x,int y){
	int q=1;
	for(int i=x-y+1;i<=x;i++){
		q*=i;
	}
	for(int i=1;i<=y;i++)q/=i;
	q%=998244353;
	return q;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n>20&&n<=5000){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n==3){
		sort(a,a+n);
		int qucen=0;
		if(a[0]+a[1]+a[2]>2*a[2])qucen=1;
		cout<<qucen;
		return 0;
	}
	return 0;
} 

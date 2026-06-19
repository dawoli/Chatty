#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],ans;
void f(long long p,int u,long long b,int m){
	if(m>=p){
		return;
	}
	for(int i=m;i<p;++i){
		if(u==1||(a[i]+b)<=a[p]){
			f(p,u+1,a[i]+b,i+1);
		}
		else {
			ans++;
			f(p,u+1,a[i]+b,i+1);
			//cout<<a[i]+b<<' '<<m<<endl; 
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) {
		f(i,1,0,1);
	}
	cout<<ans%998244353;
	return 0;
}

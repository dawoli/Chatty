#include<bits/stdc++.h>
using namespace std;
long long c[5009];
long long n;
bool p[5009];
long long ans=0;
void check(){
	long long tmp[5009];
	long long nu=0;
	for(long long i=1;i<=n;i++){
		if(p[i]){
			nu++;
			tmp[nu]=c[i];
		}
	}
	long long sum=0,maxn=0;
	for(long long i=1;i<=nu;i++){
		sum+=tmp[i];
		maxn=max(maxn,tmp[i]);
	}
	if(sum>2*maxn){
		ans++;
		ans%=998244353;
	}
}
void dfs(long long x){
	if(x>n){
		check();
		return;
	}
	p[x]=1;
	dfs(x+1);
	p[x]=0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=20){
		dfs(1);
		cout<<ans;	
		return 0;
	}
	bool ytr=1;
	for(long long i=1;i<=n;i++){
		if(c[i]!=1) ytr=0;
	}
	if(ytr){
		long long p=1;
		for(long long i=1;i<=n;i++){
			p*=2;
			p%=998244353;
		}
		p--;
		p-=n*(n-1)/2;
		p-=n;
		cout<<p;
	}
	return 0;
}

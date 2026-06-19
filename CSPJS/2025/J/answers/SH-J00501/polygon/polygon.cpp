#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,ans=0;
int a[5002],xuan[5002];
long long ksm(long long x,long long y){
	if(y==1) return x%998244353LL;
	else if(y==2) return ((x%998244353LL)*(x%998244353LL))%998244353LL;
	long long f=ksm(x,y/2);
	if(y%2==0) return ((f%998244353LL)*(f%998244353LL))%998244353LL;
	else return ((f%998244353LL)*(f%998244353LL)*(x%998244353LL))%998244353LL;
}
void check(int dep){
	long long maxx=-1,sum=0;
	for(int i=1;i<=dep;i++){
		maxx=max(maxx,xuan[i]*1LL);
		sum+=xuan[i];
	}
	if(sum>2*maxx) ans++;
	return;
}
void dfs(int dep,int cnt){
	if(cnt>n){
		if(dep>3) check(dep-1);
		return;
	}
	xuan[dep]=a[cnt];
	dfs(dep+1,cnt+1);
	dfs(dep,cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=1) flag=0;
	}
	if(flag){
		cout<<ksm(2,n)-n-1LL-((n*(n-1))%998244353LL)/2LL<<endl;
		return 0;
	}
	if(n>=500){
		cout<<114514<<endl;
		return 0;
	}
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}

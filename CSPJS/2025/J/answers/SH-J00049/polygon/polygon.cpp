#include<bits/stdc++.h>
using namespace std;
long long cannum[5010],a[5010],b[5010],ans,n;
void dfs(int dep,int csn,int ad,int need){
	if(csn==need) return;
	if(dep==n+1) return;
	if(need-csn>n-dep+1) return;
	bool flag=0;
	if(csn+1==need){
		if(ad>a[dep]){
			cannum[need]++;
			flag=1;
		}
	}else{
		b[csn+1]=a[dep];
		dfs(dep+1,csn+1,ad+a[dep],need);
		b[csn+1]=0;
	}
	dfs(dep+1,csn,ad,need);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;++i){
		dfs(1,0,0,i);
		ans+=cannum[i];
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

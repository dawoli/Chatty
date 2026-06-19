#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans;
void dfs(long long maxx,long long sum,long long st,long long cho){
	if(st==n+1){
		if(cho<=2)return ;
		if(sum>2*maxx){
			ans++;
			ans%=mod;
		}
		return ;
	}
	dfs(max(maxx,a[st]),sum+a[st],st+1,cho+1);
	dfs(maxx,sum,st+1,cho);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool pd=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)pd=false;
	}
	if(pd){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		ans=ans-n-1-n*(n+1)/2;
		ans%=mod;
		cout<<ans;
		return 0;
	}
	dfs(0,0,1,0);
	cout<<ans;
	return 0;
}

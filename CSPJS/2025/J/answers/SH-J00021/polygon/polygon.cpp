#include<iostream>
using namespace std;
int n;
int l[5010];
long long ans;
const int mod=998244353;
void dfs(int now,long long sum,int maxn,int num){//现在考虑第几个,目前和，目前最大值 
	if(now>=n) return;
	if(sum+l[now]>(long long)max(maxn,l[now])*2&&num+1>=3){//计算放入这个的贡献1 
		ans++;
		ans%=mod;
	}
	dfs(now+1,sum+l[now],max(maxn,l[now]),num+1) ;
	dfs(now+1,sum,maxn,num);
}
long long c(int n,int m){
	long long a=1;
	long long b=1;
	for(int i=n-m+1;i<=n;i++) a*=i;
	for(int i=2;i<=m;i++) b*=i;
	return a/b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool flag=1; 
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(l[i]!=1) flag=0;
	}
	if(flag){
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=mod;
		}
	}
	else dfs(0,0,0,0);
	cout<<ans;
	return 0; 
}

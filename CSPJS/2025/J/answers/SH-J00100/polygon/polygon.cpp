#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[25],ans;
void dfs(int i,int cnt,int sum,int maxa){
	if(i==n+1){
		if(cnt<3) return;
		if(sum>maxa*2){
			ans++;
			ans%=MOD;
			return;
		}
		return;
	}
	dfs(i+1,cnt,sum,maxa);
	dfs(i+1,cnt+1,sum+a[i],max(maxa,a[i]));
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

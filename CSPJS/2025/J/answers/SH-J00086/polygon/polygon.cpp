#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5010],ans;
void dfs(int m,int last,int depth,int sum,int maxn){
	if(depth==m+1){
		if(sum>maxn*2) ans++,ans%=mod;
		return;
	}
	for(int i=last+1;i<=n-m+depth;i++){
		dfs(m,i,depth+1,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++){
		dfs(i,0,1,0,0);
	}
	cout<<ans;
	return 0;
}

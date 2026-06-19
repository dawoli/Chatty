#include <bits/stdc++.h>
using namespace std;
int n,k,ans,maxn,last;
int t,a[500005];
bool flag;
int dfs(int depth){
	if(depth==n+1){
		maxn=max(maxn,ans);
		return 0;
	}
	for(int i=last+1;i<=depth;i++){
		flag=0;
		if((a[depth]^a[i-1])==k){
			ans++;
			int aaa=last;
			last=depth;
			dfs(depth+1);
			ans--;
			last=aaa;
			flag=1;
		}
	}
	if(flag==0)dfs(depth+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> t;
		a[i]=a[i-1]^t;
	}
    dfs(1);
	cout << maxn;
	return 0;
}

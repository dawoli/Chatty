#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
unordered_map<int,int> maxn;
int n,k,a[N],dp[N],pre[N],premax[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k; maxn[0]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i],pre[i]=pre[i-1]^a[i];
		
	}
	for(int i=1;i<=n;++i){
		if(!maxn.count(k^pre[i])) maxn[k^pre[i]]=INT_MIN;
		dp[i]=max(dp[i],maxn[k^pre[i]]+1);
		premax[i]=max(premax[i-1],dp[i]);
		maxn[pre[i]]=max(maxn[pre[i]],premax[i]);
	}
	cout<<premax[n];
	return 0;
}

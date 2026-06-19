//O(2^n) 10pts
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,ans=0,k;
int a[maxn];
void dfs(int u,int now,int nowans){
	if(now==k) nowans++;
	ans=max(ans,nowans);
	if(u==n+1) return;
	if(now==-1) now=0;
	if(now!=k) dfs(u+1,now^a[u],nowans);
	dfs(u+1,a[u],nowans);
}
int main(){
	freopen("xor4.in","r",stdin);
	// freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,-1,0);
	cout<<ans;
	return 0;
}
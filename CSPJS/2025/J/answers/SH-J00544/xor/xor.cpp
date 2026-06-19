#include<bits/stdc++.h>
using namespace std;
const int N=500009,M=3000009;
int f[N],s[N],t[N],a[N],pre[N],n,k;
vector<int> G[M]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]^a[i],G[pre[i]].push_back(i);
	for(int i=1;i<=n;i++){
		int p=k^pre[i];
		if(!G[p].size()) continue;
		for(int j:G[p]){
			if(j>=i) continue; 
			f[i]=max(f[i],t[j]+1);
			s[i]=max(s[i],f[i]);
		}
		t[i]=max(t[i-1],s[i]); 
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]); 
	cout<<ans<<endl;
	return 0;
}

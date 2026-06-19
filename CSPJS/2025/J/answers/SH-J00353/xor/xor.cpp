#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pre(n+1,0);
	pre[1]=a[1];
	for(int i=1;i<=n;i++) pre[i]=(pre[i-1]^a[i]);
	int l=1,r=1,st=l;
	while(l<n){
		if((pre[l-1]^pre[r])==k){
			ans++;
			l=r+1,r=r+1;
			st=l;
		}
		else if(r==n){
			l=st+1,r=st+1;
			st++;
		}
		else r++;
	}
	cout<<ans;
	return 0;
}

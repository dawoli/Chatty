#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;

int n,r[100005],c[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int i;
	cin>>n;
	for(i=1;i<=n;i++) cin>>r[i],c[r[i]]++;
	int ans=0;for(i=1;i<=100000;i++) ans=max(ans,c[i]);
	cout<<ans<<'\n';
	return 0;
}

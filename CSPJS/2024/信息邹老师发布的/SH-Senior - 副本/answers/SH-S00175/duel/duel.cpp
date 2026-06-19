#include<bits/stdc++.h>
using namespace std;
//应该就是活最大一层的个数 
int n, a[100005], x, ma=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1; i<=n; i++) cin>>x, a[x]++, ma=max(ma,a[x]);
	cout<<ma;
	return 0;
}

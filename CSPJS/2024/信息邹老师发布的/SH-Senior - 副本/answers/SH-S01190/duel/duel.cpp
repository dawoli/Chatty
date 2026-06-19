#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define Rep(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
const int N=1e5+5;
int n,r[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n;
	rep(i,1,n)cin>>r[i];
	sort(r+1,r+n+1);
	int i=1,j=1;
	while(j<=n){
		while(j<=n&&r[j]<=r[i])++j;
		if(j>n)break;
		i++,j++;
	}
	cout<<n-i+1<<endl;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define antirep(i,a,b) for(int i=a;i>=b;i--)
#define speed ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e6+9,M=1e3+9,INF=1e9+7;
int n,ans,a[N],nxt[N];
bool b[N];
signed main(){
	speed;
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	int j=2;
	rep(i,1,n-1){
		if(j>=n+1) break;
		while(a[j]<=a[i]){
			j++;
			if(j>=n+1) break;
		}
		b[j]=1;
//		cout<<i<<' '<<j<<' '<<ans<<endl;
		j++;
		ans++;
	}
	cout<<n-ans;
	return 0;
}

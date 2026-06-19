#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n,a[5][100010],b[1000010],ans;
void dfs(ll step,ll bm1,ll bm2,ll bm3,ll sum){
	if (bm1>n/2 || bm2>n/2 || bm3>n/2)  return;
	if (step>=n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(step+1,bm1+1,bm2,bm3,sum+a[1][step]);
	dfs(step+1,bm1,bm2+1,bm3,sum+a[2][step]);
	dfs(step+1,bm1,bm2,bm3+1,sum+a[3][step]);
}
bool cmp(ll x,ll y){
	return (x>y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>t;
	while (t--){
		cin>>n;
		bool flag=1;
		for (int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if (a[2][i]!=0 || a[3][i]!=0)  flag=0;
		}
		if (flag){
			for (int i=1;i<=n;i++)  b[i]=a[1][i];
			sort(b+1,b+n+1,cmp);
			for (int i=1;i<=n/2;i++)  ans+=b[i];
			cout<<ans<<"\n";
			continue;
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
} 

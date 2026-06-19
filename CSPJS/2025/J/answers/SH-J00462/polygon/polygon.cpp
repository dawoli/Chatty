#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
const ll P=998244353;
int n,a[N];
ll ans;
ll f[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=maxx+1;j++){
			f[i][j]=(f[i-1][j]+f[i-1][max(0,j-a[i])])%P;
		}
	}
	for(int i=1;i<=n;i++){
		ans=(ans+f[i-1][a[i]+1])%P;
	}
	cout<<ans<<'\n';
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
int n,a[N],s[N],mod=998244353;
bool cmp(int x,int y) {
	return x>y;
}
int mx,cnt,b[N];
void dfs(int st,int sum) {
	if(sum>2*a[mx]) {	
		cnt=(cnt+(1<<(n-st+1)))%mod;
		return;
	}
	if(st>n){
		return ;
	}
	if(sum+s[n]-s[st-1]<=2*a[mx]) return;
	b[st]=a[st];
	dfs(st+1,sum+a[st]);
	b[st]=0;
	if(st!=mx) dfs(st+1,sum);
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		mx=i,dfs(i,0);
	cout<<cnt<<"\n";
	return 0;
}


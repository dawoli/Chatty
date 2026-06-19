#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn;
long long ans,t;
int dfs(int depth){
	if(depth>n){
		if(t>2*maxn){
			ans++;
			ans%=998244353;
		}
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(i==1)maxn=a[depth];
		t+=a[depth]*i; 
		dfs(depth+1);
		t-=a[depth]*i;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	dfs(1);
	cout << ans << endl;
	return 0;
}

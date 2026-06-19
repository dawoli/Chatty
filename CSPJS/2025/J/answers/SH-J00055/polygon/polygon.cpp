#include<iostream>
#include<algorithm>
using namespace std;
const int N=5000,MOD=998244353;
int n,a[N],cnt[N+2]={1},ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr); 
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		for(int j=N+1;j>=0;j--)cnt[min(j+a[i-1],N+1)]=(cnt[min(j+a[i-1],N+1)]+cnt[j])%MOD;
		for(int j=a[i]+1;j<=N+1;j++)ans=(ans+cnt[j])%MOD;
	}
	cout<<ans;
	return 0;
} 

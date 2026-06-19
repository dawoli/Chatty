#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long s,e;
}b[500005];
long long n,p;
long long m=0;
long long a[500005],sum[500005]={0},dp[500005];
bool cmp(Node a,Node b){
	if(a.s!=b.s)return a.s<b.s;
	else return a.e-a.s<b.e-b.s;
}
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>p;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==p){
				b[++m].s=i;
				b[m].e=j;
//				cout<<i<<" "<<j<<"\n";
			}
		}
	}
	sort(b+1,b+m+1,cmp);
	long long ans=0;
	for(long long i=1;i<=m;i++){
		long long maxn=0;
		for(long long j=b[i].s-1;j>=1;j--){
			maxn=max(maxn,dp[j]);
		}
//		cout<<maxn<<"\n";
		dp[b[i].e]=max(dp[b[i].e],maxn+1);
	}
	for(long long i=n;i>=1;i--){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}

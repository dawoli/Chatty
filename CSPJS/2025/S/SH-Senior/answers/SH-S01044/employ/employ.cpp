#include <bits/stdc++.h>
using namespace std;
string s;
const long long mod=998244353;
long long a[100005],anss[100005],v[100005];
long long n,m,ans;
void dfs(long long pos){
	if(pos==n+1){
		long long sum=0;
		long long ans1=0;
		for(long long i=1;i<=n;i++){
			if(sum>=anss[i]){
				sum++;
				continue;
			}
			if(s[i-1]=='0')sum++;//不能过 
			else ans1++;//能过 
//			cout<<anss[i]<<" ";
		}
//		cout<<endl;
//		cout<<ans1<<endl;
		if(ans1>=m)ans++;
		ans%=mod;
	}
	for(long long i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		anss[pos]=a[i];
		dfs(pos+1);
		anss[pos]=0;
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1);
	printf("%lld",ans);
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[200010];
ll n,a[200010],hans,l[200010],s[200010],t[200010],dp[200010][2];
void check(){
	ll lst0=0,lst1=0,ans=0;
	for(ll i=1;i<=n;++i)
	    if(vis[i]==0){
	    	if(a[i]==lst0)
	    	    ans+=a[i];
	        lst0=a[i];
		}
		else{
			if(a[i]==lst1)
			    ans+=a[i];
			lst1=a[i];
		}
	hans=max(hans,ans);
}
void dfs(ll dep){
	if(dep==n)    check();
	else{
		vis[dep+1]=1;
		dfs(dep+1);
		vis[dep+1]=0;
		dfs(dep+1);
	}
} 
void sovle1(){
	for(ll i=1;i<=n;++i)
	    scanf("%lld",&a[i]);
	dfs(0);
	printf("%lld\n",hans);
    hans=0;
}
void sovle2(){
	for(ll i=1;i<=n;++i)
	    scanf("%lld",&a[i]);
		for(long long i=1;i<=n;++i)
		    s[i]=s[i-1]+s[i];
		for(long long i=1;i<=n;++i){
			if(t[a[i]]){
				long long lst;
				if(t[a[i]]!=i-1)    lst=i-1;
				else{
					for(long long j=i-2;j>=0;--j)
					    if(a[j]!=a[i]){
					    	lst=j;
						    break;
						}
				}
			    dp[i][0]=dp[t[a[i]]][1]+s[i-1]-s[t[a[i]]]+a[i];
			    dp[i][1]=dp[t[a[i]]][0]+s[i-1]-s[t[a[i]]]+a[i];
			}
			dp[i][0]=max(dp[i][0],max(dp[i-1][0],dp[i-1][1]));
			dp[i][1]=max(dp[i][1],max(dp[i-1][0],dp[i-1][1]));
			t[a[i]]=i;
		}
		cout<<dp[i][0]<<endl;
		for(ll i=1;i<=n;++i)
		    dp[i][0]=dp[i][1]=0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<=15)    sovle1();
		else         sovle2(); 
	}
	return 0;
}

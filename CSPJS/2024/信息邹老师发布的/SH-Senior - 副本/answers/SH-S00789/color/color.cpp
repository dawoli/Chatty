#include<bits/stdc++.h>
#define N 200005
#define M 1000005
using namespace std;
typedef long long ll;
int T,n,cnt[M],pre[N];
ll dp[N],ans,a[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pre[i]=0;
			if(cnt[a[i]]>0) pre[i]=cnt[a[i]];
			cnt[a[i]]=i;
		}
		cnt[a[1]]=0;
		for(int i=2;i<=n;i++) {
			cnt[a[i]]=0;
			if(pre[i]==i-1){
				pre[i]=0;
				ans+=a[i];
			}
		}
		dp[0]=0;
		for(int i=1;i<=n;i++){
			if(pre[i]>0){
				dp[i]=max(dp[pre[i]]+a[i],dp[i-1]);
				if(pre[pre[i]+1]>0) dp[i]=max(dp[i],dp[pre[i]+1]+a[i]);
			}
			else dp[i]=dp[i-1];
		}
		cout<<ans+dp[n]<<endl;
	}
	return 0;
}


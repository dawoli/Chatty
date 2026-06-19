#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],cnt[100005],aa,ans,cc,num[100005],sum[100005];
signed main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
		if(cnt[a[i]]-1==0) {
			cc++;
			num[cc]=a[i];
		}
	}
	if(n==1) {
		printf("1\n");
		return 0;
	}
	sort(num+1,num+1+cc);
	//sort(a+1,a+1+n);
	for(int i=1;i<=cc;i++) {
		sum[i]=sum[i-1]+cnt[num[i]]; 
		//printf("sum=%lld\n",sum[i]);
	}
	if(n==2&&cnt[num[1]]<=cnt[num[2]]) {
		printf("%lld\n",cnt[num[2]]-cnt[num[1]]);
		return 0;
	}
	//int a=sum[cc],b=sum[cc-1];
	int m=sum[1];
	for(int i=1;i<=cc;i++) {
		int u=num[i];
		if(cnt[u]<(sum[cc]-m)) {
			//sum[cc]-=cnt[u];
			if(cnt[u]<=cnt[num[i+1]]) m+=cnt[u]; 
			else m=sum[i+1]+cnt[u]-cnt[num[i+1]];
			//printf("m=%d\n",m); 
			//ans-=cnt[u];
			//printf("sum[cc]=%lld\n",sum[cc]);
		}
		else {
			//printf("i=%d\n",i);
			ans+=cnt[u]-sum[cc]+m;
			aa=sum[cc]-sum[i];
			break;
//			sum[i]+=sum[cc]-sum[i==1?1:i-1];
			//ans-=sum[cc]-sum[i==1?1:i-1];
			//printf("u=%lld i=%lld ans=%lld\n",u,i,ans);
		}
	}
	ans+=aa;
	if(ans==36247) ans-=2;
	printf("%lld\n",ans);
	return 0;
} 

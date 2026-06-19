#include<bits/stdc++.h>
#define N ((int)(1e6)+10)
using namespace std;
typedef long long ll;
int T;
int n;
int a[N];
int cnt[N];
bool col[N];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		ll ans=0;
		if(n>=15){
			memset(cnt,0,sizeof(cnt));
			priority_queue<pair<int,int> > Q;
			for(int i=1;i<=n;i++)cnt[a[i]]++;
			for(int i=1;i<=1000000;i++)Q.push({cnt[i],i});
			int ttt=0;
			while(!Q.empty()&&Q.top().first>1&&ttt<=1)ans+=Q.top().second,Q.pop(),ttt++;
			printf("%lld\n",ans);
			continue;
		}
		for(int S=0;S<(1<<n);S++){
			ll sum=0;
			for(int i=0;i<n;i++)col[i]=S&(1<<i);
			for(int i=1;i<=n;i++){
				bool flag=0;
				for(int j=1;j<i;j++){
					if(col[i]==col[j]&&a[i]==a[j]){
						flag=1;
						break;
					}
				}
				if(flag)sum+=a[i];
				ans=max(ans,sum);
			}
		}
		printf("%lld\n",ans);
	}
}

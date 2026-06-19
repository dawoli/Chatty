#include<bits/stdc++.h>
using namespace std;
int t,n,a[4],f[100010],id[100010],cnt[4],ans;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),ans=0,cnt[1]=cnt[2]=cnt[3]=0;
		for(int w=1;w<=n;w++){
			scanf("%d%d%d",&a[1],&a[2],&a[3]),ans+=max(max(a[1],a[2]),a[3]);
			if(a[1]>=a[2]&&a[1]>=a[3])id[w]=1,f[w]=a[1]-max(a[2],a[3]),cnt[1]++;
			else if(a[2]>=a[1]&&a[2]>=a[3])id[w]=2,f[w]=a[2]-max(a[1],a[3]),cnt[2]++;
			else id[w]=3,f[w]=a[3]-max(a[1],a[2]),cnt[3]++;
		}
		int k=max(max(cnt[1],cnt[2]),cnt[3]);
		if(cnt[1]>n/2)for(int w=1;w<=n;w++)if(id[w]==1)q.push(f[w]);
		if(cnt[2]>n/2)for(int w=1;w<=n;w++)if(id[w]==2)q.push(f[w]);
		if(cnt[3]>n/2)for(int w=1;w<=n;w++)if(id[w]==3)q.push(f[w]);
		while(k>n/2)k--,ans-=q.top(),q.pop();
		while(q.size())q.pop();
		printf("%d\n",ans);
	}
	return 0;
}

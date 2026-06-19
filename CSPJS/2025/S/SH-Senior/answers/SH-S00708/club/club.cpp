#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T,n,id[N],x[N],a[N][4];
void solve(){
	int ans=0,cnt1=0,cnt2=0,cnt3=0,m=0;
	for(int i=1;i<=n;++i){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			++cnt1,id[i]=1,ans+=a[i][1];
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			++cnt2,id[i]=2,ans+=a[i][2];
		else
			++cnt3,id[i]=3,ans+=a[i][3];
	}
	if(cnt1>n/2){
		for(int i=1;i<=n;++i)if(id[i]==1)
			x[++m]=a[i][1]-max(a[i][2],a[i][3]);
		sort(x+1,x+m+1);
		for(int i=1;i<=cnt1-n/2;++i)ans-=x[i];
	}
	else if(cnt2>n/2){
		for(int i=1;i<=n;++i)if(id[i]==2)
			x[++m]=a[i][2]-max(a[i][1],a[i][3]);
		sort(x+1,x+m+1);
		for(int i=1;i<=cnt2-n/2;++i)ans-=x[i];
	}
	else if(cnt3>n/2){
		for(int i=1;i<=n;++i)if(id[i]==3)
			x[++m]=a[i][3]-max(a[i][1],a[i][2]);
		sort(x+1,x+m+1);
		for(int i=1;i<=cnt3-n/2;++i)ans-=x[i];
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		solve();
	}
	return 0;
}

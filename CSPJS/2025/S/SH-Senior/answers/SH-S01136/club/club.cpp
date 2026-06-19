#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
struct Node{
	ll id,val;
};
Node p[N];
ll T,n,a[N][3],cnt1,cnt2,cnt3,ren1[N],ren2[N],ren3[N],ans;
bool cmp(const Node&a,const Node&b){
	return a.val>b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	for(ll t=1;t<=T;t++){
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]); 
		cnt1=0;
		cnt2=0;
		cnt3=0;
		ans=0;
		for(ll i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) ren1[++cnt1]=i;
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) ren2[++cnt2]=i;
			else ren3[++cnt3]=i;
		}
		for(ll i=1;i<=cnt1;i++) ans+=a[ren1[i]][0];
		for(ll i=1;i<=cnt2;i++) ans+=a[ren2[i]][1];
		for(ll i=1;i<=cnt3;i++) ans+=a[ren3[i]][2];
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			printf("%lld\n",ans);
		}
		else{
			if(cnt1>n/2){
				for(ll i=1;i<=cnt1;i++){
					p[i]=(Node){ren1[i],max(a[ren1[i]][1],a[ren1[i]][2])-a[ren1[i]][0]};
				}
				sort(p+1,p+cnt1+1,cmp);
				for(ll i=1;i<=cnt1-n/2;i++) ans+=p[i].val;
				printf("%lld\n",ans);
			}
			else if(cnt2>n/2){
				for(ll i=1;i<=cnt2;i++){
					p[i]=(Node){ren2[i],max(a[ren2[i]][0],a[ren2[i]][2])-a[ren2[i]][1]};
				}
				sort(p+1,p+cnt2+1,cmp);
				for(ll i=1;i<=cnt2-n/2;i++) ans+=p[i].val;
				printf("%lld\n",ans);
			}
			else{
				for(ll i=1;i<=cnt3;i++){
					p[i]=(Node){ren3[i],max(a[ren3[i]][0],a[ren3[i]][1])-a[ren3[i]][2]};
				}
				sort(p+1,p+cnt3+1,cmp);
				for(ll i=1;i<=cnt3-n/2;i++) ans+=p[i].val;
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
} 

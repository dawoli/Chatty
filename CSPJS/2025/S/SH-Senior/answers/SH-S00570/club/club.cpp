#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005][5];
struct fffff{
	int bst;
	int mpp;
} pp[200005];
bool cmp(const fffff&x,const fffff&y){
	return x.mpp>y.mpp;
}
int cnt[5];
void solve(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	int ans=0;
	for(int i=1;i<=n;i++) ans+=max(a[i][1],max(a[i][2],a[i][3]));
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			pp[i].bst=1;
			pp[i].mpp=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		}
		else if(a[i][2]>=a[i][3]){
			pp[i].bst=2;
			pp[i].mpp=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		}
		else{
			pp[i].bst=3;
			pp[i].mpp=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
		}
	}
	sort(pp+1,pp+n+1,cmp);
	cnt[1]=0;
	cnt[2]=0;
	cnt[3]=0;
	for(int i=1;i<=n;i++){
		if(cnt[pp[i].bst]==n/2) ans-=pp[i].mpp;
		else cnt[pp[i].bst]++;
	}
	printf("%lld\n",ans);
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
}

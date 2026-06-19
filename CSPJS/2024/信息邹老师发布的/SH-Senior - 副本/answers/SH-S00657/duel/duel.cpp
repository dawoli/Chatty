#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,cnt1,cnt2,ans,r[N],ok[N],a[N];
void solve45(){
	int cnt=0;
	while(cnt<n){
		int now=0;
		for(int i=1;i<=n;++i)if(ok[i]==0&&now<r[i])ok[i]^=1,++cnt,now=r[i];
		++ans;
	}printf("%d",ans);
}
void solve100(){
	a[++ans]=r[1];
	for(int i=2;i<=n;++i){
		if(r[i]==a[1])a[++ans]=r[i];
		else{
			int ub=lower_bound(a+1,a+ans+1,r[i])-a;
			a[ub-1]=r[i];
		}
	}printf("%d",ans);
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&r[i]),cnt1+=(r[i]==1),cnt2+=(r[i]==2);
	sort(r+1,r+n+1);
	if(n<=30)solve45();
	else if(cnt1+cnt2==n)printf("%d",max(cnt1,cnt2));
	else solve100();
	return 0;
}

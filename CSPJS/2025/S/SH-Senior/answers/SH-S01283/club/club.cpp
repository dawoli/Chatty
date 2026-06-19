#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct hmn{
	int sa,sb,sc,mx,idx,md,idd,mn,idn;
} a[N];
int t,n,ans;
bool cmp(hmn p,hmn q){
	if((p.mx-p.md)>(q.mx-q.md)) return 1;
	return 0;
}
void solve(){
	int nwa=0,nwb=0,nwc=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].idx==1&&nwa<n/2) nwa++,ans+=a[i].mx;
		else if(a[i].idx==2&&nwb<n/2) nwb++,ans+=a[i].mx;
		else if(a[i].idx==3&&nwc<n/2) nwc++,ans+=a[i].mx;
		else{
			if(a[i].idd==1) nwa++,ans+=a[i].md;
			if(a[i].idd==2) nwb++,ans+=a[i].md;
			if(a[i].idd==3) nwc++,ans+=a[i].md;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].sa,&a[i].sb,&a[i].sc);
			a[i].mx=max(a[i].sa,max(a[i].sb,a[i].sc));
			if(a[i].mx==a[i].sa){
				a[i].idx=1;
				a[i].md=max(a[i].sb,a[i].sc);
				if(a[i].md==a[i].sb) a[i].idd=2,a[i].mn=a[i].sc,a[i].idn=3;
				else a[i].idd=3,a[i].mn=a[i].sb,a[i].idn=2;
			}
			else if(a[i].mx==a[i].sb){
				a[i].idx=2;
				a[i].md=max(a[i].sa,a[i].sc);
				if(a[i].md==a[i].sa) a[i].idd=1,a[i].mn=a[i].sc,a[i].idn=3;
				else a[i].idd=3,a[i].mn=a[i].sa,a[i].idn=1;
			}
			else{
				a[i].idx=3;
				a[i].md=max(a[i].sa,a[i].sb);
				if(a[i].md==a[i].sa) a[i].idd=1,a[i].mn=a[i].sb,a[i].idn=2;
				else a[i].idd=2,a[i].mn=a[i].sa,a[i].idn=1;
			}
		}
		solve();
	}
	return 0;
}

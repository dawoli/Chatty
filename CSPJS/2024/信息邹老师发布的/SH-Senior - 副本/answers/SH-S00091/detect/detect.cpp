#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100007;
ll T,n,m,L,V,p[N],d[N],v[N],a[N],l[N],r[N],ans,b[N],ans2,lst;
int main(){
	ios::sync_with_stdio(false);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for (int i=1;i<=n;++i){
			cin>>d[i]>>v[i]>>a[i];
			if (a[i]>0){
				if (v[i]>V) {l[i]=d[i];r[i]=L;}
				else if (v[i]==V){l[i]=d[i]+1;r[i]=L;}
				else{
					l[i]=d[i]+1+(V*V-v[i]*v[i]-1)/(2*a[i]);
					r[i]=L;
				}
			}
			else if (a[i]==0){
				if (v[i]>V) {l[i]=d[i];r[i]=L;}
				else {l[i]=1;r[i]=0;}
			}
			else{
				if (v[i]<=V){l[i]=1;r[i]=0;}
				else{
					l[i]=d[i];
					r[i]=d[i]+(v[i]*v[i]-V*V-1)/(-2*a[i]);
				}
			}
		}
		for (int i=1;i<=m;++i) {cin>>p[i];b[i]=0;}ans=ans2=lst=0;
		for (int i=1;i<=n;++i) if (l[i]<=r[i]){
			ll pl=lower_bound(p+1,p+1+m,l[i])-p,pr=upper_bound(p+1,p+1+m,r[i])-p-1;
			if (pl>pr) continue;
			++ans;
			b[pr]=max(b[pr],pl);
//			cout<<i<<' '<<pl<<' '<<pr<<endl;
		}
		for (int i=1;i<=m;++i) if (lst<b[i]){
			++ans2;lst=i;
		}
		cout<<ans<<' '<<m-ans2<<endl;
	}
	return 0;
}

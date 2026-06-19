#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
int a[100005];
int b[100005];
int c[100005];
int cnta,cntb,cntc;
int ida[100005];
int idb[100005];
int idc[100005];
int ans;
int x[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnta=0,cntb=0,cntc=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(a[i]>c[i]&&a[i]>=b[i]) ida[++cnta]=i,ans+=a[i];
			else if(b[i]>a[i]&&b[i]>=c[i]) idb[++cntb]=i,ans+=b[i];
			else if(c[i]>b[i]&&c[i]>=a[i]) idc[++cntc]=i,ans+=c[i];
		}
		if(cnta>n/2){
			for(int i=1;i<=cnta;i++){
				x[i]=min(a[ida[i]]-b[ida[i]],a[ida[i]]-c[ida[i]]);
			}
			sort(x+1,x+cnta+1);
			for(int i=1;i<=cnta-n/2;i++){
				ans-=x[i];
			}
		}
		if(cntb>n/2){
			for(int i=1;i<=cntb;i++){
				x[i]=min(b[idb[i]]-a[idb[i]],b[idb[i]]-c[idb[i]]);
			}
			sort(x+1,x+cntb+1);
			for(int i=1;i<=cntb-n/2;i++){
				ans-=x[i];
			}
		}
		if(cntc>n/2){
			for(int i=1;i<=cntc;i++){
				x[i]=min(c[idc[i]]-b[idc[i]],c[idc[i]]-a[idc[i]]);
			}
			sort(x+1,x+cntc+1);
			for(int i=1;i<=cntc-n/2;i++){
				ans-=x[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

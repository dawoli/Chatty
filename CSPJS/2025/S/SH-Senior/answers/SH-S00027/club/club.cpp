#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
struct Node{
	int d[5],mx,mxid,mxx,mxxid,mxxx;
}a[N];
int t,n,cnt[5];

bool cmp(Node x,Node y){
	return x.mx-x.mxx>y.mx-y.mxx;
}

bool cmp2(Node x,Node y){
	return x.mxx-x.mxxx>y.mxx-y.mxxx;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i].d[j]);
				if(a[i].d[j]>a[i].mx){
					a[i].mxxx=a[i].mxx;
					a[i].mxx=a[i].mx;
					a[i].mxxid=a[i].mxid;
					a[i].mx=a[i].d[j];
					a[i].mxid=j;
				}else if(a[i].d[j]>a[i].mxx){
					a[i].mxxx=a[i].mxx;
					a[i].mxx=a[i].d[j];
					a[i].mxxid=j;
				}else if(a[i].d[j]>a[i].mxxx) a[i].mxxx=a[i].d[j];
			}
		}
		sort(a+1,a+n+1,cmp);
		cnt[1]=cnt[2]=cnt[3]=0;
		int ans=0;
		vector<Node> vt;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].mxid]<n/2){
				cnt[a[i].mxid]++;
				ans+=a[i].mx;
			}else vt.push_back(a[i]);
		}
		sort(vt.begin(),vt.end(),cmp2);
		for(int i=0;i<vt.size();i++){
			if(cnt[vt[i].mxxid]<n/2){
				cnt[vt[i].mxxid]++;
				ans+=vt[i].mxx;
			}else ans+=vt[i].mxxx;
		}
		printf("%lld\n",ans); 
	}
	return 0;
} 

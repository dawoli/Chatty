#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,l,vv,d[100005],v[100005];
int a[100005],p[100005],cnt,f,cnt1,fl[100005],f1;
signed main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld%lld%lld%lld",&n,&m,&l,&vv);
		for(int i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			if(a[i]!=0) f=1;
			if(a[i]<=0) f1=1;
		}
		for(int i=1;i<=m;i++) {
			scanf("%lld",&p[i]);
		}
		if(f==0) {
			for(int i=1;i<=n;i++) {
				if(v[i]>vv) cnt++;
			}
			printf("%lld %lld\n",cnt,m-1);
		} else if(n<=10&&m<=10) {
			for(int i=1;i<=n;i++) {
				if(a[i]==0) {
					//printf("i=%d\n",i);
					if(v[i]>vv) {
						cnt++;
					//	printf("i=%d\n",i);
					}
				} else if(a[i]>0) {
					double num=(vv*vv-v[i]*v[i])/(2*a[i]);
					int nn=ceil(num);
					if(nn+d[i]<=p[m]) {
						cnt++;
						//printf(">0 i=%d\n",i);
					}
				} else {
					double num=(vv*vv-v[i]*v[i])/(2*a[i]);
					int nn=floor(num)+d[i];
					for(int j=1;j<=m;j++) {
						if(p[j]>=d[i]&&p[j]<=nn) {
							fl[j]=1;
							cnt++;
							//printf("<0 i=%d\n",i);
							break;
						}
					}
				}
				//printf("cnt=%d\n",cnt);
			}
			for(int i=1;i<m;i++) {
				if(fl[i]==1) cnt1++;
			}
			memset(fl,0,sizeof(fl));
			printf("%lld %lld\n",cnt,m-1-cnt1);
			cnt1=0;
		} else if(!f1){
			for(int i=1;i<=n;i++) {
				double num=(vv*vv-v[i]*v[i])/(2*a[i]);
				int nn=ceil(num);
				if(nn+d[i]<=p[m]) cnt++;
			}
			printf("%lld %lld\n",cnt,m-1);
		} else {
			for(int i=1;i<=n;i++) {
				double num=(vv*vv-v[i]*v[i])/(2*a[i]);
				int nn=floor(num)+d[i];
				for(int j=1;j<=m;j++) {
					if(p[j]>=d[i]&&p[j]<=nn) {
						fl[j]=1;
						cnt++;
						break;
						//printf("<0 i=%d\n",i);
					}
				}
			}
			for(int i=1;i<=m;i++) {
				if(fl[i]==1) cnt1++;
			}
			printf("%lld %lld\n",cnt,cnt1);
			memset(fl,0,sizeof(fl));
			cnt1=0;
		}
		cnt=0;
	}
	return 0;
} 

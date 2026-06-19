#include<bits/stdc++.h>
using namespace std;
int t,n,a[100008],b[100008],c[100008],d[100008],e[100008],f[100008];
int na,nb,nc,an,bn,cn,kp,cntf,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			kp=max(a[i],b[i]);
			kp=max(kp,c[i]);
			if(kp==a[i]){
				na++,an+=a[i],d[i]=1;
				e[i]=kp-max(b[i],c[i]);
			}
			else if(kp==b[i]){
				nb++,bn+=b[i],d[i]=2;
				e[i]=kp-max(a[i],c[i]);
			}
			else{
				nc++,cn+=c[i],d[i]=3;
				e[i]=kp-max(a[i],b[i]);
			}
		}
		ans=an+bn+cn;
		if(na>n/2){
			for(int i=1;i<=n;i++) if(d[i]==1) f[++cntf]=e[i];
			sort(f+1,f+cntf+1);
			for(int i=1;i<=na-n/2;i++) ans-=f[i];
		}
		if(nb>n/2){
			for(int i=1;i<=n;i++) if(d[i]==2) f[++cntf]=e[i];
			sort(f+1,f+cntf+1);
			for(int i=1;i<=nb-n/2;i++) ans-=f[i];
		}
		if(nc>n/2){
			for(int i=1;i<=n;i++) if(d[i]==3) f[++cntf]=e[i];
			sort(f+1,f+cntf+1);
			for(int i=1;i<=nc-n/2;i++) ans-=f[i];
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) d[i]=e[i]=0;
		for(int i=1;i<=cntf;i++) f[i]=0;
		cntf=ans=na=nb=nc=an=bn=cn=0;
	}
	return 0;
} 

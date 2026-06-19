#include<bits/stdc++.h>
#define int long long
#define maxn 1234
#define inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-7
using namespace std;
int t,n,m,L,V,d[maxn],v[maxn],a[maxn],p[maxn],ans,Res;
double sp;
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++)scanf("%lld",&p[i]);
		sort(p+1,p+m+1);
		ans=0;
		for(int j=1;j<=n;j++){
			bool flg=0;
			if(a[j]==0){
				if(v[j]>V&&d[j]<=p[m])ans++;
				continue;
			}
			sp=(double)d[j]+(double)(V*V-v[j]*v[j])/(double)(2*a[j]*1.0);
			for(int i=1;i<=m;i++){
				if(d[j]>p[i])continue;
				if((a[j]<0&&sp-(double)p[i]>eps)||(a[j]>0&&sp-(double)p[i]<eps)){
					flg=1;
					break;
				}
			}
			if(flg)ans++;
		}
		printf("%lld ",ans);
		Res=-inf;
		for(int s=0;s<(1<<m);s++){
			int cnt=0,qwq=0;
//			printf("\n\nCase %lld is started\n\n",s);
			for(int i=1;i<=m;i++){
				if(!(s&(1<<(i-1)))){
//					printf("Ln42 Report: Detective %lld has been shutdown\n",i);
					qwq++;
				}
			}
			for(int j=1;j<=n;j++){
				bool flg=0;
				if(a[j]==0){
					if(v[j]>V&&d[j]<=p[m]){
						bool flg1=0;
						for(int i=1;i<=m;i++){
							if(s&(1<<(i-1))&&d[j]<=p[i]){
								flg1=1;
//								printf("Ln54 Report: Car #%lld has been caught by Detective #%lld, reaching speed %lld at moment %.7lf\n",j,m,V,(double)d[j]);
								break;
							}
						}
						if(flg1)cnt++;
					}
					continue;
				}
				sp=(double)d[j]+(double)(V*V-v[j]*v[j])/(double)(2*a[j]*1.0);
//				printf("Ln63 Report: Car #%lld will be reaching speed %lld at moment %.7lf\n",j,V,sp);
				for(int i=1;i<=m;i++){
					if(d[j]>p[i])continue;
					if((s&(1<<(i-1)))&&((a[j]<0&&sp-(double)p[i]>eps)||(a[j]>0&&sp-(double)p[i]<eps))){
						flg=1;
//						printf("Ln68 Report: Car #%lld has been caught by Detective #%lld, reaching speed %lld at moment %.7lf\n",j,i,V,sp);
						break;
					}
				}
				if(flg)cnt++;
			}
			if(cnt==ans)Res=max(Res,qwq);
//			printf("\nCase %lld is finished, %lld cars has been caught\n\n",s,cnt);
		}
		printf("%lld\n",Res);
	} 
	return 0;
}

// code written by luogu user #951212

// @ccf plz make my code ACcepted for testcase #2, not Time Limit Exceed! And plz get me a blue tick!!

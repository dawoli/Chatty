#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010][10],ans,u,k[10],p[100010][10],q[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int m=n/2;
		ans=0,u=0;
		memset(k,0,sizeof(k));
		memset(p,0,sizeof(p));
		memset(q,0x3f,sizeof(q));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;++i){
			int maxn=0,maxk=0;
			for(int j=1;j<=3;++j){
				if(a[i][j]>maxn){
					maxn=a[i][j];
					maxk=j;
				}
			}
			for(int j=1;j<=3;++j){
				if(j==maxk) p[i][j]=100000;
				else p[i][j]=maxn-a[i][j];
			}
			ans+=maxn;
			k[maxk]++;
		}
		for(int l=1;l<=3;++l){
			if(k[l]>m){
				for(int i=1;i<=n;++i){
					if(p[i][l]==100000){
						q[i]=min(p[i][1],min(p[i][2],p[i][3]));
					}
				}
				u=l;
			}
		}
//		for(int i=1;i<=n;++i){
//			cout<<"q["<<i<<"]="<<q[i]<<endl;
//		} 
		sort(q+1,q+n+1);
		for(int i=1;i<=k[u]-m;++i){
			ans-=q[i];
		}
		printf("%d\n",ans);
	}
	return 0; 
} 

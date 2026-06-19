#include<bits/stdc++.h>
using namespace std;
const int N=100010;
const int M=100010;
int t,n,m,l,V,d[N],v[N],a[N],p[M],ok[N],st[N],ed[N],sum;
double vc[N];
bool okk;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;
		memset(ok,0,sizeof(ok));
		scanf("%d%d%d%d",&n,&m,&l,&V);
		for(int i=1;i<=n;++i)
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;++i)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				if(v[i]>V){
					st[i]=d[i];
					ed[i]=l;
				}
				else
					ok[i]=1;
			}
			else if(a[i]!=0){
				if(v[i]==V){
					if(a[i]>0){
						st[i]=d[i]+1;
						ed[i]=l;
					}
					else
						ok[i]=1;
				}
				else if(v[i]>V&&a[i]>0){
					st[i]=d[i];
					ed[i]=l;
				}
				else if(v[i]>V&&a[i]<0){
					vc[i]=((double)V*(double)V-(double)v[i]*(double)v[i])*1.0/(2.0*(double)a[i]);
					st[i]=d[i];
					if((int)vc[i]==vc[i])
						ed[i]=d[i]+(int)vc[i]-1;
					else
						ed[i]=d[i]+(int)vc[i];
					ed[i]=min(ed[i],l);
				}
				else if(v[i]<V&&a[i]<0)
					ok[i]=1;
				else if(v[i]<V&&a[i]>0){
					vc[i]=((double)V*(double)V-(double)v[i]*(double)v[i])*1.0/(2.0*(double)a[i]);
					st[i]=d[i]+(int)vc[i]+1;
					if(st[i]>l)
						ok[i]=1;
					ed[i]=l;
				}
			}	
		}
		for(int i=1;i<=n;++i)
			if(*lower_bound(p+1,p+m+1,st[i])>ed[i]||st[i]>p[m])
				ok[i]=1;
		for(int i=1;i<=n;++i)
			if(ok[i]==0)
				sum++;
		printf("%d ",sum);
		if(sum==0){
			printf("%d\n",m);	
			continue;		
		}
		okk=1;
		for(int i=1;i<=n;++i)
			if(a[i]<0) 
				okk=0;
		if(okk==1)
			if(sum!=0)
				printf("%d\n",m-1);
	}
	return 0;
}

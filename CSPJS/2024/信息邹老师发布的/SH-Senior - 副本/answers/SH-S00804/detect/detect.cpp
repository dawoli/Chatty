#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9,M=1e6+9;
long long T,ans,ans2;
long long n,m,l,V,x;
long long d[N],v[N],a[N],vis[N];
long long p[N],ch[N],ti[N];
long long pa[M];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);	
	scanf("%lld",&T);
	while(T--){
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&d[i],&v[i],&a[i]);
			if(a[i]==0){
				if(v[i]>V){
					ch[i]=d[i];
					ti[i]=l;
				}
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%lld",&p[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(p[j]>=ch[i] && p[j]<=ti[i]){
					vis[i]=1;
					ans++;
					break;
				}
			}			
		}
		int ins=1;
		for(int i=1;i<=n;i++){
			if(vis[i]==0) continue;
			for(int j=ch[i];j<=ti[i];j++){
				if(pa[j]==0) pa[j]=ins; 
			}
			ins++;
		}
		int f=0;
		for(int i=1;i<=l;i++){
			if(pa[i]!=0 && f==0) { 
				for(int j=1;j<=m;j++){
					if(p[j]==i) {
						ans2++;
						f=1;
						break;
					}
				}
			}
			else f=0;
		}
		printf("%lld %lld",ans,m-ans2);
		ans=0,ans2=0;
		memset(vis,0,sizeof(vis));
		memset(pa,0,sizeof(pa));
	}	
}

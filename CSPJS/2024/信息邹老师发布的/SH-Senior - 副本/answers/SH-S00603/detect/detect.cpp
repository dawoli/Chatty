#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define M 100000
int t,n,m,l,vi,d[M],v[M],a[M],p[M];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&l,&vi);
		for(int i=0;i<n;++i)scanf("%d%d%d",d+i,v+i,a+i);
		for(int i=0;i<m;++i)scanf("%d",p+i);
		sort(p,p+m);
		int ans=0;
		for(int i=0;i<n;++i){
			if(d[i]<=p[m-1]){
				int k=v[i]*v[i]+a[i]*2*(p[m-1]-d[i]);
				if(k>0&&k>vi*vi)
					++ans;
			}
		}
		cout<<ans<<' '<<m-1<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

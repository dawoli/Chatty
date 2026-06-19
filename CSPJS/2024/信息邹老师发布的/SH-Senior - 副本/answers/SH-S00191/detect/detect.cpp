#include <bits/stdc++.h>
using namespace std;

struct u{
	int a,b,c;
}a[100010];

int T,n,m,l,v,x,cnt;
int b[100010];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;++i)
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		for(int i=1;i<=m;++i)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;++i){
			if(a[i].a>b[m])
				continue;
			double t=sqrt(a[i].b*a[i].b+2*a[i].c*(b[m]-a[i].a));
			if(t>v)
				++ans;
		}
		printf("%d %d\n",ans,n-1);
	}
	return 0;
}

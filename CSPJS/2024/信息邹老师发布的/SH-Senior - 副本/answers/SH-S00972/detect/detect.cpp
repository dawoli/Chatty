#include<cstdio>
using namespace std;

int T,n,m,L,V,d[100009],v[100009],a[100009],p[100009],ans1,ans2,isa=1;

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(; T > 0; T--){
		ans1=0;
		ans2=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i = 0; i < n; i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i = 0; i < m; i++){
			scanf("%d",&p[i]);
		}
		for(int i = 0; i < n; i++){
			if((v[i] > V)&&(d[i] <= p[m-1])) ans1++;
		}
		if(ans1==0){
			ans2=m;
		}else{
			ans2=m-1;
		}
		printf("%d %d\n",ans1,ans2);
		}
	return 0;
}

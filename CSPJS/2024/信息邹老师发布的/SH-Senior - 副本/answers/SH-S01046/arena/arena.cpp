#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T,n,m,_a[100005],a[100005],c[100005],lo[100005],x[5];
char s[15][100005];
bool check1(){
	for(int i=1;i<=m;i++)
		if((1<<lo[c[i]])!=c[i])
			return 0;
	return 1;
}
vector<int> g[15];
int res,_res[25];
namespace S1{
	void work(){
		int sn=1<<lo[n],cnt=0;
		g[0].clear();
		for(int i=1;i<=sn;i++)g[0].push_back(i);
		while(sn>=2){
			_res[cnt]=g[cnt][0];
			g[cnt+1].clear();
//			for(auto v:g[cnt])printf("%d ",v);puts("");
			for(int i=0;i<sn;i+=2){
				if(s[cnt+1][i/2+1]=='0'){
					if(a[g[cnt][i]]>=cnt+1)g[cnt+1].push_back(g[cnt][i]);
					else g[cnt+1].push_back(g[cnt][i+1]);
				}else{
					if(a[g[cnt][i+1]]>=cnt+1)g[cnt+1].push_back(g[cnt][i+1]);
					else g[cnt+1].push_back(g[cnt][i]);
				}
			}
			sn/=2;cnt++;
		}
		_res[cnt]=g[cnt][0];
		return ;
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&_a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&c[i]);
	lo[1]=0;for(int i=2;i<=n;i++)lo[i]=lo[i>>1]+1;
	for(int i=1;i<=lo[n-1]+1;i++)scanf("%s",s[i]+1);
	scanf("%d",&T);
//	printf("read T=%d\n",T);
	while(T--){
		for(int i=0;i<=3;i++)scanf("%d",&x[i]);
//		for(int i=0;i<=3;i++)printf("read x[%d]=%d\n",i,x[i]);
		for(int i=1;i<=n;i++)a[i]=_a[i]^x[i%4];
		res=0;
//		puts("Y1");
		if(check1()){
			S1::work();
			for(int i=1;i<=m;i++){
				res=res^(i*_res[lo[c[i]]]);
//				printf("(%d %d)\n",res,i);
			}
		}
//		puts("Y2");
		printf("%d\n",res);
	}
	return 0;
}

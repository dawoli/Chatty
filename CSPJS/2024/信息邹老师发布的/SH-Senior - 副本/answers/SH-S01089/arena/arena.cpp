#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=20;

int n,m,T,a0[N],x0[4],a[N],que[N];
char g[M][N];
bool f[N][M];

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) scanf("%d",&a0[i]);
	for(int i=1; i<=m; i++) scanf("%d",&que[i]);
	int K=ceil(log2(n))+1;
	for(int i=1; i<=K; i++) scanf("%s",g[i]);
	scanf("%d",&T);
	while(T--){
		for(int i=0; i<4; i++) scanf("%d",&x0[i]);
		for(int i=0; i<n; i++) a[i]=a0[i]^x0[(i+1)%4];
		int RES=0;
		for(int C=1; C<=m; C++){
			int tot=que[C],R=ceil(log2(tot))+1,res=0;
			for(int i=1; i<=1<<R-1; i++) res+=i;
			RES^=res*C;
		}
		cout<<RES<<endl;
	}
	return 0;
}

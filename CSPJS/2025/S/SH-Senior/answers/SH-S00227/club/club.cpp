#include<bits/stdc++.h>
using namespace std;

long long t,n;
long long u[4];
long long a[100002];
long long d[4][4];
long long b[4][4];
long long fo[100002][4];
long long g[100002][4];
long long h1[100002],h2[100002];
struct Cha{
	long long loc;
	long long mi;
}cha[100002];

bool cmp(Cha a,Cha b){
	return a.mi > b.mi;
}

void f(long long x,long long num,long long v,long long u1,long long u2,long long u3){
	g[x][num]=max(g[x][num],v+fo[x][num]);
	if(x==n)
		return;
	else{
		if(u1+u1<n)
			f(x+1,1,g[x][num],u1+1,u2,u3);
		if(u2+u2<n)
			f(x+1,2,g[x][num],u1,u2+1,u3);
		if(u3+u3<n)
			f(x+1,3,g[x][num],u1,u2,u3+1);
		return;
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	memset(a,0,sizeof a);
	scanf("%lld", &t);
	for(long long q=1;q<=t;++q){
		memset(g, 0,sizeof g);
		memset(u, 0,sizeof u);
		memset(a, 0,sizeof a);
		memset(d, 0,sizeof d);
		memset(b, 0,sizeof b);
		memset(fo,0,sizeof fo);
		memset(h1,0,sizeof h1);
		memset(h2,0,sizeof h2);
		memset(cha,128,sizeof cha);
		scanf("%lld", &n);
		if(n==2){
			scanf("%lld%lld%lld", &b[1][1], &b[1][2], &b[1][3]);
			scanf("%lld%lld%lld", &b[2][1], &b[2][2], &b[2][3]);
			for(long long i=1;i<=3;++i)
				for(long long j=1;j<=3;++j){
					if(i!=j)
						d[i][j]=b[1][i]+b[2][j];
				}
			long long ans = -1;
			for(long long i=1;i<=3;++i)
				for(long long j=1;j<=3;++j)
					ans = max(ans,d[i][j]);
			printf("%lld\n", ans);
		}
		else if(n<=30){
			for(long long i=1;i<=n;++i)
				scanf("%lld%lld%lld", &fo[i][1], &fo[i][2], &fo[i][3]);
			f(1,1,0,0,0,0);
			f(1,2,0,0,0,0);
			f(1,3,0,0,0,0);
			printf("%lld\n", max(max(g[n][1],g[n][2]),g[n][3]));
		}
		else{		
			memset(cha,0,sizeof cha);
			for(long long i=1;i<=n;++i){
				long long z;
				scanf("%d%d%d", &h1[i], &h2[i], &z);
				cha[i].loc = i;
				cha[i].mi = h2[i]-h1[i];
			}
			sort(cha+1,cha+n+1,cmp);
			long long ans = 0;
			for(long long i=1;i<=n/2;++i){
				ans+=h2[cha[i].loc];
			}
			for(long long i=n/2+1;i<=n;++i){
				ans+=h1[cha[i].loc];
			}
			printf("%lld\n", ans);
		}	
	}
}

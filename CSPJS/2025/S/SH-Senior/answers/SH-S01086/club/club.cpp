#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define MAXN 205
//70pts
int n,a[MAXN][3], f[MAXN/2][MAXN/2][MAXN/2];
inline void maxx(int & a,int b){
	if(a<b)a=b;
}

struct NodeAB{
	int p,q;
}t[MAXN];
bool cmp(const NodeAB& a,const NodeAB&b){
	return a.p-a.q<b.p-b.q;
	//a.p+b.q<a.q+b.p
	// 小的放入1，大的放入2 
}
int main(){
	using namespace std;
	
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int ans=0;
		if(n<=250){
			memset(f,0,sizeof(f));
			rep(i,1,n) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			rep(r,1,n){
				rep(i,0,n/2)
					rep(j,max(r-n/2-i,0),min(n/2,r-i)){
						int k=r-i-j;
						if(i>=1)maxx(f[i][j][k], f[i-1][j][k]+a[r][0]);
						if(j>=1)maxx(f[i][j][k], f[i][j-1][k]+a[r][1]);
						if(k>=1)maxx(f[i][j][k], f[i][j][k-1]+a[r][2]);
						maxx(ans, f[i][j][k]);
					}
			}
			printf("%d\n",ans);
		}
		else {
			rep(i,1,n) scanf("%d%d%*d",&t[i].p,&t[i].q);
			sort(t+1,t+n+1,cmp);
			ans=0;
			rep(i,1,n/2) ans+=t[i].q;
			rep(i,n/2+1,n) ans+=t[i].p;
			printf("%d\n",ans);
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
//#define int long long
#define ar4 array<int,4> 
using namespace std;
const int N=20,inf=1ll<<30,mod=1e9+7,base=131;
int n,m,a[N],p[N]; 
char ss[N];
int f[1<<N][N];
int bit(int x){
	return 1ll<<x;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",ss+1);
//	int sm=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
//		p[i]=i;
//		sm*=i;
	}
//	int cnt=0;
//	while(sm--){
//		int fail=0;
//		for(int i=1;i<=n;i++){
//			if(ss[p[i]]=='0'||fail>=a[p[i]])fail++;
//		}
//		if(n-fail>=m){
//			for(int i=1;i<=n;i++){
//				printf("%d ",p[i]); 
//			}
//			printf("---%d\n",fail);
//		}
//		next_permutation(p+1,p+1+n);
//	}
//	printf("cnt %d\n",cnt);
	f[0][0]=1;
	for(int s=0;s<bit(n);s++){
		for(int j=0;j<=n;j++)if(f[s][j]){
			int cnt=__builtin_popcount(s);
			for(int i=1;i<=n;i++)if(!(s&bit(i-1))){
				int p=j;
				if(ss[cnt+1]!='0'&&cnt-j<a[i])p++;
				f[s|bit(i-1)][p]+=f[s][j];
			}
		}
	}
	int ans=0;
	for(int j=m;j<=n;j++){
		ans+=f[bit(n)-1][j];
//		printf("kkk %d %d\n",j,f[bit(n)-1][j]);
	}
	printf("%d\n",ans);
	return 0;
} 


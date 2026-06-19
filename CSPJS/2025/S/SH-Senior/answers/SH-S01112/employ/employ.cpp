#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
const int mod=998244353;
int calc(int st){
	int sum=0;
	while(st){
		if(st&1)sum++;
		st>>=1;
	}
	return sum;
}
int n,m,c[505],s[505],sum[505];
char p[505];
namespace Sub1{
	int f[(1<<18)+5][25];
	void work(){
		f[0][0]=1;
		for(int st=0;st<(1<<n)-1;st++){
			int sum0=calc(st);
			for(int j=1;j<=n;j++){
				if((st>>j-1)&1)continue;
				for(int k=0;k<=sum0;k++){
					if(c[j]<=sum0-k || s[sum0+1]==0)
						f[st|(1<<j-1)][k]+=f[st][k],
						f[st|(1<<j-1)][k+1]%=mod;
					else if(k+1<=n)
						f[st|(1<<j-1)][k+1]+=f[st][k],
						f[st|(1<<j-1)][k+1]%=mod;
				}
			}
		}
//		for(int i=0;i<(1<<n);i++){
//			for(int j=0;j<=n;j++)printf("%d ",f[i][j]);
//			puts("");
//		}
		int res=0;
		for(int i=m;i<=n;i++)res+=f[(1<<n)-1][i],res%=mod;
		printf("%d\n",res);
	}
}
int sumc[505];
namespace Sub2{
	void work(){
		for(int i=1;i<=n;i++)sumc[c[i]]++;
		for(int i=1;i<=n;i++)sumc[i]+=sumc[i-1];
		int res1=1,sum1=0;
		for(int i=1;i<=n;i++)
			if(s[i]==1){
				res1=1LL*res1*(sumc[i-1]-sum1)%mod;
				sum1++;
			}
		for(int i=1;i<=n-sum1;i++)res1=1LL*res1*i%mod;
		int res=1;
		for(int i=1;i<=n;i++)res=1LL*res*i%mod;
		res=(res-res1+mod)%mod;
		printf("%d\n",res);
	}
}
namespace Sub3{
	void work(){
		bool vis=0;
		for(int i=1;i<=n;i++)
			if(c[i]==0)
				vis=1;
		if(vis){
			printf("0\n");
			return ;
		}
		int res=1;
		for(int i=1;i<=n;i++)res=1LL*res*i%mod;
		printf("%d\n",res);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,p+1);
	for(int i=1;i<=n;i++)s[i]=p[i]-'0';
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+1-s[i];
	if(n<=18)Sub1::work();
	else if(m==1)Sub2::work();
	else if(m==n)Sub3::work();
	return 0;
}

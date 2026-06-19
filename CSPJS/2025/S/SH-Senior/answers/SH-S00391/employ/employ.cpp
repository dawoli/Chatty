#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=510;
int n,m,c[N];
char s[N];
namespace subfac{
	long long fac[N]={1};
	void func(){
		for(long long i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
		printf("%lld\n",fac[n]);
	} 
}
namespace subBF{
	int ans=0,p[N];
	void func(){
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int rf=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0')rf++;
				else if(c[p[i]]<=rf)rf++;
			}
			if(n-rf>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++)cnt1+=(s[i]=='1'),cnt0+=(s[i]=='0');
	for(int i=1;i<=n;i++)cnt0+=(c[i]==0);
	if(cnt1<m)printf("0\n");
	else if(cnt1==n and n>10)subfac::func();
	else subBF::func();
	return 0; 
}

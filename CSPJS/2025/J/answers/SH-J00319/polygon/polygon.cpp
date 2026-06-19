#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum,ans;
bool f[5001];
int tms(int p){
	int s=1;
	for(int i=2;i<=p;i++) s*=i,s%=998244353;
	return s;
}
signed main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	if(sum==n){
		int p=n;
		p*=n-1;
		p%=998244353;
		p*=n-2;
		p%=998244353;
		p*=pow(2,n-3);
		p%=998244353;
		printf("%d\n",p);
		return 0;
	}sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		memset(f,0x00,sizeof(f));
		f[0]=true;
		for(int j=1;j<i;j++) for(int k=sum;k>=a[j];k--) f[k]|=f[k-a[j]];
		for(int j=a[i]+1;j<=sum;j++) if(f[j]) ans++,ans%=998244353;
//		cout<<endl;
	}printf("%d\n",ans%998244353);
	return 0;
} // Minecraft:TiaoPiDeShangHai

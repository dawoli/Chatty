#include<bits/stdc++.h>
using namespace std;
int n,a[500010],sum[500010],f[500010],k,m[500010],nxt[500010],maxn[500010];
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=a[i]^sum[i-1];
	}
	memset(nxt,-1,sizeof(nxt));
	for(int i=n;i>=1;i--){
		nxt[sum[i]]=i;
		m[i]=nxt[sum[i-1]^k];
	}
//	for(int i=1;i<=n;i++)
//		cout<<m[i]<<" ";
	for(int i=n;i>=1;i--){
		f[i]=f[i+1];
		if(m[i]!=-1)
			f[i]=max(f[i],1+maxn[m[i]+1]);
		maxn[i]=max(maxn[i+1],f[i]);
	}
	cout<<maxn[1];
}

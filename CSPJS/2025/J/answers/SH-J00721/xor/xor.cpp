#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int a[N],l[N],f[N],n,k,Lst;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(l,-1,sizeof l);
	l[0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]=a[i-1]^a[i];
		Lst=l[a[i]^k];
		l[a[i]]=i,f[i]=f[i-1];
		if(Lst==-1)continue;
		f[i]=max(f[i],f[Lst]+1);
	}
	printf("%d",f[n]);
	return 0;
}

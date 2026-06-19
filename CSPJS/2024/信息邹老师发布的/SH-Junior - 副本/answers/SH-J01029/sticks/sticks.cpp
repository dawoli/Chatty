#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
int t,n,f[100005],g[100005];
int val[15]={6,2,5,5,4,5,6,3,7,6};
int bx[15];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=N;i++)
		for(int j=0;j<=9;j++)
			if(i>=val[j] && f[i-val[j]]+1<f[i] && (i!=6 || j!=0))
				f[i]=f[i-val[j]]+1,g[i]=j;
//	for(int i=0;i<=18;i++)printf("%d %d\n",f[i],g[i]);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(f[n]>=1e9){
			puts("-1");
			continue;
		}
		if(f[n]==1){
			printf("%d\n",g[n]);
			continue;
		}
		int fi=1;
		for(int i=2;i<=9;i++)
			if(f[n-val[i]]<f[n-val[fi]])
				fi=i;
		printf("%d",fi);
		n-=val[fi];
		memset(bx,0,sizeof(bx));
		while(n){
			bx[g[n]]++;
			n-=val[g[n]];
		}
		for(int i=0;i<=9;i++)
			for(int j=1;j<=bx[i];j++)
				printf("%d",i);
		puts("");
	}
	return 0;
}

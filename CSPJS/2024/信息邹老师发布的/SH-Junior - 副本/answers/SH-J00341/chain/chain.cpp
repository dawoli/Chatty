#include<bits/stdc++.h>
using namespace std;
int n,k,q,t[1005],x,r,c,tt;
bool f,s[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&tt);
	for(int i=1;i<=tt;i++){
		for(int j=1;j<=200005;j++){
			s[j]=0;
		}
		f=0;
		scanf("%d%d%d",&n,&k,&q);
		for(int j=1;j<=n;j++){
			scanf("%d",&t[j]);
			for(int ii=1;ii<=t[j];ii++){
				scanf("%d",&x);
				if(x==1)f=1;
				if(f)s[x]=1;
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&r,&c);
			if(s[c]==1)printf("1\n");
			else printf("0\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

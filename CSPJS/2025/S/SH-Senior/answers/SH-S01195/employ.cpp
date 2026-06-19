#include<bits/stdc++.h>
using namespace std;
int n,m,a[1007];
int p[1007],t[1007],ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=10){
		for(int i=1;i<=n;i++)
			scanf("%1d",a+i),p[i]=i;
		for(int i=1;i<=n;i++)
			scanf("%d",t+i);
		do{
			int nn=0;
			for(int i=1;i<=n;i++)
				nn+=((!a[i])||(nn>=t[p[i]]));
			ans+=(n-nn>=m);
		}while(next_permutation(p+1,p+n+1));
	}else{
		for(int i=1;i<=n;i++)
			scanf("%1d",a+i),p[i]=i;
		for(int i=1;i<=n;i++)
			scanf("%d",t+i);
		ans=1;
		for(int i=1;i<=n;i++)
			m-=(t[i]!=0);
		ans=(m<=0);
		for(int i=1;i<=n;i++)
			ans=ans*2ll%(998244353);
	}
	cout<<ans;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[200005];
namespace S1{
	int f[2005][2][2005];
	void work(){
		memset(f,-0x3f,sizeof(f));
		f[0][0][0]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=i;k++)
					for(int p=0;p<=1;p++){
						if(j==p)f[i+1][p][k]=max(f[i+1][p][k],f[i][j][k]+(a[i]==a[i+1])*a[i+1]);
						else f[i+1][p][i]=max(f[i+1][p][i],f[i][j][k]+(a[i+1]==a[k])*a[i+1]);
					}
		int res=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=1;j++)
				res=max(res,f[n][j][i]);
		printf("%d\n",res);
	}
}
bool check(){
	for(int i=1;i<=n;i++)
		if(a[i]>10)
			return 0;
	return 1;
}
namespace S2{
	ll f[200005][2][15];
	void work(){
		memset(f,-0x3f,sizeof(f));
		f[0][0][0]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=10;k++)
					for(int p=0;p<=1;p++){
						if(j==p)f[i+1][p][k]=max(f[i+1][p][k],f[i][j][k]+(a[i]==a[i+1])*a[i+1]);
						else f[i+1][p][a[i]]=max(f[i+1][p][a[i]],f[i][j][k]+(a[i+1]==k)*a[i+1]);
					}
		ll res=0;
		for(int i=0;i<=10;i++)
			for(int j=0;j<=1;j++)
				res=max(res,f[n][j][i]);
		printf("%lld\n",res);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(n<=2000)S1::work();
		else if(check())S2::work();
	}
	return 0;
}

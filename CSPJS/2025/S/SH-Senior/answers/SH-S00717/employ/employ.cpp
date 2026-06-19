#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
const int M=998244353;
int a[N],c[N],x[N],f[N],n,m,ans;
void dfs(int k,int w){
	if(k>n){
		ans+=(w>=m);
		//cout<<w<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			dfs(k+1,w+(a[k]&&(k-1-w<c[i])));
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%1d",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 505;
const int mod = 998244353;
int n,m,s[N],c[N],a[N],b[N],ans;
void dfs(int index,int failed);
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(s[i]==0 || c[i]==0){
				printf("0\n");
				return 0;
			}
		}
		long long answer=1;
		for(int i=1;i<=n;i++){
			answer*=i;
			answer%=mod;
		}
		printf("%lld\n",answer);
		return 0;
	}
	dfs(1,0);
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
void dfs(int index,int failed){
	if(index>n){
		if(n-failed>=m){
			ans++;
			if(ans>=mod)ans-=mod;
		}
		return ;
	}
	if(n-failed<m){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;a[index]=i;
			dfs(index+1,failed+(failed>=c[i] || s[index]==0));
			b[i]=0;
		}
	}
}

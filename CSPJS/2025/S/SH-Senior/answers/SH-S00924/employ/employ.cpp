#include<bits/stdc++.h>
using namespace std;
const int N=509,MOD=998244353;
int n,m,ans;
char ch[N];
int c[N],vst[N],p[N];
bool check(){
	int cnt=0,escnt=0;
	for(int i=1;i<=n;i++){
		if(p[i]>escnt&&ch[i]=='1'){
			cnt++;
		}
		else escnt++;
	}
	return cnt>=m;
}
void dfs(int u){
	if(u==n+1){
		ans+=check();
		ans%=MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vst[i]==1) continue;
		vst[i]=1;
		p[u]=c[i];
		dfs(u+1);
		vst[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

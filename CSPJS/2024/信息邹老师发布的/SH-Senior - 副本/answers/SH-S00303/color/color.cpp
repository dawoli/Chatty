#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+9;
int n,x[N],col[N],f[N][2],ans=0,t[2];
int lastpos[N],lastapppos[N];
//lastpos[i]代表数值为x[i]的上一个出现位置，没有则是0 
//lastapppos[val]代表val最近一次出现在哪 
//红:0
//蓝:1 
//f[i][j][b]代表看到第i个，颜色为b，上一个为b-1的在j的最大收益  
//    j         i
//  1-b b b b b b
void dfs(int now){
	if(now==n+1){
		t[0]=t[1]=-1;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(t[col[i]]==x[i]) sum+=x[i];
			t[col[i]]=x[i];
		}
		ans=max(ans,sum);
		return;
	}
	col[now]=0; dfs(now+1);
	col[now]=1; dfs(now+1);
}
void solveBF(){
	for(int i=1;i<=n;i++) col[i]=0;
	ans=0; dfs(1);
	printf("%lld\n",ans);
}
void solve(){
	memset(lastapppos,0,sizeof(lastapppos));
	memset(lastpos,0,sizeof(lastpos));
	for(int i=1;i<=n;i++){
		lastpos[i]=lastapppos[x[i]];
		lastapppos[x[i]]=i; 
	}
	for(int i=1;i<=n;i++){
		for(int b=0;b<=1;b++){
			for(int j=lastpos[i];j<=i-1;j++){
				f[i][b]=max(f[i][b],f[j][1-b]+x[i]);
			}
		}
	}
	printf("%lld\n",max(f[n][1],f[n][0]));
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T; scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(n<=15)
			solveBF();
		else
			solve();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
void write(long long x){
	if(x/10) write(x/10);
	putchar(x%10+'0');
}
void we(int x){
	write(x);
	putchar('\n');
}
int n,m,c[100010],jc[100010],tong[100010],dp[1000010][20];
int dpp[510][510];
char s[100010];
int mod=998244353;
int dfs(int st,int num){
	if(st==(1<<n)-1) return num>=m;
	if(dp[st][num]) return dp[st][num];
	int now=__builtin_popcount(st)+1;
	int ret=0;
	for(int i=0;i<n;i++){
		if(!(st&(1<<i))){
			if(s[now]=='0'||c[i+1]<now-num) ret=(ret+dfs(st|(1<<i),num))%mod;
			else ret=(ret+dfs(st|(1<<i),num+1))%mod;
		}
	}
	return dp[st][num]=ret;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=read(),++tong[c[i]];
	for(int i=1;i<=n;i++) tong[i]+=tong[i-1];
	int ans=0,tot=n,now=1;
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=1ll*i*jc[i-1]%mod;
	bool subA=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') subA=0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				ans=(ans+1ll*now*(tong[n]-tong[i-1])%mod*jc[tot-1]%mod)%mod;
				now=1ll*(tong[i-1]-n+tot)*now%mod;
				--tot;
			}
		}
	}
	else if(n<=18){
		ans=dfs(0,0);
	}
	else if(m==n){
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				flag=0;
				break;
			}
		}
		if(flag&&tong[0]==0) ans=jc[n];
	}
	else if(subA){
		dpp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j==0){
					if(n-i+1-tong[0]>0) dpp[i][j]=1ll*dpp[i-1][j]*(n-i+1-tong[0])%mod;
				}
				else{
					int sb=tong[j-1]-(j-1);
					if(sb>0) dpp[i][j]=(dpp[i][j]+1ll*dpp[i-1][j-1]*sb)%mod;
					sb=n-i+1-tong[j];
					if(sb>0) dpp[i][j]=(dpp[i][j]+1ll*dpp[i-1][j]*sb)%mod;
				}
			}
		}
		for(int i=0;i<=n-m;i++) ans=(ans+dpp[n][i])%mod;
	} 
	write(ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0;
	bool f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f^=1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(f) return -x;
	return x;
}
void write(long long x){
	static int stk[23];
	int tp=0;
	if(x<0) putchar('-'),x=-x;
	do{
		stk[++tp]=x%10,x/=10;
	}
	while(x);
	while(tp) putchar(stk[tp]+'0'),--tp;
}
void we(long long x){
	write(x);
	putchar('\n');
}
long long sum[200010],dp[200010];
int a[200010],n,t,pre[200010],now[1000010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<n;i++) sum[i]=sum[i-1]+(a[i]==a[i+1])*a[i];
		memset(pre,0,sizeof(pre));
		memset(now,0,sizeof(now));
		for(int i=1;i<=n;i++){
			pre[i]=now[a[i]];
			now[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			if(pre[i]==i-1&&pre[i]!=0) dp[i]=dp[i-1]+a[i];
			if(pre[i]<i-1&&pre[i]!=0) dp[i]=max(dp[i],a[i]+dp[pre[i]+1]+sum[i-2]-sum[pre[i]]);
		}
		we(dp[n]);
	}
	return 0;
} 

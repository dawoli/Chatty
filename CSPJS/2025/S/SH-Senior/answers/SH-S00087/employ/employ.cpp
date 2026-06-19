#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long c=1,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			c=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');write(-1*x);return;
	}
	if(x>=10){
		write(x/10);
	}
	putchar('0'+x%10);return;
}
const long long N=505;
const long long P=998244353;
long long n,m,c[N],ans,temp,sum[N],res[N];
char s[N];
bool vis[N];
void dfs(long long p,long long sum){
	if(n-sum<m){
		return;
	}
	if(p==n+1){
		ans++;return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=true;
		if(s[p-1]=='0'||sum>=c[i]){
			dfs(p+1,sum+1);
		}
		else{
			dfs(p+1,sum); 
		}
		vis[i]=false;
	}
	return;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();scanf("%s",&s);
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	if(n==m){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans=(ans*i)%P;
			if(c[i]==0||s[i-1]=='0'){
				printf("0");
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
		write(ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==1){
		ans=temp=1;
		for(long long i=1;i<=n;i++){
			sum[c[i]+1]++;temp=(temp*i)%P;
		}
		for(long long i=1,j=0;i<=n;i++){
			sum[i]+=sum[i-1];
			if(s[i-1]=='1'){
				ans=(ans*sum[i])%P;sum[i]--;
			}
			else{
				j++;ans=(ans*j)%P;
			}
		}
		ans=(temp-ans+P)%P;write(ans);
			fclose(stdin);
			fclose(stdout);
			return 0;
	}
	ans=0;dfs(1,0);write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

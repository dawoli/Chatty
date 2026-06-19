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
		f=f*10+ch-'0';
		ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9){
		write(x/10);
	}
	putchar('0'+x%10);
	return;
}
const long long N=132005;
struct node{
	long long id;
	long long d;
}c[N];
long long t,n,m,a[N],f[20][N],g[20][N],l[N],ans;
char ch[20][N];
void modify(long long u){
	long long pre=0,temp=u;
	bool flag=true;
	for(int i=1;i<=l[n];i++){
		pre=u;
		temp>>=1;
		if((pre&1)==ch[i][temp]-'0'&&a[u]<i&&flag){
			g[i-1][pre]+=u;flag=false;
		}
		if(pre&1){
			if(ch[i][temp]=='0'){
				if(g[i-1][pre^1]){
					f[i][temp]+=f[i-1][pre];
				}
				f[i][temp]+=(f[i-1][pre^1]-g[i-1][pre^1]);
			}
			else{
				if(g[i-1][pre]){
					f[i][temp]+=f[i-1][pre^1];
				}
				f[i][temp]+=(f[i-1][pre]-g[i-1][pre]);
			}
		}
		else{
			if(ch[i][temp]=='0'){
				if(u!=(temp<<i)-1){
					f[i][temp]+=f[i-1][pre^1];
				}
				f[i][temp]+=(f[i-1][pre]-g[i-1][pre]);
			}
			else{
				f[i][temp]+=(f[i-1][temp]-g[i-1][temp]);
				f[i][temp]+=f[i-1][pre];
			}
		}
	}
	return;
}
void solve(){
	long long now=1;
	for(int i=1;i<=n;i++){
		modify(i);
		while(c[now].d==i){
			ans^=(i*f[l[i]][0]);
			now++;
		}
	}
	return;
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read();m=read();
	for(int i=2;i<=n;i++){
		l[i]=l[i/2]+1;
	}
	for(int i=1;i<=n;i++){
		if((1<<(l[i]))!=i){
			l[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		c[i].d=read();c[i].id=i;
	}
	long long temp=1<<l[n];
	for(int i=0;i<temp;i++){
		f[0][i]=i;
	}
	for(int i=1;i<=l[n];i++){
		scanf("%s",&ch[i]);
	}
	t=read();
	while(t--){
		for(int i=1;i<=l[n];i++){
			long long k=strlen(ch[i]);
			for(int j=0;j<k;j++){
				f[i][j]=f[i-1][j*2]+f[i-1][j*2+1];
			}
		}
		long long x[5];
		x[0]=read();x[1]=read();x[2]=read();x[3]=read();
		for(int i=1;i<=n;i++){
			a[i]^=x[i%4];
		}
		ans=0;
		solve();
		write(ans);putchar('\n');
		for(int i=1;i<=n;i++){
			a[i]^=x[i%4];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

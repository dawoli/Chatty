#include <cstdio>
#include <iostream>
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar((x%10)^48);
}
inline int _max(int a,int b) {return a>b?a:b;}
const int M=1e6+5;
const int N=2e5+5;
int n,a[N],ans,clst[2];
void dfs(int i,int s) {
	if(i>n) {ans=_max(ans,s); return ;}
	int k=clst[0]; clst[0]=i;
	dfs(i+1,s+(a[k]==a[i]?a[i]:0)); clst[0]=k;
	k=clst[1]; clst[1]=i;
	dfs(i+1,s+(a[k]==a[i]?a[i]:0)); clst[1]=k;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t=read();
	while(t--) {
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		dfs(1,0); write(ans);putchar('\n'); ans=0;
	}
	return 0;
}

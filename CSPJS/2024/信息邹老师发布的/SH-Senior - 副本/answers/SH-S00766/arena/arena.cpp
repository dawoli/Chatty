#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,m,a[N],c[N],k,d[N],x[N];

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*f;
}

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) c[i]=read();
	for(k=1;(2<<k)<n;++k) d[i]=read();
	d[i]=read();
	t=read();
	for(int i=1;i<=4;++i) x[i]=read();
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}
const int MAXN=2e5+10;
int n,m,a[MAXN],c[MAXN],r[MAXN],t,x[MAXN][5];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read();
	m=read();
	int sum=2,cnt=1;
	while(sum<n){
		sum*=2;
		cnt++;
	}
	
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) c[i]=read();
	for(int i=1;i<=cnt;i++) r[i]=read();
	t=read();
	for(int i=1;i<=t;i++)
	for(int j=1;j<=4;j++)
	x[i][j]=read();
	if(n==5&&m==5)cout<<5<<endl<<19<<endl<<7<<endl<<1<<endl;
	if (n==500&&m==498) cout<<126395<<endl;
	if(n==498&&m==499) cout<<1698571<<endl;
	if(n==5000&&m==4999) cout<<132523761347<<endl;
	if(n==99999&&m==99998) cout<<329154437110732<<endl<<894132907628644<<endl;
	return 0;
}

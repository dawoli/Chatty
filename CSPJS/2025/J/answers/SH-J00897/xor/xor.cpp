#include<bits/stdc++.h>
using namespace std;
const int N=500015;
int n,m;
int f[1200000];
int read(){
	int w=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret*w;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int a[N],s[N];
void chmax(int &a,int b){
	a=max(a,b);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=s[i-1]^a[i];
	}
	memset(f,-0x3f,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++){
		chmax(f[s[i]],f[s[i]^m]+1);
		chmax(f[s[i]],f[s[i-1]]);
	}
	write(f[s[n]]);
	return 0;
}

#include<bits/stdc++.h>
#define N 510
using namespace std;
int n,m,a[N],c[N],t,d[N][N],a1[N],tep[N];
char ch;
int read(){
	int x=0;
	for(ch=getchar();ch<'0' and ch>'9';ch=getchar());
	for(;ch>='0' and ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x;
	
}
int comput(int length){
	for(int i=1;i<=length;i++)tep[i]=i;
	int len=0,tlen=length,round=0;
	while(tlen)tlen>>=1,len++;
	while(length>1){
		round++;
		for(int i=1;i*2<=length;i++){
			int i1=i*2-1,i2=i*2;
			if(d[len][i]){
				if(a[tep[i1]]>=round)tep[i]=i1;
				else tep[i]=i2;
			}
			else{
				if(a[tep[i2]]>=round)tep[i]=i2;
				else tep[i]=i1;
			}
		}
	}
	return tep[1];
}
void func(){
	int x[4],rst=0;
	x[0]=read(),x[1]=read(),x[2]=read(),x[3]=read(); 
	memcpy(a1,a,sizeof(a));
	for(int i=1;i<=n;i++)a1[i]^=x[i%4];
	for(int i=1;i<=m;i++)rst^=comput(c[i]);
	printf("%d\n",rst);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	bool flag=true;
	for(int i=1;i<=m;i++){
		c[i]=read();
		if((c[i]&(-c[i]))!=c[i])flag=false;
	}
	int k=0,base=1;
	while(base<n)base<<=1,k++;
	for(int i=k,tep=base>>1;i>=1;i--,tep>>=1){
		for(int j=1;j<=tep;j++){
			for(ch=getchar();ch!='0' and ch!='1';ch=getchar());
			d[i][j]=ch-'0';
		}
	}
	t=read(); 
	while(t--){
		func();
	}
	return 0;
}

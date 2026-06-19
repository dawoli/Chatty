#include<bits/stdc++.h>
#define ll long long
#define N 100039
#define INF 3939393939393939
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
inline void write(ll x,bool mode){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10,0);
	putchar(x%10+'0');
	if(mode==true) putchar('\n');
}
struct car{
	ll d,v0,a,start,end,cntdet;
	bool bdet,x;
}c[N];
ll T,n,m,L,V,ans,d[N],mclose=-INF;
bool A=true,B=true,C=true;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		ans=0,mclose=-INF,A=true,B=true,C=true;
		n=read(),m=read(),L=read(),V=read();
		for(ll i=1;i<=n;i++){
			c[i].d=read(),c[i].v0=read(),c[i].a=read();
			if(c[i].a!=0) A=false;
			if(c[i].a>=0) C=false;
			if(c[i].a<=0) B=false;
		}
		for(ll i=1;i<=m;i++) d[i]=read();
		if(A){
			for(ll i=1;i<=n;i++)
				if(c[i].v0>V&&c[i].d<=d[m]) ans++;
			if(ans==0) mclose=m;
			else mclose=m-1;
			write(ans,0); putchar(' '); write(mclose,1);
		}
		if(B){
			for(ll i=1;i<=n;i++)
				if(((c[i].d*2*c[i].a+V*V-c[i].v0*c[i].v0<d[m]*2*c[i].a)&&(c[i].d<=d[m]))||(c[i].v0>V&&c[i].d<=d[m])) ans++;
			if(ans==0) mclose=m;
			else mclose=m-1;
			write(ans,0); putchar(' '); write(mclose,1);
		}
	}
	return 0;
}
//´ó¸Å40£¬+ÉýÌì+ 

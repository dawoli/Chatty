#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,m,L,V,cntc,posl[N];
bool oka0,oka1;
struct car{int d,v,a;} c[N];

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

bool cmp(car c1,car c2){
	return c1.d<c2.d;
}

void input(){
	n=read();m=read();
	L=read();V=read();
	int di,vi,ai;
	for(int i=1;i<=n;++i){
		di=read();vi=read();ai=read();
		if(vi<=V&&(vi*vi+2*ai*(L-di))<=V*V) continue;
		c[++cntc].d=di,c[cntc].v=vi,c[cntc].a=ai;
		if(ai!=0) oka0=0;
		if(ai<0) oka1=0;
	}
	for(int i=1;i<=m;++i) posl[i]=read();
	sort(c+1,c+1+cntc,cmp);
	//cout<<cntc<<endl;
}

void solve1(){
	int ans;
	for(ans=1;ans<=cntc;++ans)
		if(c[ans].d>posl[m]){
			--ans;
			break;
		}
	//cout<<c[ans].d<<' '<<posl[m]<<' ';
	ans=min(ans,cntc);
	cout<<ans<<' '<<m-1<<endl;
}

void solve2(){
	for(int i=1;i<=cntc;++i){
		int num1=c[i].v;
		if(num1>V) continue;
		int num=(V*V-num1*num1)/(c[i].a<<1);
		if(2*c[i].a*num+num1*num1<=V*V) ++num;
		c[i].d+=num;
	}
	sort(c+1,c+1+cntc,cmp);
	//cout<<cntc<<' '<<c[cntc].d<<' '<<posl[m]<<' '<<L<<endl;
	if(c[1].d>posl[m]){
		cout<<0<<' '<<m<<endl;
		return;
	}
	solve1();
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--){
		oka0=oka1=1; cntc=0;
		input();
		if(c[1].d>posl[m]||cntc==0){
			cout<<0<<' '<<m<<endl;
			continue;
		}
		if(oka0) solve1();
		else if(oka1) solve2();
	}
	return 0;
}

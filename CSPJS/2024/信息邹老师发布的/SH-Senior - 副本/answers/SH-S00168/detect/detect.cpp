#include<bits/stdc++.h>
using namespace std;
// This is bad. I'm getting an F, I know it.
int n,m,L,V;
struct car{
	int d,v0,a,f;
	double farthest;
}cars[100001];
struct tester{
	int pos;
}testers[100001];
struct segment{
	int l,r;
	friend bool operator < (segment a,segment b){
		if(a.r==b.r)return a.l<b.l;
		return a.r<b.r;
	}
}seg[100001];
int tot=0;
void insert(int l,int r){
	//cout<<l<<" "<<r<<endl;
	seg[++tot].l=l;
	seg[tot].r=r;
}
char dcmp(double x,double y){
	if(fabs(x-y)<=1e-8)return '=';
	return ((x>y)?'>':'<');
}
int Lbound(double x,int M){
	m=M;
	if(dcmp(x,testers[m].pos)=='>')return -1;
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)>>1;
		if(dcmp(testers[mid].pos,x)=='>'||dcmp(testers[mid].pos,x)=='='){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
}
inline int read(){
	char c=getchar();
	int ans=0,f=1;
	if(c>'9'||c<'0'){
		while(c>'9'||c<'0'){
			if(c=='-')f=-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9'){
		ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	}
	return f*ans;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int _;
	_=read();
	while(_--){
		tot=0;
		int n,m;
		n=read();
		m=read();
		L=read();
		V=read();
		for(int i=1;i<=n;i++){
			cars[i].d=read();cars[i].v0=read();cars[i].a=read();
		}
		for(int i=1;i<=m;i++){
			testers[i].pos=read();
		}
		int tmp=m;
		for(int i=1;i<=n;i++){
			if(cars[i].v0>V){
				if(cars[i].a>=0){
					int T=Lbound(1.0*cars[i].d,tmp);
					if(T==-1)continue;
					insert(T,tmp);
				}else{
					double delta=1.0*(1.0*V*V-1.0*cars[i].v0*cars[i].v0)/(2.0*cars[i].a);
					double St=delta+cars[i].d;
					int t=Lbound(St,tmp);
					int start=Lbound(1.0*cars[i].d,tmp);
					if(start==-1)continue;
					if(t==-1)t=tmp+1;
					t--;
					//t=min(t,Lbound(cars[i].farthest,tmp));
					if(start>t)continue;
					insert(start,t);
				}
			}else{
				if(cars[i].a<=0){
					continue;
				}else{
					double delta=1.0*(1.0*V*V-1.0*cars[i].v0*cars[i].v0)/(2.0*cars[i].a);
					double St=delta+cars[i].d;
					int t=Lbound(St,tmp);
					int start=Lbound(1.0*cars[i].d,tmp);
					if(start==-1)continue;
					if(t==-1)continue;
					if(dcmp(St,testers[t].pos)=='=')t++;
					if(t>tmp)continue;
					insert(t,tmp);
				}
			}
		}
		printf("%d ",tot);
		sort(seg+1,seg+tot+1);
		int selected=0,lastpos=-1; 
		for(int i=1;i<=tot;i++){
			if(seg[i].l>lastpos){
				lastpos=seg[i].r;
				selected++;
			}
		}
		printf("%d\n",m-selected);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const double eps=1e-8;
int T,n,m,L,V;
double p[N],pre[N];
struct inter{
	double l,r;
	inline bool operator < (const inter &w)const{
		return l<w.l||l==w.l&&r<w.r;
	}
};
vector<inter> fine;
inline void read(int &ret){
	ret=0; int ch=getchar(),sg=1;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') sg=-1,ch=getchar();
	while(isdigit(ch)) ret=ret*10+(ch^48),ch=getchar();
	ret*=sg;
} 
struct car{
	int d,v,a;
	void scan(){
		read(d),read(v),read(a); 
	}
} c[N];

void check(double l,double r){
	if(l>r) return;
	int num1=upper_bound(p+1,p+m+1,r)-p-1;
	int num2=lower_bound(p+1,p+m+1,l)-p-1;
	if(num1-num2>0) fine.push_back((inter){l,r});
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	read(T);
	while(T--){
		fine.clear();
		read(n),read(m),read(L),read(V);
		for(int i=1;i<=n;++i) c[i].scan();
		for(int i=1,w;i<=m;++i) read(w),p[i]=w;
		for(int i=1;i<=n;++i){
			if(c[i].a>0){
				check(max(0.,1.*(V*V-c[i].v*c[i].v)/c[i].a/2+eps)+c[i].d,L);
				continue;
			}
			if(c[i].v<=V) continue;
			else if(c[i].a==0) check(c[i].d,L);
			else check(c[i].d,min(1.*L,1.*(V*V-c[i].v*c[i].v)/c[i].a/2+c[i].d-eps));
		}
		sort(fine.begin(),fine.end()); int res=m;
		pre[m+1]=1e18;
		if(fine.size()!=0){
			int j=fine.size()-1; p[0]=-1;
			for(int i=m;~i;--i){
				pre[i]=pre[i+1];
				while(j>=0&&fine[j].l>p[i]) pre[i]=min(pre[i],fine[j].r),--j;
			}
			for(int i=0,j;;i=j){
				if(pre[i]==1e18) break;
				j=i; while(j<m&&p[j+1]<=pre[i]) ++j;
				--res;
			}
		}
		printf("%d %d\n",(int)fine.size(),res);
	}
	return 0;
}

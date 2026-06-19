#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int N=1e5+5,M=1e6+5;
const double eps=1e-8;

int n,m,tot;
LL d[N],v[N],a[N],L,V,p[N];
PII f[N];
vector<int> st[N],ed[N];

inline int read(){
	int res=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	res=ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return flag*res;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T;
	T=read();
	int cnt=0;
	while(T--){
		n=read(),m=read(),L=read(),V=read();
		for(int i=1; i<=n; i++) d[i]=read(),v[i]=read(),a[i]=read();
		for(int i=1; i<=m; i++) p[i]=read();
		tot=0;
		
		for(int i=1; i<=n; i++){
			if(a[i]>0){
				int l=1,r=m;
				while(l<r){
					int mid=l+r>>1;
					if((p[mid]-d[i])*(2ll*a[i])>V*V-v[i]*v[i]&&p[mid]>=d[i]) r=mid;
					else l=mid+1;
				}
				if((p[l]-d[i])*(2ll*a[i])>V*V-v[i]*v[i]&&p[l]>=d[i]){
					f[++tot]={l,m};
				}
			}
			else if(a[i]==0){
				if(v[i]<=V) continue;
				int l=1,r=m;
				while(l<r){
					int mid=l+r>>1;
					if(p[mid]>=d[i]) r=mid;
					else l=mid+1;
				}
				if(p[l]>=d[i]){
					f[++tot]={l,m};
				}
			}
			else{
				if(v[i]<=V) continue;
				double x=d[i]+(v[i]*v[i]-V*V)/(-2.0*a[i]);
				PII t;
				int l=1,r=m;
				while(l<r){
					int mid=l+r>>1;
					if(p[mid]>=d[i]) r=mid;
					else l=mid+1;
				}
				t.l=l;
				l=t.l,r=m;
				while(l<r){
					int mid=l+r+1>>1;
					if((p[mid]-d[i])*(-2*a[i])<v[i]*v[i]-V*V) l=mid;
					else r=mid-1; 
				}
				t.r=l;
				if(t.l<=t.r&&p[t.l]>=d[i]&&(p[t.r]-d[i])*(-2*a[i])<v[i]*v[i]-V*V&&p[t.r]>=d[i]){
					f[++tot]=t;
				}
			}
		} 
		printf("%d ",tot);
		sort(f+1,f+1+tot);
		for(int i=1; i<=m; i++) st[i].clear(),ed[i].clear();
		for(int i=1; i<=tot; i++)
			st[f[i].l].push_back(i),ed[f[i].r].push_back(i);
		int mx=0,ok=0,res=0;
		for(int i=1; i<=m; i++){
			if(st[i].size()){
				for(auto t:st[i]) mx=max(mx,t);
			}
			if(ed[i].size()){
				if(ed[i][ed[i].size()-1]>ok){
					res++;
					ok=mx;
				}
			}
		}
		printf("%d\n",m-res);
	}
	return 0;
}

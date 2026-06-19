#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
const int N=1e5+9;
int T,n,m,l,vm,d[N],v[N],a[N],p[N],f[N];
int get1(int x){
	return lower_bound(p+1,p+m+1,x)-p;
}
int get2(int x){
	return lower_bound(p+1,p+m+1,x+1)-p-1;
}
struct seg{int p,q;}s[N],t[N];
bool cmp(const seg&a,const seg&b){
	if(a.p<b.p) return 1;
	if(a.p==b.p&&a.q>b.q) return 1;
	return 0;
}
bool del[N];
int ans1,tot;
void solve(){
	n=read(),m=read(),l=read(),vm=read();
	for(int i=1;i<=n;i++) d[i]=read(),v[i]=read(),a[i]=read();
	for(int i=1;i<=m;i++) p[i]=read();
	sort(p+1,p+m+1);
	ans1=tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]>vm&&p[m]>=d[i]){
				s[++ans1]=(seg){get1(d[i]),m};
			}
		}
		else{
			int ld=get1(d[i]);
			if(a[i]>0){
				if(d[i]>p[m]) continue;
				if(vm<v[i]) s[++ans1]=(seg){ld,m};
				else{
					int nxt=d[i]+(vm*vm-v[i]*v[i])/(2*a[i])+1;
					int ll=get1(nxt);
					if(ll<=m){
						s[++ans1]=(seg){ll,m};
					}
				}
			}
			if(a[i]<0){
				if(v[i]<=vm) continue;
				int nxt=d[i]+(vm*vm-v[i]*v[i]-1)/(2*a[i]);
				if(nxt>l) s[++ans1]=(seg){ld,m};
				else{
					int rr=get2(nxt);
					if(ld<=rr) s[++ans1]=(seg){ld,rr};
				}
			}
		}
	}
	printf("%d ",ans1);
	sort(s+1,s+ans1+1,cmp);
	for(int i=1;i<=ans1;i++) del[i]=0;
	for(int i=ans1;i>=1;i--)if(!del[i]){
		for(int j=i-1;j>=1;j--){
			if(s[j].q<s[i].q) break;
			del[j]=1;
		}
	}
	for(int i=1;i<=ans1;i++)if(!del[i]) t[++tot]=s[i];
	for(int i=1;i<=tot;i++){
		int lf=0,rt=i-1,ans=i-1;
		while(lf<=rt){
			int mid=(lf+rt)>>1;
			if(t[mid].q>=t[i].p) rt=mid-1;
			else ans=mid,lf=mid+1;
		}
		f[i]=f[ans]+1;
	}
	printf("%d\n",m-f[tot]);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}

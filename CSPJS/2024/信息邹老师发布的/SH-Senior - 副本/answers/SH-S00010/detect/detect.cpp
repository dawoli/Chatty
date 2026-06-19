#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=200009;
const int mod=998244353;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		s=s*10+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int n,m,L,V;
int v[N],a[N];
double d[N],p[N];
int opt[N];
int tyf[N],l[N],r[N];
struct node{int l,r;} x[N];
bool cmp(const node&p,const node&q){
	return p.l<q.l;
} 
int mn[N];
inline void solve(){
	n=read(); m=read(); L=read(); V=read();
	for(int i=1;i<=n;i++)d[i]=read(),v[i]=read(),a[i]=read();
	for(int i=1;i<=m;i++)p[i]=read();
	memset(tyf,0,sizeof(tyf));
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]<=V)continue;
			if(d[i]>p[m])continue;
			int pos=lower_bound(p+1,p+m+1,d[i])-p;
			if(pos<=m)tyf[i]=1,l[i]=pos,r[i]=m;
		}
		if(a[i]<0){
			if(v[i]<=V)continue;
			double lim=1.0*(v[i]*v[i]-V*V)/(2*abs(a[i]))+d[i];
			int pos1=lower_bound(p+1,p+m+1,d[i])-p;
			int pos2=lower_bound(p+1,p+m+1,lim)-p;
			if(pos1<pos2)tyf[i]=1,l[i]=pos1,r[i]=pos2-1;
			//�Ͻ磺(v[i]^2-V*2)/(2|a[i]|) 
		}
		if(a[i]>0){
			if(v[i]>V){
				int pos=lower_bound(p+1,p+m+1,d[i])-p;
				if(pos<=m)tyf[i]=1,l[i]=pos,r[i]=m;
				continue;
			}
			double lim=1.0*(V*V-v[i]*v[i])/(2*a[i])+d[i];
			if(p[m]<=lim)continue;
			int pos=upper_bound(p+1,p+m+1,lim)-p;
			if(pos<=m)tyf[i]=1,l[i]=pos,r[i]=m;
		}
	}
//	for(int i=1;i<=n;i++)cout<<tyf[i]<<' '<<l[i]<<' '<<r[i]<<'\n';
	int ans1=0;
	for(int i=1;i<=n;i++)ans1+=tyf[i];
	cout<<ans1<<' ';
	int tot=0;
	for(int i=1;i<=n;i++)if(tyf[i])x[++tot]=(node){l[i],r[i]};
	sort(x+1,x+tot+1,cmp);
	mn[tot+1]=0x3f3f3f3f;
	for(int i=tot;i>=1;i--)mn[i]=min(mn[i+1],x[i].r);
	int ans2=m,now=1;
	while(now<=tot){
		int tmp=mn[now];
		ans2--;
		while(now<=tot&&x[now].l<=tmp)now++;
	}
	cout<<ans2<<'\n';
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int _=read();
	while(_--){
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}e[100010];
int t,n,m,L,hh,V,pos,ans1,ans2,f,ff,d[100010],v[100010],a[100010],p[100010],dp[4000010],flag[100010];
inline int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return k*f;
}
bool cmp(node x,node y){
	return x.l<y.l;
}
void init(){
	pos=1;
	ans1=ans2=f=ff=0;
	for(int i=1;i<=100000;i++){
		e[i].l=e[i].r=-1;
	}
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0]=0;
	memset(flag,0,sizeof(flag)); 
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--){
		init();
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=n;i++) d[i]=read(),v[i]=read(),a[i]=read();
		for(int i=1;i<=n;i++){
			if(a[i]!=0) f=1;
			if(a[i]<=0) ff=1;
		}
		for(int i=1;i<=m;i++) p[i]=read();
		if(!f){
			for(int i=1;i<=n;i++){
				if(v[i]<=V) continue;
				if(d[i]<=p[m]) ans1++;
			}
			cout<<ans1<<" "<<m-1<<"\n";
			continue;
		}
		if(!ff){
			for(int i=1;i<=n;i++){
				if(v[i]==V) d[i]++;
				else if(v[i]<V){
					int tmp1=V*V-(v[i]*v[i]),tmp2=2*a[i];
					d[i]+=tmp1/tmp2+1;
				} 
				if(d[i]<=p[m]) ans1++;
			}
			cout<<ans1<<" "<<m-1<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(v[i]>V){
				e[i].l=d[i];
				if(a[i]>=0) e[i].r=L;
				else{
					int tmp1=(v[i]*v[i])-V*V,tmp2=2*(-a[i]);
					if(tmp1%tmp2==0) e[i].r=e[i].l+tmp1/tmp2-1;
					else e[i].r=e[i].l+tmp1/tmp2;
				}
			}
			else if(v[i]==V){
				if(a[i]>0){
					e[i].l=d[i]+1;
					e[i].r=L;
				}
				else e[i].l=e[i].r=-1;
			}
			else{
				if(a[i]>0){
					int tmp1=V*V-(v[i]*v[i]),tmp2=2*a[i];
					e[i].l=d[i]+tmp1/tmp2+1,e[i].r=L;
				}
				else e[i].l=e[i].r=-1;
			}
			if(e[i].l>e[i].r) e[i].l=e[i].r=-1;
		}
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(e[i].l==-1&&e[i].r==-1) continue;
			while(e[i].l>p[pos]&&pos<=m) pos++;
			if(p[pos]>=e[i].l&&p[pos]<=e[i].r) ans1++;
			else e[i].l=e[i].r=-1; 
		}
		cout<<ans1<<" ";
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(e[i].l!=-1&&e[i].r!=-1){
				hh=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(e[i].l==-1&&e[i].r==-1) continue;
			for(int j=1;j<=m;j++){
				if(p[j]>=e[i].l&&p[j]<=e[i].r) flag[j]|=(1<<(i-hh));
			}
		}
		for(int i=0;i<(1<<(n-hh+1))-1;i++){
			for(int j=1;j<=m;j++){
				dp[i|flag[j]]=min(dp[i|flag[j]],dp[i]+1);
			}
		}
		cout<<m-dp[(1<<(n-hh+1))-1]<<"\n";
	}
	return 0;
} 

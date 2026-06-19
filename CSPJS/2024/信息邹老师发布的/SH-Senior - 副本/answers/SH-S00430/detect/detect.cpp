#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int T,n,m,L,v;
int d[N],v0[N],a[N],l[N],r[N],p[N];
struct node{
	int l,r;
}pos[N];
bool cmp(node a,node b){
	return a.r<b.r;
}
int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),L=read(),v=read();
		for(int i=1;i<=n;i++){
			d[i]=read(),v0[i]=read(),a[i]=read();
			if(a[i]>0){
				l[i]=min(L+1,max(0ll,(int)floor((v*v-v0[i]*v0[i])/(2.0*a[i]))+1)+d[i]);
				r[i]=L;
			}
			else if(a[i]<0){
				if(v0[i]<=v) l[i]=L+1;
				else l[i]=d[i];
				r[i]=min(L,max(0ll,(int)ceil((v*v-v0[i]*v0[i])/(2.0*a[i]))-1)+d[i]);
			}
			else{
				if(v0[i]<=v) l[i]=L+1;
				else l[i]=d[i];
				r[i]=L;
			}
		}
		for(int i=1;i<=m;i++){
			p[i]=read();
		}
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			pos[i].l=pos[i].r=0;
			if(l[i]==L+1) continue;
			int ll=1,rr=m;
			while(ll<=rr){
				int mid=(ll+rr)>>1;
				if(p[mid]>=l[i]){
					rr=mid-1;
					pos[i].l=mid;
				}
				else ll=mid+1;
			}
			ll=1,rr=m;
			while(ll<=rr){
				int mid=(ll+rr)>>1;
				if(p[mid]<=r[i]){
					ll=mid+1;
					pos[i].r=mid;
				}
				else rr=mid-1;
			}		}
		sort(pos+1,pos+n+1,cmp);
		int now=0;
		for(int i=1;i<=n;i++){
			if(!pos[i].l||!pos[i].r||pos[i].l>pos[i].r){
				++ans1;
				continue;
			}
			if(pos[i].l<=now&&now<=pos[i].r) continue;
			now=pos[i].r;
			++ans2;
		}
		write(n-ans1); 
		putchar(' '); 
		write(m-ans2); 
		puts("");
	}
}

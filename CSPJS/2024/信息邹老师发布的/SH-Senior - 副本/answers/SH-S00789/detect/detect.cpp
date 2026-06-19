#include<bits/stdc++.h>
#define N 100005
#define INF 2e9
using namespace std;
int T,n,m,L,V,p[N],cnt=0,mxr,pre,tot=0,q;
struct car{
	int d,v,a,s,l,r;
}c[N],cd[N];
int alocate(int s){
	int l=1,r=m,mid,ans=INF;
	while(l<=r){
		mid=(l+r)/2;
		if(p[mid]>=s){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1; 
	}
	return ans;
}
int dlocate(int s){
	int l=1,r=m,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(p[mid]<s){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
bool cmp(const car &a,const car &b){
	return a.r<b.r;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]);
		cnt=mxr=tot=pre=q=0;
		for(int i=1;i<=n;i++){
			if(c[i].a>0){
				if(c[i].v<=V) c[i].s=c[i].d+1+(V*V-c[i].v*c[i].v)/(2*c[i].a);
				else c[i].s=c[i].d;
				c[i].l=alocate(c[i].s);
				if(c[i].l<INF){
					cnt++;
					mxr=max(mxr,c[i].l);
				}
			}
			else if(c[i].a==0){
				if(c[i].v<=V) c[i].s=INF;
				else c[i].s=c[i].d;
				c[i].l=alocate(c[i].s);
				if(c[i].l<INF){
					cnt++;
					mxr=max(mxr,c[i].l);
				}
			}
			else{
				if(c[i].v<=V) c[i].s=-1;
				else{
					c[i].s=c[i].v*c[i].v-V*V;
					if(c[i].s%(2*(-c[i].a))==0) c[i].s=c[i].d+c[i].s/(2*(-c[i].a))-1;
					else c[i].s=c[i].d+c[i].s/(2*(-c[i].a));
				}
				c[i].r=dlocate(c[i].s);
				if(c[i].r>0&&p[c[i].r]>=c[i].d){
					cnt++;
					cd[++q]=c[i];
				}
			}
		}
		sort(cd+1,cd+q+1,cmp);
		for(int i=1;i<=q;i++){
			if(p[pre]<cd[i].d){
				tot++;
				pre=cd[i].r;
			}
		}
		if(pre<mxr) tot++;
		tot=m-tot;
		printf("%d %d\n",cnt,tot);
	}
	return 0;
}


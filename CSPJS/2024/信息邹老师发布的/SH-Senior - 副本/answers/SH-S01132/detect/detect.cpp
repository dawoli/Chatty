#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
}c[100001];
bool cmp(car a,car b){
	return a.d<b.d;
}
long long T,n,m,L,vv,V,dj,j,ans,ykd,mid,l,r,an,far,ds;
int jsc,p[100001],nd[1000001];
bool vis[1000001],flag;
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
cin>>T;
while(T--){
	far=0,ds=0;
	memset(nd,0,sizeof(nd));
	scanf("%lld %lld %lld %lld",&n,&m,&L,&vv);
	for(int i=0;i<n;i++)scanf("%lld %lld %lld",&c[i].d,&c[i].v,&c[i].a);
	for(int i=0;i<m;i++)scanf("%lld",&p[i]);
	memset(vis,0,sizeof(vis));
	sort(c,c+n,cmp);
	ans=0,ykd=0;
	V=vv*vv;
	jsc=0;
	dj=0;
	j=0;
	for(int i=0;i<n;i++){
		if(c[i].a>0){
			flag=0;
			while(p[dj]<c[i].d)dj++;
			if((c[i].v*c[i].v+2*c[i].a*(p[m-1]-c[i].d))>V)ans++,flag=1;
			if(flag){
				l=dj,r=m-1,an=m-1;
				while(l<r){
					mid=(l+r)>>1;
					if((c[i].v*c[i].v+2*c[i].a*(p[m-1]-c[i].d))>V)an=mid,l=mid+1;
					else r=mid;
				}
				mid=(l+r)>>1;
				if((c[i].v*c[i].v+2*c[i].a*(p[m-1]-c[i].d))>V)an=mid,l=mid+1;
				jsc=max(jsc,p[an]);
			}
		}else if(c[i].a<0){
			flag=0;
			while(p[j]<c[i].d)j++;
			if((c[i].v*c[i].v+2*c[i].a*(p[j]-c[i].d))>V)flag=1,ans++;
			if(flag){
				l=j,r=m-1,an=j;
				while(l<r){
					mid=(l+r)>>1;
					if((c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d))>V)an=mid,l=mid+1;
					else r=mid;
				}
				mid=(l+r)>>1;
				if((c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d))>V)an=mid,l=mid+1;
				vis[p[an]]=1,nd[p[an]]=c[i].d;
			}
		}else{
			if(c[i].d<=p[m-1]&&c[i].v>vv)ans++,ds=1;
		}
	}
	for(int i=0;i<m;i++){
		if(vis[p[i]]&&nd[p[i]]>far)ykd++,far=p[i];
	}
	if(jsc>far)ykd++;
	if(ds)ykd++;
	printf("%lld %lld\n",ans,m-ykd);
}
return 0;
}

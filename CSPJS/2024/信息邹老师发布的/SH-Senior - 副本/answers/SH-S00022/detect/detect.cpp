#include<bits/stdc++.h>
using namespace std;
struct CAR{
	int d,v,a,ovr,s,t;
}c[100009]; 
struct DETECTION{
	int p,ls;
}dtt[100009];
int T,n,m,L,V,cnt,ans;
void calc(int x){
	if(c[x].a==0&&c[x].v>V)c[x].s=c[x].d,c[x].t=L;
	if(c[x].a==0&&c[x].v<=V)c[x].s=L+1,c[x].t=L;
	if(c[x].a>0){
		int l=c[x].d,r=L+1,mid;
		while(l<r){
			mid=(l+r)/2;
			if(c[x].v*c[x].v+2*c[x].a*(mid-c[x].d)>V*V)
				r=mid;
			else l=mid+1;
		}
		c[x].s=l,c[x].t=L;
	}
	if(c[x].a<0&&c[x].v<=V)c[x].s=L+1,c[x].t=L;
	if(c[x].a<0&&c[x].v>V){
		int l=c[x].d,r=L+1,mid;
		while(l<r){
			mid=(l+r)/2;
			if(c[x].v*c[x].v+2*c[x].a*(mid-c[x].d)<=V*V)
				r=mid;
			else l=mid+1;
		}
		c[x].s=c[x].d,c[x].t=l-1;
	}
	if(c[x].s<=c[x].t){
		int l=1,r=m+1,mid;
		while(l<r){
			mid=(l+r)/2;
			if(dtt[mid].p>=c[x].s)
				r=mid;
			else l=mid+1;
		}
		c[x].s=l;
		l=1,r=m+1,mid;
		while(l<r){
			mid=(l+r)/2;
			if(dtt[mid].p>c[x].t)
				r=mid;
			else l=mid+1;
		}
		c[x].t=l-1;
	}
	if(c[x].s<=c[x].t){
		c[x].ovr=1,cnt++;
		dtt[c[x].t].ls=max(dtt[c[x].t].ls,c[x].s);
	}
}
int read(){
	char c;
	int f=1,res=0;
	c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))
		c=getchar();
	if(c=='-')
		f=-1,c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V,cnt=0,ans=0;
		for(int i=1;i<=n;i++)
			c[i].d=read(),c[i].v=read(),c[i].a=read(),c[i].ovr=c[i].s=c[i].t=0;
		for(int i=1;i<=m;i++)
			dtt[i].p=read(),dtt[i].ls=-1;
		dtt[m+1].p=L+1;
		for(int i=1;i<=n;i++)
			calc(i);
		cout<<cnt<<" ";
		if(cnt==0)cout<<m<<endl;
		else cout<<m-1<<endl;
	}
	return 0;
}

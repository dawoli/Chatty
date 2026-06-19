#include<bits/stdc++.h>
using namespace std;
struct car{
	int x,y,v,a,l,r,f,h;
}a[100005],f[100005];
struct tr{
	int l,r,x;
}t[4000005];
int n,b[100005],m,tt,l,v,tot2,tot,mxn[100005],d[1000005];
vector<int> s[1000005];
bool cmp(car a,car b){
	return a.h<b.h;
}
void sad(int i,int k){
	for(;i<=l;i+=i&(-i)) s[i].push_back(k);
}
void sad2(int i){
	for(;i<=l;i+=i&(-i)) d[i]++;
}
int sfd(int i){
	int h=0;
	for(;i>0;i-=i&(-i)) h+=s[i].size();
	return h;
}
int sfd2(int i){
	int h=0;
	for(;i>0;i-=i&(-i)) h+=d[i];
	return h;
}
void bd(int z,int y,int p){
	t[p].l=z,t[p].r=y;
	if(z==y){
		mxn[z]=p;
		return;
	}
	int mid=(z+y)/2;
	bd(z,mid,p*2);
	bd(mid+1,y,p*2+1);
}
void ad(int z,int y,int p,int k){
	if(z<=t[p].l && y>=t[p].r){
		t[p].x+=k;
		return;
	}
	if(z>t[p].r || y<t[p].l) return;
	int mid=(t[p].l+t[p].r)/2;
	if(z<=mid) ad(max(z,t[p].l),min(y,mid),p*2,k);
	if(y>mid) ad(max(mid+1,z),min(t[p].r,y),p*2+1,k);
}
int fmx(int p){
	if(p/2>0) return t[p].x+fmx(p/2);
	return t[p].x;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>tt;
	while(tt--){
		memset(d,0,sizeof(d));
		for(int i=0;i<=1000005;i++) s[i].clear();
		tot=0;tot2=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].v>>a[i].a;
			if(a[i].a<=0 && a[i].v<=v) a[i].f=0;
			else if(a[i].a>0 && a[i].v*a[i].v+2*a[i].a*(l-a[i].x)<=v*v) a[i].f=0;
			else{
				int p=v*v-a[i].v*a[i].v;a[i].f=1,a[i].y=l;
				if(a[i].a<0){
					int x=a[i].v*a[i].v,y=-a[i].a,si=x/(2*y);
					a[i].y=min(l,a[i].x+si);
					x=-p,y=-a[i].a,si=x/(2*y);
					if(x%(2*y)==0) si--;
					a[i].l=a[i].x,a[i].r=min(a[i].y,a[i].l+si);
				}
				else if(a==0) a[i].l=a[i].x,a[i].r=a[i].y;
				else{
					int si=p/(2*a[i].a)+1;
					if(a[i].v>v) a[i].l=a[i].x;
					else a[i].l=a[i].x+si;
					a[i].r=l;
				}
				f[++tot2]=a[i];
			}
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
			sad(b[i],i);
		}
		int h=0;
		for(int i=1;i<=tot2;i++){
			f[i].h=sfd(f[i].r)-sfd(f[i].l-1);
			if(f[i].h>0) a[++tot]=f[i],h++;
		}
		cout<<h<<" ";h=0;
		sort(a+1,a+1+tot,cmp);
		bd(1,l,1);
		for(int i=1;i<=tot;i++) ad(a[i].l,a[i].r,1,1);
		for(int i=1;i<=tot;i++){
			int ff=sfd2(a[i].r)-sfd2(a[i].l-1);
			if(ff){
				ad(a[i].l,a[i].r,1,-1);
				continue;
			}
			int mx=0,q=0;
			for(int j=1;j<=m;j++){
				if(b[j]>=a[i].l && b[j]<=a[i].r){
					int mn=fmx(mxn[b[j]]);
					if(mx<mn) mx=mn,q=b[j];
				}
			}
			sad2(q);h++;
			ad(a[i].l,a[i].r,1,-1);
		}
		cout<<n-h;
	}
	return 0;
} 
/*1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15*/

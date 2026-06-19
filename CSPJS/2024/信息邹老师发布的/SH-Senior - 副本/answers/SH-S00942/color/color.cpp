#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,c;
int a[200005];
int fa[200005];
struct lnode{
	int r,val,lmax,rmax;
}l[200005];
int r[200005];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int find(int u){
	if(fa[u]!=u) fa[u]=find(fa[u]);
	return fa[u];
}
void uni(int u,int v){
	int r1=find(u);
	int r2=find(v);
	if(r1!=r2){
		fa[r2]=r1;
		l[r1].val=l[r1].val+l[r2].val;
		l[r1].lmax=min(l[r1].lmax,l[r2].lmax);
		l[r1].rmax=max(l[r1].rmax,l[r2].rmax);
	}
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		c=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			l[i].r=0;
			l[i].val=0;
			r[i]=0;
			for(int j=1;j<i;j++)
			if(a[i]==a[j]){
				fa[j]=j;
				l[j].r=i;
				l[j].rmax=i;
				l[j].lmax=j;
				l[j].val=a[i];
				r[i]=j;
			}
		}
		for(int i=1;i<n;i++){
			if(l[i].val!=0){
				if(l[i].r-i==2){
					if(l[i+1].val!=0){
						uni(i,i+1);
					}
					if(r[i+1]!=0){
						uni(r[i+1],i);
					}
				}
				for(int j=l[i].rmax;j<n;j++){
					if(l[j].val!=0){
						uni(i,j);
					}
				}
			}
		}
		for(int i=1;i<=n;i++) c=max(c,l[i].val);
		cout<<c<<endl;
	}
	return 0;
}

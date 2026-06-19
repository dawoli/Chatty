#include<bits/stdc++.h>
using namespace std;
#define int long long
//非常简单，以后T1都这么出 
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int n;
struct node{
	int x,y,z;
}a[100005],x[100005],y[100005],z[100005];
int nx,ny,nz;
bool cmpx(node u,node v){
	return u.x-max(u.y,u.z)<v.x-max(v.y,v.z);
}
bool cmpy(node u,node v){
	return u.y-max(u.x,u.z)<v.y-max(v.x,v.z);
}
bool cmpz(node u,node v){
	return u.z-max(u.y,u.x)<v.z-max(v.y,v.x);
}
signed main(){//club
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int ans=0;
		nx=0,ny=0,nz=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			int ma=max(a[i].x,max(a[i].y,a[i].z));
			ans+=ma;
			if(a[i].x==ma){
				x[++nx]=a[i];
			}
			else if(a[i].y==ma){
				y[++ny]=a[i];
			}
			else {
				z[++nz]=a[i];
			}
		}
		if(max(nx,max(ny,nz))>n/2){
			if(nx>n/2){
				sort(x+1,x+nx+1,cmpx);
				for(int i=1;i<=nx-(n/2);i++){
					ans-=x[i].x-max(x[i].y,x[i].z);
				}
			}
			else if(ny>n/2){
				sort(y+1,y+ny+1,cmpy);
				for(int i=1;i<=ny-(n/2);i++){
					ans-=y[i].y-max(y[i].x,y[i].z);
				}
			}
			else if(nz>n/2){
				sort(z+1,z+nz+1,cmpz);
				for(int i=1;i<=nz-(n/2);i++){
					ans-=z[i].z-max(z[i].y,z[i].x);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

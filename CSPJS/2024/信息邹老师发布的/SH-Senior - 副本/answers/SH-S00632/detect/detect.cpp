#include<bits/stdc++.h>
#define ld long double
using namespace std;
struct node {
	int id,si;
};
node big[100005];
ld n,m,L,V,d[100005],v[100005],a[100005],p[100005],vis[25][100005],t,s;
vector<int> f[25][100005];
long long ans1,ans2,T;
bool flag;
bool cmp(node sdf,node dfg) {
	return sdf.si>dfg.si;
}
void add(ld x,ld y,int isa,int isb,int isc) {
	int l=1,r=m,mid,ans;
	if(isa==1) {
		while(l<=r) {
			mid=(l+r)>>1;
			if(p[mid]>=x) {
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	if(isa==0) {
		while(l<=r) {
			mid=(l+r)>>1;
			if(p[mid]>x) {
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	if(isa==1&&isb==1&&(p[ans]<x||p[ans]>y))return;
	if(isa==0&&isb==1&&(p[ans]<=x||p[ans]>y))return;
	if(isa==1&&isb==0&&(p[ans]<x||p[ans]>=y))return;
	if(isa==0&&isb==0&&(p[ans]<=x||p[ans]>=y))return;
	ans1++;
	if(isb==1) {
		for(int i=ans;p[i]<=y&&i<=m;i++) {
			f[T][i].push_back(isc);
		}
	}
	if(isb==0) {
		for(int i=ans;p[i]<y&&i<=m;i++) {
			f[T][i].push_back(isc);
		}
	}
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--) {
		ans1=ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		for(int i=1;i<=n;i++) {
			t=(V-v[i])/a[i];
			s=v[i]*t+0.5*a[i]*t*t;
			if(v[i]<=V&&a[i]<=0)continue;
			if(v[i]>V&&a[i]>=0)add(d[i],L,1,1,i);
			if(v[i]==V)add(d[i],L,0,1,i);
			if(v[i]>V&&a[i]<0)add(d[i],d[i]+s,1,0,i);
			if(v[i]<V&&d[i]+s<L)add(d[i]+s,L,0,1,i);
		}
		for(int i=1;i<=m;i++) {
			big[i].id=i;
			big[i].si=f[T][i].size();
		}
		sort(big+1,big+(int)m+1,cmp);
		for(int i=1;i<=m;i++) {
			flag=false;
			for(int j:f[T][big[i].id]) {
				if(vis[T][j]==0) {
					flag=true;
					vis[T][j]=1;
				}
			}
			if(!flag)ans2++;
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
    return 0;
}

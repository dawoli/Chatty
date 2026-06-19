#include<bits/stdc++.h>
using namespace std;
struct node{
	int ll,rr;
};
node h[100005]={};
int n,m,l,v;
int d[100005]={};
int vv[100005]={};
int a[100005]={};
int p[100005]={};
int ll[100005]={};
int rr[100005]={};
bool cmp(node x,node y){
	return x.rr<y.rr;
}
void solve(){
	cin>>n>>m>>l>>v;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&d[i],&vv[i],&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++){
		if(p[m]<d[i]){
			ll[i]=-1;
			continue;
		}
		int l=1,r=m;
		while(l<=r){
			int mid=l+r>>1;
			if(p[mid]>=d[i]){
				r=mid-1;
			}else l=mid+1;
		}
		r=m;
		if(a[i]==0){
			if(vv[i]>v){
				ll[i]=l,rr[i]=r;
			}else ll[i]=-1;
		}
		else if(a[i]>0){
			if(v*v>=vv[i]*vv[i]+2*a[i]*(p[m]-d[i])){
				ll[i]=-1;
			}
			else{
				while(l<=r){
					int mid=l+r>>1;
					if(v*v<vv[i]*vv[i]+2*a[i]*(p[mid]-d[i])){
						r=mid-1;
					}else l=mid+1;
				}
				ll[i]=l,rr[i]=m;
			}	
		}else{
			if(v*v>=vv[i]*vv[i]+2*a[i]*(p[l]-d[i])){
				ll[i]=-1;
			}
			else{
				ll[i]=l;
				while(l<=r){
					int mid=l+r>>1;
					if(v*v<vv[i]*vv[i]+2*a[i]*(p[mid]-d[i])){
						l=mid+1;
					}else r=mid-1;
				}
				rr[i]=r;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		h[i].ll=ll[i];
		h[i].rr=rr[i];
		if(ll[i]!=-1)cnt++;
	}
	cout<<cnt<<" ";
	sort(h+1,h+n+1,cmp);
	cnt=0;
	int be=0;
	for(int i=1;i<=n;i++){
		if(h[i].ll==-1)continue;
		if(h[i].ll<=be)continue;
		else{
			be=h[i].rr;
			cnt++;
		}
	}
	cout<<m-cnt<<'\n';
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 

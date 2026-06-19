#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,a[100010],b[100010],c[100010],s[100010],dp[100010],tr[400010],h[100010],f[100010],t,ml,mr,l,r,ans;
pair<int,int>p[100010];
set<int>R;
vector<pair<int,int>>e;
int query(int i,int l,int r,int kl,int kr){
	if(kl>r||kr<l)return 1e9;
	if(kl<=l&&kr>=r)return tr[i];
	int m=(l+r)/2;
	return min(query(i*2,l,m,kl,kr),query(i*2+1,m+1,r,kl,kr));
}
void add(int i,int l,int r,int k){
	if(l==r){tr[i]=min(tr[i],dp[k]);return;}
	int m=(l+r)/2;
	((k<=m)?add(i*2,l,m,k):add(i*2+1,m+1,r,k)),tr[i]=min(tr[i*2],tr[i*2+1]);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d),e.clear(),R.clear(),ans=1e9,ml=mr=0,memset(tr,0x3f,sizeof(tr));
		for(int w=1;w<=n;w++)scanf("%d%d%d",&a[w],&b[w],&c[w]);
		for(int w=1;w<=m;w++)scanf("%d",&s[w]);
		for(int w=1;w<=n;w++){
			if(c[w]>0){
				l=a[w],r=k;
				while(l<r){int m=(l+r)/2;if(1ll*b[w]*b[w]+2ll*c[w]*(m-a[w])<=1ll*d*d)l=m+1;else r=m;}
				r=k;
			}else if(c[w]<0){
				l=a[w],r=k;
				while(l<r){int m=(l+r+1)/2;if(1ll*b[w]*b[w]+2ll*c[w]*(m-a[w])<=1ll*d*d)r=m-1;else l=m;}
				l=a[w];
			}else if(c[w]==0)if(b[w]>d)l=a[w],r=k;else r=-1;
			if(l<=r)l=lower_bound(s+1,s+m+1,l)-s,r=upper_bound(s+1,s+m+1,r)-s,r--;
			if(l<=r)e.push_back({l,r}),ml=max(ml,l),mr=max(mr,r);
		}
		sort(e.begin(),e.end());
		for(int w=1;w<=e.size();w++)h[w]=e[w-1].first,p[w]={e[w-1].second,e[w-1].first};
		sort(p+1,p+e.size()+1);
		for(int w=1;w<=e.size();w++)f[w]=p[w].first;
		for(int w=1,x=1;w<=m;w++){
			auto k=R.lower_bound(w);
			if(k!=R.begin()){
				k--;
				int y=-1,z=*k,u=z-1;
				if(h[1]<z)u=h[lower_bound(h+1,h+e.size()+1,z)-h-1];
				y=u;
				if(w==1||y+1>w-1||y<0)dp[w]=1;else dp[w]=query(1,1,m,y+1,w-1)+1;add(1,1,m,w);
			}else dp[w]=1,add(1,1,m,w);
			while(p[x].second==w)R.insert(p[x].first),x++;
		}
		for(int w=ml;w<=mr;w++)ans=min(ans,dp[w]);
		printf("%d %d\n",e.size(),m-ans);
	}
	return 0;
}

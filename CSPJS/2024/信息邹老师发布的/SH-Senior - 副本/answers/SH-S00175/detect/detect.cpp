#include<bits/stdc++.h>
using namespace std;
//以防万一
typedef long double ld;
int n, t, m, ql[100005], qr[100005], ans=0, dp[100005];
ld l, v, p[100005];
vector <int> g[100005];
struct C{
	ld d;
	ld v;
	ld a;
}c[100005];
inline int B(ld d){//比这个距离大于等于的第一个点 
	if(d<=0) return 1;
	if(d>l) return m+1;
	int L=1, R=m, mid, ans=m+1;
	while(L<=R){
		mid=(L+R)/2;
		if(p[mid]<d) L=mid+1;
		else ans=mid, R=mid-1;
	}
	return ans;
}
inline int Bi(ld d){//比这个距离大于的第一个点 
	if(d<0) return 1;
	if(d>=l) return m+1;
	int L=1, R=m, mid, ans=m+1;
	while(L<=R){
		mid=(L+R)/2;
		if(p[mid]<=d) L=mid+1;
		else ans=mid, R=mid-1;
	}
	return ans;
}
inline int Lo(ld d){//比这个距离小于的第一个点 
	if(d<=0) return 0;
	if(d>l) return m;
	int L=1, R=m, mid, ans=0;
	while(L<=R){
		mid=(L+R)/2;
		if(p[mid]>=d) R=mid-1;
		else ans=mid, L=mid+1;
	}
	return ans;
}
inline void run(int x){
	if(c[x].a>0){
		if(c[x].v>v){ql[x]=B(c[x].d), qr[x]=max(m,ql[x]);}
		else{
			ql[x]=Bi(c[x].d+(v*v-c[x].v*c[x].v)/(2.0*c[x].a));
			qr[x]=max(m,ql[x]);
		}
	}
	if(c[x].a==0){
		if(c[x].v>v){ql[x]=B(c[x].d), qr[x]=max(m,ql[x]);}
		else{ql[x]=qr[x]=m+1;}
	}
	if(c[x].a<0){
		if(c[x].v<=v){ql[x]=qr[x]=m+1;}
		else{
			int bb=B(c[x].d), ll=Lo(c[x].d+(c[x].v*c[x].v-v*v)/(2.0*(-c[x].a)));
			if(bb<=ll){
				ql[x]=bb, qr[x]=ll;
			}
			else{
				ql[x]=qr[x]=m+1;
			}
		}
	}
	if(ql[x]>=1&&ql[x]<=m&&qr[x]>=1&&qr[x]<=m&&ql[x]<=qr[x]){
		ans++;
		g[qr[x]].push_back(ql[x]);
	}
	return;
}
int main(){
	freopen("detect.in","r",stdin); freopen("detect.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>t;
	while(t){
		t--;
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n>>m>>l>>v;
		for(int i=1; i<=n; i++){cin>>c[i].d>>c[i].v>>c[i].a;}
		for(int i=1; i<=m; i++){g[i].clear();cin>>p[i];}
		for(int i=1; i<=n; i++){run(i);}
		for(int i=1; i<=m; i++){//开始dp
			dp[i]=dp[i-1]; 
			for(auto y:g[i]){
				dp[i]=max(dp[i],dp[y-1]+1);
			}
		}
		cout<<ans<<" "<<m-dp[m]<<'\n';
	}
	return 0;
}

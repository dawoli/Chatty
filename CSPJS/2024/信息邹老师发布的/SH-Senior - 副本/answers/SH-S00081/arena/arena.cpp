#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(ll)((1ll<<31)-1);
const int N=(1<<17)+999,L=18;
int n,m,k,num,a[N],b[N],c[N],x[4];
//!!! num !!! 
int lg[N],d[L][N];
pair<int,int> f[L][N];
#define ln node*2-1
#define rn node*2
int l[L][N],r[L][N];
void pushup(int dep,int node){
	int mid=(l[dep][node]+r[dep][node])/2;
	if(d[dep][node]==0){
		int mn=inf;
		for(int i=l[dep][node];i<=mid;i++)
			if(f[dep+1][i].first!=-1){
				mn=min(f[dep+1][i].first,mn);
				if(f[dep+1][i].second>=k-dep) f[dep][i]=make_pair(max(f[dep+1][i].first,k-dep),f[dep+1][i].second);
				else f[dep][i]=make_pair(-1,-1);
			}
			else f[dep][i]=make_pair(-1,-1);
		if(mn<k-dep)
			for(int i=mid+1;i<=r[dep][node];i++)
				f[dep][i]=f[dep+1][i];
		else
			for(int i=mid+1;i<=r[dep][node];i++)
				f[dep][i]=make_pair(-1,-1);
	}
	else{
		int mn=inf;
		for(int i=mid;i<=r[dep][node];i++)
			if(f[dep+1][i].first!=-1){
				mn=min(f[dep+1][i].first,mn);
				if(f[dep+1][i].second>=k-dep) f[dep][i]=make_pair(max(f[dep+1][i].first,k-dep),f[dep+1][i].second);
				else f[dep][i]=make_pair(-1,-1);
			}
			else f[dep][i]=make_pair(-1,-1);
		if(mn<k-dep)
			for(int i=l[dep][node];i<=mid;i++)
				f[dep][i]=f[dep+1][i];
		else
			for(int i=l[dep][node];i<=mid;i++)
				f[dep][i]=make_pair(-1,-1);
	}
	return;
}
void build(int dep,int node,int lf,int rg){
	l[dep][node]=lf; r[dep][node]=rg;
	if(lf==rg){
		f[dep][lf]=make_pair(0,inf);
		return;
	}
	int mid=(lf+rg)/2; 
	build(dep+1,ln,lf,mid); build(dep+1,rn,mid+1,rg);
	pushup(dep,node);
	return;
}
ll ans[N];
ll query(int dep){
//	cerr<<endl;
	ll res=0;
	for(int i=1;i<=r[dep][1];i++)
		if(f[dep][i].first!=-1){
			res+=i;
//			cerr<<i<<endl; 
		}
	return res;
}
void solve1(){
	for(int i=0;i<4;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		a[i]^=x[i%4];
//		cerr<<a[i]<<" ";
	}
//	cerr<<endl; 
	build(0,1,1,num);
	int u;
	for(int i=1;i<=n;i++){
		u=i;
		f[k][i]=make_pair(a[i],a[i]);
		u=(u+1)/2;
		for(int j=k-1;j>=0;j--){
			pushup(j,u);
			u=(u+1)/2;
		}
		if(b[i]){
			u=lg[i];
			if((1<<u)<i) u++;
			ans[i]=query(k-u);
		}
	}
	ll answer=0;
	for(int i=1;i<=m;i++){
//		cerr<<ans[c[i]]<<" ";
		answer^=(ans[c[i]]*i);
	}
	cout<<answer<<'\n';
	for(int i=1;i<=n;i++)
		a[i]^=x[i%4];
	return;
}
char ch[N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i],b[c[i]]=1;
	lg[1]=0;
	for(int i=2;i<N;i++) lg[i]=lg[i>>1]+1;
	k=lg[n]; if((1<<k)<n) k++; num=(1<<k);
//	cerr<<k<<endl;
	for(int i=k-1;i>=0;i--){
		cin>>(ch+1);
		for(int j=1;j<=(1<<i);j++){
			d[i][j]=ch[j]-'0';
//			cerr<<d[i][j]<<" "; 
		}
//		cerr<<endl;
	}
	int T; cin>>T;
	while(T--){
		if(n<=5000&&m<=5000) solve1();
//		else solve2();		
	}
	return 0;
}

#include<bits/stdc++.h>
#define N 200005
#define mid ((l+r)>>1)
#define int long long
#define INF 5114514114514114514ll
using namespace std;
int n,m,k=1,a[N],aaa[N],c[N],x[4],d[20][N],ans,aans[N],id[N],mn[20][N],sm[20][N];
int dfs(int r,int g,int l,int r,int rek){
	if(!r){
		return;
	}
	if(b<mid){
		if(d[r][g]){
			int v=dfs(r-1,g*2,mid+1,r,r);
			if(v<r)return ans+=sm[r-1][g*2-1][rek],mn[r-1][g*2-1];
			return v;
		}
		else{
			ans+=sm[r-1][g*2-1][rek];
			if(mn[r-1][g*2-1]<k)return dfs(r-1,g*2,mid+1,r,rek);
			return mn[r-1][g*2-1]
		}
	}
	if(b==mid){
		if(d[r][g]){
			int v=0;ans+=S(mid+1,r);
			if(v<r)return ans+=sm[r-1][g*2-1][rek],mn[r-1][g*2-1];
			return v;
		}
		else{
			ans+=sm[r-1][g*2-1][rek];ans+=S(mid+1,r);
			if(mn[r-1][g*2-1]<k)return 0;
			return mn[r-1][g*2-1]
		}
	}
	if(b>mid){
		if(d[r][g]){
			return ans+=S(mid+1,r),dfs(r-1,g*2-1,l,mid,rek);
		}
		else{
			int v=dfs(r-1,g*2-1,l,mid,r);
			if(v<r)return ans+=S(mid+1,r),0;
			return v;
		}
	}
	dfs(r-1,g,l,mid,rek);
	dfs(r-1,g+(1<<(r-1)),1,mid+1,r,rek);
}
bool cmp(const int &x,const int &y){
	return c[x]<c[y];
}
void upd(int r,int g,int val){
	for(int i=0;i<=min(val,k);i++)++sm[r][g];
	mn[r][g]=min(mn[r][g],val);
	upd(r+1,g/2,val);
}
void solve(){
	for(int i=1;i<=m;i++)id[i]=i;
	
	stable_sort(id+1,id+1+m,cmp);
	for(int i=1,nw=0;i<=m;i++){
		while(nw<c[id[i]]){
			++nw;
			upd(1,nw,a[nw]);
		}
		ans=0,dfs(k,1,1,(1<<k),c[id[i]]),aans[id[i]]=ans;
	}
	int aaans=0;
	for(int i=1;i<=m;i++)aaans^=i*aans[i];
	cout<<aaans<<'\n';
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>aaa[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	while((1<<k)<=n)++k;
	for(int r=1;r<=k;r++)
		for(int g=1;g<=(1<<(k-r));g++)
			cin>>d[r][g],mn[r][g]=INF;
	for(int g=1;g<=(1<<k);g++)mn[0][g]=INF;
	cin>>T;
	while(T--){
		for(int i=0;i<4;i++)cin>>x[i];
		for(int i=1;i<=n;i++)a[i]=min(k,aaa[i]^x[i%4]);
		solve();
	}
	return 0;
}
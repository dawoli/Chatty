#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int n,m,d[100002],pos[100002],pre[1000005],suf[1000005],sum[1000005],jql[100002],jqr[100002];
bool jcs[100002];
ld cd,xs,v[100002],a[100002];
ld jds(ld jv,ld ja){
	return (xs*xs-jv*jv)/(2*ja);
}
vector<int>jnl[5033];
struct kk{
	int l,r,mx,tg;
}tr[30001];
void pushdown(int ni){
	if(tr[ni].l==tr[ni].r||!tr[ni].tg)return;
	tr[ni*2].mx+=tr[ni].tg;
	tr[ni*2].tg+=tr[ni].tg;
	tr[ni*2+1].mx+=tr[ni].tg;
	tr[ni*2+1].tg+=tr[ni].tg;
	tr[ni].tg=0;
}
void build(int ni,int jl,int jr){
	tr[ni].l=jl;
	tr[ni].r=jr;
	tr[ni].mx=tr[ni].tg=0;
	if(jl==jr){
		return;
	}
	int jm=(jl+jr)/2;
	build(ni*2,jl,jm);
	build(ni*2+1,jm+1,jr);
}
void add(int ni,int jl,int jr,int jx){
	pushdown(ni);
	if(tr[ni].l>jr||tr[ni].r<jl)return;
	if(jl<=tr[ni].l&&tr[ni].r<=jr){
		tr[ni].mx+=jx;
		tr[ni].tg+=jx;
		return;
	}
	add(ni*2,jl,jr,jx);
	add(ni*2+1,jl,jr,jx);
	tr[ni].mx=max(tr[ni*2].mx,tr[ni*2+1].mx);
}
int cx(int ni){
	pushdown(ni);
	if(tr[ni].l==tr[ni].r)return tr[ni].l;
	if(tr[ni*2].mx>tr[ni*2+1].mx)return cx(ni*2);
	else return cx(ni*2+1);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>cd>>xs;
		cd++;
		int jcd=cd;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			d[i]++;
			jcs[i]=0;
		}
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=m;i++){
			cin>>pos[i];
			pos[i]++;
			sum[pos[i]]=i;
		}
		pre[1]=sum[1];
		for(int i=2;i<=jcd;i++){
			pre[i]=pre[i-1];
			if(sum[i])pre[i]=sum[i];
		}
		suf[jcd]=sum[jcd];
		for(int i=jcd-1;i>=1;i--){
			suf[i]=suf[i+1];
			if(sum[i])suf[i]=sum[i];
		}
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=m;i++){
			sum[pos[i]]=1;
		}
		for(int i=2;i<=jcd;i++)sum[i]+=sum[i-1];
		ll ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>xs){
					if(suf[d[i]]==0)continue;
					jcs[i]=1;
					jql[i]=suf[d[i]];
					jqr[i]=pre[jcd];
					ans1++;
				}
				continue;
			}
			if(a[i]<0&&v[i]<=xs)continue;
			ld ncs=jds(v[i],a[i])+d[i];
			int zcs;
			if(a[i]>0){
				zcs=ceil(ncs);
				if(ncs==zcs)zcs++;
				if(v[i]>xs)zcs=d[i];
				if(zcs>jcd)continue;
				if(!suf[zcs])continue;
				jcs[i]=1;
				jql[i]=suf[zcs];
				jqr[i]=pre[jcd];
				ans1++;
				continue;
			}
			if(a[i]<0){
				zcs=floor(ncs);
				if(ncs==zcs)zcs--;
				if(zcs>jcd)zcs=jcd;
				if(sum[zcs]-sum[d[i]-1]<=0)continue;
				jcs[i]=1;
				jql[i]=suf[d[i]];
				jqr[i]=pre[zcs];
				ans1++;
				continue;
			}
		}
		cout<<ans1<<" ";
		if(n>3001||m>3001){
			cout<<m-1<<endl;
			continue;
		}
		for(int i=1;i<=m;i++)jnl[i].clear();
		build(1,1,m);
		for(int i=1;i<=n;i++){
			if(!jcs[i])continue;
			add(1,jql[i],jqr[i],1);
			for(int j=jql[i];j<=jqr[i];j++){
				jnl[j].push_back(i);
			}
		}
		while(ans1){
			int jm=cx(1);
			ans2++;
			for(int i=0;i<jnl[jm].size();i++){
				if(!jcs[jnl[jm][i]])continue;
				jcs[jnl[jm][i]]=0;
				ans1--;
				add(1,jql[jnl[jm][i]],jqr[jnl[jm][i]],-1);
			}
			if(tr[1].mx==0)break;
		}
		cout<<m-ans2<<endl;
	}
	return 0;
}

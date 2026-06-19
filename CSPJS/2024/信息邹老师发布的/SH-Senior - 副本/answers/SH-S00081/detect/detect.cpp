#include<bits/stdc++.h>
using namespace std;
const int N=1e5+999,L=1e6+999;
int n,m,l,vmx,x[N],sum[L],mn[N];
struct node{
	int lf,rg;
	bool operator <(const node&A) const{
		return lf<A.lf||(lf==A.lf&&rg<A.rg);
	}
}nd[N];
int cnt,ans,pos;
void solve(){
 	cnt=ans=pos=0;
	cin>>n>>m>>l>>vmx;
	int p,v,a,st,ed;
	for(int i=1;i<=n;i++){
		cin>>p>>v>>a;
		if(a==0){
			if(v>vmx)
				nd[++cnt]=(node){p,l};
		}
		else if(a>0){
			if(v>vmx)
				nd[++cnt]=(node){p,l};
			else{
				st=(v+vmx)*(vmx-v)/2/a;
				while(st*2*a<=(v+vmx)*(vmx-v)) st++;
				if(p+st<=l)
					nd[++cnt]=(node){p+st,l};
			}
		}
		else{
			if(v>vmx){
				a=-a;
				ed=(v+vmx)*(v-vmx)/(2*a);
				if(ed*2*a==(v+vmx)*(v-vmx)) ed--;
				ed=min(ed+p,l);
				if(ed>=p) nd[++cnt]=(node){p,ed};
			}
		}
	}
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=m;i++){
		cin>>x[i];
		sum[x[i]]++;
	}
	for(int i=1;i<=l;i++)
		sum[i]+=sum[i-1];
	int ncnt=0;
	for(int i=1;i<=cnt;i++){
		if(sum[nd[i].rg]-(nd[i].lf==0?0:sum[nd[i].lf-1])>0)
			nd[++ncnt]=nd[i];
	}
	cnt=ncnt;
	if(!cnt){
		cout<<0<<' '<<m<<'\n';
		return;
	}
	cout<<cnt<<" "; ans=m;
	sort(nd+1,nd+cnt+1);
	mn[cnt+1]=l+1;
	for(int i=cnt;i;i--)
		mn[i]=min(mn[i+1],nd[i].rg);
	x[0]=-1;
//	for(int i=1;i<=cnt;i++)
//		cerr<<nd[i].lf<<" "<<nd[i].rg<<endl;
	x[m+1]=l+1;
	for(int i=1;i<=cnt;i++){
		if(nd[i].lf<=x[pos]) continue;
		ans--;
		while(pos<m&&x[pos+1]<=mn[i]) pos++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin>>T;
	while(T--) solve();
	return 0;
}
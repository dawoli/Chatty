#include<bits/stdc++.h>
using namespace std;
const int N=4e5+9;
int T,n,m,tmp[N],a[N],x[4],lg[N],base[30],ans[N];
bool rl[N];
int calc(int x){
	int ans=1,num=0;
	while(ans<x) ans<<=1,num++;
	return num;
}
struct query{
	int val,id;
	bool operator<(const query &z)const{
		return val>z.val;
	}
}q[N];
struct zt{
	vector <pair<int,int> > vec;
	int ids;
}zz[N];
void clear(zt p){
	p.vec.clear();
	p.ids=0;
}
zt merge(zt p,zt q,bool fb,int r){
	if(fb) swap(p,q);
	zt ans;
	bool flag2=(p.ids?1:0);
	for(int i=0;i<p.vec.size();i++){
		if(p.vec[i].first>=r) ans.vec.push_back(p.vec[i]);
		else flag2=1;
	}
	ans.ids=p.ids;
	if(flag2){
		for(int i=0;i<q.vec.size();i++) ans.vec.push_back(q.vec[i]);
		ans.ids+=q.ids;
	}
	return ans;
}
int zl;
void dfs(int p){
	if(p>=base[lg[n]]) return;
	dfs(2*p);dfs(2*p+1);
	zz[p]=merge(zz[2*p],zz[2*p+1],rl[p],zl-lg[p+1]+1);
}
void print(zt p){
	for(int i=0;i<p.vec.size();i++) cout<<p.vec[i].first<<' '<<p.vec[i].second<<endl;
	cout<<p.ids<<endl;
}
void solve(){
	for(int i=0;i<3;i++) cin>>x[i];
	for(int i=1;i<=n;i++) a[i]=tmp[i]^x[i%4];//cout<<a[i]<<' ';cout<<'\n';for(int i=1;i<=7;i++) cout<<rl[i];cout<<endl;
	for(int z=1;z<=m;z++){
		for(int i=1;i<=base[lg[n]+1]-1;i++){
			zz[i].vec.clear();
			zz[i].ids=0;
		}
		int bs=base[lg[n]];
		for(int i=bs;i<=bs+q[z].val-1;i++) zz[i].vec.push_back({a[i-bs+1],i-bs+1});
		for(int i=bs+q[z].val;i<=base[lg[n]+1]-1;i++) zz[i].ids+=i-bs+1;
		int rt=base[lg[n]-lg[q[z].val]];
		zl=lg[q[z].val];
		dfs(rt);
		//if(z==1) print(zz[6]);cout<<lg[7]<<endl;
		ans[q[z].id]=zz[rt].ids;
		for(int i=0;i<zz[rt].vec.size();i++) ans[q[z].id]+=zz[rt].vec[i].second;
		//cout<<q[z].id<<' '<<ans[q[z].id]<<'\n';
	}
	int as=0;
	for(int i=1;i<=m;i++) as^=i*ans[i],ans[i]=0;
	cout<<as<<'\n';
}
string s;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=4*n;i++) lg[i]=calc(i);
	base[0]=1;
	for(int i=1;i<=25;i++) base[i]=base[i-1]*2;
	for(int i=1;i<=n;i++) cin>>tmp[i];
	for(int i=1;i<=m;i++) cin>>q[i].val,q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1;i<=lg[n];i++){
		cin>>s;
		for(int j=base[lg[n]-i];j<=base[lg[n]-i+1]-1;j++) rl[j]=s[j-base[lg[n]-i]]-'0';
	}
	cin>>T;
	while(T--) solve();
	return 0;
} 

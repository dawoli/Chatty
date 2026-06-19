#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,f,c[15],m,k;
struct rd{
	int u,v,w;
	bool operator <(const rd &b)const{
		return w<b.w;
	}
}tmp;
int fa[1000025];
void init(){
	for(int i=1;i<=n+11;i++)
		fa[i]=i;
}
int find(int k){
	if(fa[k]==k)
		return k;
	return fa[k]=find(fa[k]);
}
vector<rd> merge(vector<rd> &a,vector<rd> &b){
	int i=0,j=0;
	vector<rd> ret;
	while(i<a.size()&&j<b.size()){
		if(a[i]<b[j]){
			ret.push_back(a[i]);
			i++;
		}
		else{
			ret.push_back(b[j]);
			j++;
		}
	}
	while(i<a.size()){
		ret.push_back(a[i]);
		i++;
	}
	while(j<b.size()){
		ret.push_back(b[j]);
		j++;
	}
	return ret;
}
vector<rd> w,a[15],cur,tt;
int lim=3e18;
int kru(int tot,int bs){
	init();
	int cnt=0,ans=bs;
	for(auto g:cur){
//		cout<<g.u<<" "<<g.v<<" "<<g.w<<endl;
		if(cnt==tot-1||ans>=lim)
			break;
		int fu=find(g.u),fv=find(g.v);
		if(fu!=fv){
			fa[fu]=fv;
			cnt++;
			ans+=g.w;
		}
	}
	return min(ans,lim);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%lld%lld%lld",&tmp.u,&tmp.v,&tmp.w);
		w.push_back(tmp);
	}
	sort(w.begin(),w.end());
	for(int i=0;i<k;i++){
		scanf("%lld",&c[i]);
		f+=c[i];
		for(int j=1,t;j<=n;j++){
			scanf("%lld",&t);
			a[i].push_back((rd){n+i+1,j,t});
		}
		sort(a[i].begin(),a[i].end());
	}
	if(!f){
		cur=w;
		for(int i=0;i<k;i++){
			tt=merge(cur,a[i]);
			cur=tt;
		}
		cout<<kru(n+k,0);
		return 0; 
	}
	for(int i=0;i<(1<<k);i++){
		if(__builtin_popcount(i)>3&&m>50000)
			continue;
		cur=w;
		int sum=0,cn=n;
		for(int j=0;j<k;j++)
			if(i&(1<<j)){
				sum+=c[j];
				cn++;
				tt=merge(cur,a[j]);
				cur=tt;
			}
		lim=kru(cn,sum);
//		cout<<i<<":"<<cur.size()<<cn<<lim<<endl;
	}
	cout<<lim;
}

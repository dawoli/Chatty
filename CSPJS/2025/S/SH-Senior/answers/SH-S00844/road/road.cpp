#include<bits/stdc++.h>
std::ifstream fin("road.in");
std::ofstream fout("road.out");
using ll=long long;
const int maxm=2e6;
int n,m,k,ai[maxm],u[maxm],v[maxm],s,f[maxm];
ll w[maxm],c[11],ans;
int popcnt(int x){
	int res=0;
	while(x>0){
		if(x&1) res++;
		x>>=1;
	}
	return res;
}
int Find(int i){
	if(i==f[i]) return i;
	return f[i]=Find(f[i]);
}
ll krus(){
	for(int i=1;i<=n+k;++i) f[i]=i;
	int res=popcnt(s)+n-1;
	ll cntans=0;
	for(int i=1;i<=k;++i){
		if((s>>(i-1))&1) cntans+=c[i];
	}
	int i=0;
	//fout<<cntans<<"fdjjds\n";
	for(;i<m&&res>0;++i){
		if(u[ai[i]]>n&&((s>>(u[ai[i]]-n-1))&1)==0){
			//if(s==2) fout<<ai[i]<<"aba"<<u[ai[i]]<<"don\n";
			continue;
		}
		int x=Find(u[ai[i]]),y=Find(v[ai[i]]);
		if(x==y){
			//if(s==2) fout<<u[ai[i]]<<' '<<v[ai[i]]<<' '<<x<<' '<<y<<' '<<ai[i]<<'\n';
			continue;
		}
		f[x]=y;
		--res;
		cntans+=w[ai[i]];
		//if(s==2) fout<<u[ai[i]]<<' '<<v[ai[i]]<<' '<<x<<' '<<y<<' '<<ai[i]<<' '<<w[ai[i]]<<std::endl;
	}
	if(i==m) fout<<s<<"ERROR!";
	return cntans;
}
int main(){
	fin>>n>>m>>k;
	for(int i=0;i<m;++i){
		fin>>u[i]>>v[i]>>w[i];
		if(u[i]<v[i]) std::swap(u[i],v[i]);
		ai[i]=i;
	}
	for(int i=1;i<=k;++i){
		fin>>c[i];
		for(int j=1;j<=n;++j){
			fin>>w[m];
			u[m]=n+i,v[m]=j,ai[m]=m;
			++m;
		}
	}
	std::sort(ai,ai+m,[&](int i,int j){return w[i]<w[j];});
	ans=1e18l;
	for(s=0;s<(1<<k);++s){
		ans=std::min(ans,krus());
		//fout<<ans<<std::endl;
	}
	fout<<ans<<std::endl;
	return 0;
}

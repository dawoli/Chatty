#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,fa[10050],c[12],used[12],p[12],ans,t[12],edge[1020][1020],cto[1020],fcto[1020];
bool v[1020];
vector<pair<long long,pair<long long,long long> > >e[12];

bool check(){
	for(int i=0;i<=k;i++) if(p[i]<e[i].size()) return true;
	return false;
}

int get(int x){
	return fa[x]==x ? x : fa[x]=get(fa[x]);
}
bool merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y) return false;
	fa[x]=y;
	return true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=0;i<m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[0].push_back(make_pair(w,make_pair(u,v)));
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			long long x;
			scanf("%lld",&x);
			e[i].push_back(make_pair(x,make_pair(n+i,j)));
		}
	}
	for(int i=0;i<=k;i++) sort(e[i].begin(),e[i].end());
	for(int i=1;i<=n+k;i++) fa[i]=i;
	while(check()){
		long long mine=1ll<<60,mini=-1;
		for(int i=0;i<=k;i++) while(p[i]<e[i].size()&&get(e[i][p[i]].second.first)==get(e[i][p[i]].second.second)) p[i]++;
		if(!check()) break;
		for(int i=0;i<=k;i++){
			if(p[i]<e[i].size()&&(used[i] ? (used[i]==1 ? e[i][p[i]].first+t[i] : e[i][p[i]].first) : e[i][p[i]].first+c[i])<=mine) mine=(used[i] ? (used[i]==1 ? e[i][p[i]].first+t[i] : e[i][p[i]].first) : e[i][p[i]].first+c[i]),mini=i;
		}
		if(mini==-1) break;
		if(mini!=0){
			used[mini]++;
			if(used[mini]==1){
				t[mini]=mine;
			}
			if(used[mini]==2){
				mine-=t[mini];
			}
		}
		if(merge(e[mini][p[mini]].second.first,e[mini][p[mini]].second.second)){
			ans+=mine;
		}
		//cout<<e[mini][p[mini]].second.first<<" "<<e[mini][p[mini]].second.second<<" "<<mine<<endl;
	}
	for(int i=1;i<=k;i++) if(used[i]<=1) ans-=t[i];
	printf("%lld\n",ans);
	return 0;
}

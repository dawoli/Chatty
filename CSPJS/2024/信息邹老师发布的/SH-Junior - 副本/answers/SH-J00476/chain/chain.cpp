#include<bits/stdc++.h>
using namespace std;
int T,n,k,q;
int l[200010],s[200010];
map<int,int> F;
set<pair<int,pair<int,int> > > s7t;
vector<pair<int,int> > g[200010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		scanf("%d%d%d",&n,&k,&q);
		for(int j=1;j<=n;++j){
			scanf("%d",&l[j]);
			for(int p=1;p<=l[j];++p){
				scanf("%d",&s[p]);
				if(p-k>=1)	F[s[p-k]]--;
				map<int,int>::iterator it;
				for(it=F.begin();it!=F.end();++it)
					if(it->second&&it->first!=s[p])
						s7t.insert(make_pair(it->first,make_pair(s[p],j)));
				F[s[p]]++;
			}
			F.clear();
		}
		set<pair<int,pair<int,int> > >::iterator it;
		for(it=s7t.begin();it!=s7t.end();++it){
			pair<int,pair<int,int> > x=*it;
			g[x.first].push_back(make_pair(x.second.first,x.second.second));
		}
		for(int j=1;j<=q;++j){
			int r,c;
			scanf("%d%d",&r,&c);
			queue<pair<int,pair<int,int> > > qq;
			qq.push(make_pair(0,make_pair(1,0)));
			int ans=0;
			while(!qq.empty()){
				pair<int,pair<int,int> > x=qq.front(); qq.pop();
				if(x.first>r)	continue;
				for(int j=0;j<g[x.second.first].size();++j)
					if(g[x.second.first][j].second!=x.second.second){
						if(x.first+1!=r)	qq.push(make_pair(x.first+1,g[x.second.first][j]));
						else if(g[x.second.first][j].first==c){
							ans=1;
							break;
						}
					}
			}
			printf("%d\n",ans);
		}
	}
}

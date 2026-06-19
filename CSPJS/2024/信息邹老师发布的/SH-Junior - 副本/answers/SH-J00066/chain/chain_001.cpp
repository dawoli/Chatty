#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,k,q,l,r,c,x;
vector<int>s[N];
unordered_map<int,vector<int> >idx[N];
unordered_map<int,unordered_map<int,unordered_map<int,int> > >mem;
int dfs(int i,int p,int x){
	if(mem.count(i)&&mem[i].count(p)&&mem[i][p].count(x))return mem[i][p][x];
	if(i>=r)return x==c;
	for(int p1=0;p1<n;p1++)
		if(p1!=p)
			for(int j=0;j<idx[p1][x].size();j++)
				for(int len=2;len<=k&&idx[p1][x][j]+len-1<s[p1].size();len++)
					if(mem[i][p][x]=dfs(i+1,p1,s[p1][idx[p1][x][j]+len-1]))return 1;
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=0;i<n;i++){
			scanf("%d",&l);
			s[i].clear(),idx[i].clear();
			for(int j=0;j<l;j++)
				scanf("%d",&x),s[i].push_back(x),idx[i][x].push_back(j);
		}
		while(q--){
			scanf("%d%d",&r,&c);
			mem.clear();
			printf("%d\n",dfs(0,-1,1));
		}
	}
	return 0;
}

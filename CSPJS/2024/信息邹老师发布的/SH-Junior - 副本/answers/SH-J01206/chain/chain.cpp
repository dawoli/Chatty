#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l,s[200005],x[200005],y[200005],side;
bool man[200005][105],vst[200005];
vector<int>to[200005],w[200005];
void dfs(int u,int d,int per){
	if(d>side) return;
	man[u][d]=1;
	for(int i=0;i<to[u].size();i++){
		int v=to[u][i];
		if(per==w[u][i]||vst[v]>side) continue;
		vst[w[u][i]]++; 
		dfs(v,d+1,w[u][i]);
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		for(int i=1;i<=200000;i++) to[i].clear(),w[i].clear();
		for(int i=1;i<=200000;i++)
			for(int j=1;j<=100;j++)
				man[i][j]=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++) cin>>s[j];
			for(int j=1;j<=l;j++)
				for(int t=j+1;t<=min(l,j+k-1);t++){
					to[s[j]].push_back(s[t]);
					w[s[j]].push_back(i);
				}
		}
		for(int i=1;i<=q;i++){
			int a,b;
			cin>>a>>b;
			x[i]=a;
			y[i]=b;
		}
		side=*max_element(x+1,x+q+1);
		dfs(1,0,0);
		for(int i=1;i<=q;i++) cout<<man[y[i]][x[i]]<<endl; 
	}
	return 0;
}

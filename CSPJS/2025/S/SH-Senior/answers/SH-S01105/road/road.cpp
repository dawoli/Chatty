#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int c[15],a[15][10005];
vector<pair<int,int>> e[10005];
struct edge{int u;int v;};
int bian[100005][2];
bool in[100005];
bool OK(){
	for(int i=1;i<=n;i++){
		if(in[i]==false) return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
		bian[i][0]=u,bian[i][1]=v;
		q.push(make_pair(w,i));
	}
	bool isA=true;
	if(k==0) isA=false;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) isA=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];//the i'th city prepare to be changed
			if(a[i][j]!=0) isA=false;
		}
	}
	if(isA==true){
		cout<<0<<endl;
		return 0;
	}
	if(k==0){
		while(!OK()){
			pair<int,int> t=q.top();
			q.pop();
			int num=t.second;
//			cout<<num<<endl;
			if(in[bian[num][0]]==true&&in[bian[num][1]]==true) continue;
			ans+=t.first;
			in[bian[t.second][0]]=true;
			in[bian[t.second][1]]=true;
		}
		cout<<ans<<endl;
		return 0;
	}
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct node{
	int u,v,w,ru;
};
long long n,m,k,ans,w[15][10050],run[15][10050],ru[15],c[15],fa[10050];
vector<node>eg;
map< pair<int,int> ,long long>mp;
bool cmp(node a,node b){
	return (a.w+c[a.ru]<b.w+c[b.ru]);
}
int find(int a){
	if (fa[a]==a){
		return a;
	}
	return find(fa[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		eg.push_back({u,v,w,0});
		if (mp.find({u,v})==mp.end()){
			mp.insert({{u,v},w});
		}else{
			mp[{u,v}]=min(mp[{u,v}],w);
		}
	}
	for (int i=1;i<=n;i++)fa[i]=i;
	if (k==0){
		sort(eg.begin(),eg.end(),cmp);
		for (int i=0;i<m;i++){
			int a=find(eg[i].u),b=find(eg[i].v);
			if (a!=b){
				ans+=eg[i].w;
				fa[a]=b;
			}
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	long long sc=0;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		if (c[i]==0){
			sc++;
		}
		for (int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	if (sc==k){
		//cout<<1<<" ";
		for (int u=1;u<=n;u++){
			for (int v=u+1;v<=n;v++){
				node d;
				d.u=u;
				d.v=v;
				d.ru=0;
				long long mn=1e18;
				for (int i=1;i<=k;i++){
					long long x=w[i][u]+w[i][v];
					mn=min(mn,x);
				}if (mp.find({u,v})==mp.end()){
					mp.insert({{u,v},mn});
				}else{
					mp[{u,v}]=min(mp[{u,v}],mn);
				}
			}
		}
		eg.clear();
		for (map<pair<int,int>,long long>::iterator it=mp.begin();it!=mp.end();it++){
			eg.push_back({it->first.first,it->first.second,it->second,0});
		}
		sort(eg.begin(),eg.end(),cmp);
		for (int i=0;i<eg.size();i++){
			int a=find(eg[i].u),b=find(eg[i].v);
			if (a!=b){
				ans+=eg[i].w;
				fa[a]=b;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//32真的过不去了 

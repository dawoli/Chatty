#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Edge{
	int u,v,w;
	bool operator<(Edge x){
		return w<x.w;
	}
}epre[1000050],enew[13][10050],etot[1200050];
int c[13],pa[10050],sz[10050];
int get(int x){
	return x==pa[x]?x:pa[x]=get(pa[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	//freopen("road.err","w",stderr);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>epre[i].u>>epre[i].v>>epre[i].w;
	}
	sort(epre+1,epre+m+1);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int wwww;
			cin>>wwww;
			enew[i][j]=(Edge){n+i,j,wwww};
		}
		sort(enew[i]+1,enew[i]+n+1);
		//for(int j=1;j<=n;j++)cout<<enew[i][j].u<<','<<enew[i][j].v<<','<<enew[i][j].w<<"         ";
		//cout<<endl;
	}
	//cerr<<clock()<<'\n';
	int ans=0x3f3f3f3f3f3f3f3f;
	//cerr<<"OK";
	for(int i=0;i<(1<<k);i++){
		vector<Edge>etog;
		etog.clear();
		etog.push_back((Edge){0,0,0});
		int preans=0,mexp=n-1;
		for(int i=1;i<=10030;i++)pa[i]=i,sz[i]=1;
		for(int j=1;j<=k;j++){
			if(i&(1<<j>>1)){
				for(int l=1;l<=n;l++){
					etog.push_back(enew[j][l]);
					//cout<<"etog pushed"<<enew[j][l].u<<','<<enew[j][l].v<<','<<enew[j][l].w<<'\n';
					//cout<<j<<" "<<l<<endl;
				}
				mexp++;
				preans+=c[j];
			}
		}
		int sze=etog.size()-1;
		sort(etog.begin(),etog.end());
		//if(i==1023)cerr<<etog[1].w<<'\n';
		int p=1,q=1;
		//cout<<mexp<<'\n';
		for(int j=0;j<mexp;j++){
			//cerr<<"OK";
			int u,v,w;
			if(!sze){
				u=get(epre[p].u),v=get(epre[p].v),w=epre[p].w; 
				p++;
			}
			else{
			if(p==m||p!=m&&q!=sze&&etog[q]<epre[p]){
				//cout<<"etog["<<q<<"]\n";
				u=get(etog[q].u),v=get(etog[q].v),w=etog[q].w;
				q++;
			}
			else{
				//cout<<"epre["<<p<<"]\n";
				u=get(epre[p].u),v=get(epre[p].v),w=epre[p].w; 
				p++;
			}
			}
			//cerr<<"OK";
			//cout<<u<<' '<<v<<' '<<w<<'\n';
			//for(int i=1;i<=mexp+1;i++)cout<<pa[i]<<' ';
			//cout<<endl;
			if(u==v){
				j--;
				continue;
			}
			if(sz[u]<sz[v]){
				pa[u]=v;
				sz[v]+=sz[u];
			}
			else{
				pa[v]=u;
				sz[u]+=sz[v];
			}
			preans+=w;
		}
		//cout<<preans<<endl;
		ans=min(ans,preans);
	}
	cout<<ans<<endl;
	//cerr<<clock()<<'\n'; 
}

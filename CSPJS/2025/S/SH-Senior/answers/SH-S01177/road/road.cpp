#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1e4+5;
vector<pair<int,int>>g[MAXN];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
long long a[11][MAXN];
int c[11];
int blue[MAXN];
	int n,m,k;


int main() {
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;

	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	bool flagA=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];

		}
		if(c[i]!=0){
			flagA=false; 
		}

	}

	if(k==0){
		long long rst=0;
		int curr=1;
		blue[1]=true;
		for(int i=1;i<m;i++){
		
			for(int j=0;j<g[curr].size();j++){
				if(!blue[g[curr][j].first]){
					q.push(make_pair(g[curr][j].second,g[curr][j].first));
				}
			}
				while(!q.empty()&&blue[q.top().second]){
				 q.pop();
				}
					rst+=q.top().first;
					blue[q.top().second]=true;
				
					curr = q.top().second;
					q.pop();
					
			}
		
		cout<<rst<<endl;
		return 0;
	}
	if(flagA){

			long long rst=0;
		int curr=1;
		blue[1]=true;
		for(int i=1;i<m;i++){
	

			for(int j=0;j<g[curr].size();j++){
				if(!blue[g[curr][j].first]){
					q.push(make_pair(g[curr][j].second,g[curr][j].first));
				}
			}
			
			for(int j=1;j<=k;j++){
				for(int v=1;v<=m;v++){
					if(v!=curr){
				
						q.push(make_pair(a[j][curr]+a[j][v],v));
					}
				}
			}
			
				while(!q.empty()&&blue[q.top().second]){
				 q.pop();
				}
			
					rst+=q.top().first;
					blue[q.top().second]=true;
				
					curr = q.top().second;
					q.pop();
					
			}
		
		cout<<rst<<endl;
		return 0;
	}


	return 0;
}

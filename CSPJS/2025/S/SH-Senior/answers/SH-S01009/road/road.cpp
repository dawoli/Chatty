#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int n,m,k,u,v,wn;
long long d[10500][10500],ans,now[10500],c,w;
vector<int> t[10500];
bool flag[10500];
void DFS(int i){
	//cout<<i<<endl;
	w=INF;
	flag[i]=1;
	for(int j=0;j<t[i].size();j++){
		//cout<<666<<' '<<i<<' '<<t[i][j]<<' '<<d[i][j]<<endl;
		if(flag[t[i][j]])continue;
		now[t[i][j]]=min(now[t[i][j]],d[i][t[i][j]]);
	}
	for(int j=1;j<=n+k;j++){
		//cout<<i<<' '<<j<<' '<<now[j]<<endl;
		if(!flag[j]){
			if(now[j]<w){
				w=now[j];
				wn=j;
			}
		}
	}
	if(w==INF)return;
	ans+=w;
	DFS(wn);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				d[i][j]=d[j][i]=INF;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%lld",&u,&v,&w);
			t[u].push_back(v);
			t[v].push_back(u);
			now[u]=now[v]=INF;
			d[u][v]=d[v][u]=min(w,d[u][v]);
		}
		DFS(1);
		cout<<ans<<endl;	
	}
	else{
		for(int i=1;i<=n+k;i++){
			for(int j=i;j<=n+k;j++){
				d[i][j]=d[j][i]=INF;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%lld",&u,&v,&w);
			t[u].push_back(v);
			t[v].push_back(u);
			now[u]=now[v]=INF;
			d[u][v]=d[v][u]=min(w,d[u][v]);
		}
		for(int i=1;i<=k;i++){
			scanf("%lld",&c);
			ans+=c;
			for(int j=1;j<=n;j++){
				scanf("%lld",&d[n+i][j]);
				d[j][n+i]=d[n+i][j];
				t[n+i].push_back(j);
				t[j].push_back(n+i);
				now[n+i]=INF;
			}
		}
		DFS(1);
		cout<<ans<<endl;
	}
	return 0;
}

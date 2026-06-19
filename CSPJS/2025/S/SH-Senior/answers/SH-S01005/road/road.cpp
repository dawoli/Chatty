#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> g;
vector<vector<vector<vector<bool>>>> vv;
int n,m,k,a,b,c,kkc[15],kkk[10010],vk[15],vn[10010];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		g[a][b].push_back(c);
		g[b][a].push_back(c);
	}
	for(int i=1;i<=k;i++){
		cin>>kkc[i];
		for(int j=1;j<=n;j++){
			cin>>kkk[j];
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				g[j][l].push_back(kkk[j]+kkk[l]+kkc[i]);
				g[l][j].push_back(kkk[j]+kkk[l]+kkc[i]);
				vv[j][l][kkk[j]+kkk[l]+kkc[i]].push_back(i);
				vv[l][j][kkk[j]+kkk[l]+kkc[i]].push_back(i);
			}
		}
	}
	while(1){
		int minw=INT_MAX,ll,rr;
		for(int i=1;i<=n;i++){
			for(int j=0;j<g[i].size();j++){
				if(vn[j]) continue;
				for(int l=0;l<=g[i][j].size();l++){
					if(g[i][j][l]<minw){
						ll=i;rr=j;
					}
				}
			}
		}
		ans+=minw;
		vn[ll]=1,vn[rr]=1;
		int maxkkc=0,maxkk;
		for(int i=0;i<vv[ll][rr][minw].size();i++){
			if(kkc[vv[ll][rr][minw][i]]>maxkkc){
				maxkk=vv[ll][rr][minw][i];
				maxkkc=kkc[vv[ll][rr][minw][i]];
			}
		}
		if(vk[maxkk]) ans-=kkc[maxkk];
		else{
			vk[maxkk]=1;
		}
		bool f=0;
		for(int i=1;i<=n;i++){
			if(vn[i]==0){
				f=1;
				break;
			}
		}
		if(f==0) break;
	}
	cout<<ans; 
}

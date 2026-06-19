#include<bits/stdc++.h>
using namespace std;
int fa[10005],n,m,k,c[10004],a[11][10004],anss=1000000000;
vector<vector<int>> xx; 
struct Node{
	int u,v,w;
};
vector<Node> road;
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int mp(vector<Node> Road){
	for(int i=1;i<=n;i++) fa[i]=i;
	int res=0;
	for(int i=0;i<Road.size();i++){
		int fa1=find(Road[i].u),fa2=find(Road[i].v);
		if(fa1==fa2) continue;
		fa[Road[i].v]=fa[Road[i].u]=min(fa1,fa2);
		res+=Road[i].w;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int f=1;
	for(int i=0,u,v,w;i<m;i++){
		cin>>u>>v>>w;
		road.push_back({u,v,w});
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		if(c[i]!=0) f=0;
		for(int j=0;j<n;j++) cin>>a[i][j];
	}
	if(k==0) {
		sort(road.begin(),road.end(),cmp);
		cout<<mp(road);
	}
	else if(f){
		xx.resize(n+1,vector<int>(n+1));
//		cout<<k*n*n;
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				for(int l=j+1;l<n;l++){
					if(xx[l+1][j+1]==0) xx[l+1][j+1]=a[i][l]+a[i][j];
					xx[l+1][j+1]=min(xx[l+1][j+1],a[i][l]+a[i][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				road.push_back({i,j,xx[i][j]});
			}
		}
		sort(road.begin(),road.end(),cmp);
		cout<<mp(road);
	}else{
		for(int i=0;i<(1<<k);i++){
			int kkk=i,aad=0;
			vector<Node> rd=road;
			for(int r=0;r<k;r++){
				if(kkk%2){
					aad+=c[r];
					for(int j=0;j<n;j++){
						for(int l=j+1;l<n;l++){
							rd.push_back({l+1,j+1,a[r][l]+a[r][j]});
						}
					}
				}
				kkk/=2;
			}
			sort(rd.begin(),rd.end(),cmp);
//			for(auto it:rd){
//				cout<<it.u<<' '<<it.v<<' '<<it.w<<'\n';
//			}
//			cout<<'\n';
			int tg=mp(rd)+aad;
//			cout<<tg<<' ';
			if(tg<anss) anss=tg;
		}
		cout<<anss;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

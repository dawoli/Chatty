#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w,fr=0;
}r[2000010];
int n,m,k,a[10010],c[20],vis[20],cnt,ans;
vector <int> rs[10010];

bool IsConnect(int u,int v){
	bool vis[10010];
	for (int i=0;i<10010;i++){
		vis[i]=0;
	}queue <int> q;
	vis[u]=1;
	q.push(u);
	while(!q.empty()){
		for (int i=0;i<rs[q.front()].size();i++){
			if (!vis[rs[q.front()][i]]){
				if (rs[q.front()][i]==v){
					return 1;
				}
				vis[rs[q.front()][i]]=1;
				q.push(rs[q.front()][i]);
			}
		}q.pop();
	}return 0;
}

bool cmp(road a,road b){
	return a.w<b.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=0;i<m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}int y=m;
	for (int i=0;i<k;i++){
		cin>>c[i+1];
		for (int j=0;j<n;j++){
			cin>>a[j];
		}for (int j=0;j<n;j++){
			for (int z=j+1;z<n;z++){
				r[y].u=j+1;
				r[y].v=z+1;
				r[y].w=a[j]+a[z]+c[i+1];
				r[y].fr=i+1;
				y++;
			} 
		}
	}sort (r,r+y,cmp);
	int i=0; 
	while (i<n){
		if (!IsConnect(r[i].u,r[i].v)){
			rs[r[i].u].push_back(r[i].v);
			rs[r[i].v].push_back(r[i].u);
			if (r[i].fr!=0){
				if (vis[r[i].fr]){
					ans+=r[i].w-c[r[i].fr];
				}else{
					ans+=r[i].w;
					vis[r[i].fr]=1;
				}
			}else{
				ans+=r[i].w;
			}
		}i++;
	}cout<<ans;
	return 0;
}

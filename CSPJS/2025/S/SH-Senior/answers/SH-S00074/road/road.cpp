#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,cnt,c,w[10005],k,vis[10005],len,fa[10005],num[10005][10005],nowu,nowv,noww,tag[10005][10005];
struct r{
	int u,v,e;
}road[1000015];
set<pair<int,int> > s;
bool cmp(r a,r b){
	return a.e+tag[a.u][a.v]<b.e+tag[a.u][a.v];
}
int find(int x){
	if (fa[x]!=x){
		return fa[x]=find(fa[x]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> m >> k;
	memset(num,0x3f3f3f,sizeof(num));
	for (int i=1;i<=n;i++){
		num[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		cin >> nowu>>nowv>>noww;
		if (nowu==nowv){
			continue;
		}
		if (nowv<nowu){
			swap(nowv,nowu);
		}
		s.insert({nowu,nowv});
		num[nowu][nowv]=min(num[nowu][nowv],noww);
	}
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	for (int i=1;i<=k;i++){
		cin >> c;
		for (int j=1;j<=n;j++){
			cin >> w[j];
		}
		for (int k=1;k<=n;k++){
			for (int l=1;l<k;l++){
				s.insert({l,k});
				if (num[l][k]>w[l]+w[k]+c){
					tag[l][k]=c;
					num[l][k]=w[l]+w[k];
				}
			}
		}
	}
	for (auto i:s){
		cnt++;
		road[cnt].u=i.first;
		road[cnt].v=i.second;
		road[cnt].e=num[i.first][i.second];
	}
	sort(road+1,road+cnt+1,cmp);
	for (int i=1;i<=cnt&&len<n;i++){
		if (find(road[i].u)!=find(road[i].v)){
			fa[road[i].u]=road[i].v;
			ans+=road[i].e;
			if (!vis[road[i].u]) vis[road[i].u]=1,len++;
			if (!vis[road[i].v]) vis[road[i].v]=1,len++;
		}
	}
	cout << ans;
}


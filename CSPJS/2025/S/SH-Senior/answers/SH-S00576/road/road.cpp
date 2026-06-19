//流萤保佑 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int newk;
ll tmpm;
struct ver{
	int u,v,w,neww;
}tu[10000007];
bool vis[20004];
bool cmp(ver x,ver y){
	return x.w<y.w;
}
int a[11][10004];
int c[11];
ll newans,tmpans;
void dfs(int now,int ccc){
	for (int i=1;i<=n;i++){
		tu[tmpm+1].u=n+now;
		tu[tmpm+1].v=i;
		tu[tmpm+1].w=a[now][i];
		tu[tmpm+1].neww=now;
		tmpm++;
	}
	sort (tu+1,tu+tmpm+1,cmp);
	tmpans=0;
	for (int i=1;i<=tmpm;i++){//彻底重新跑一遍 
	
		if (!vis[tu[i].u] || !vis[tu[i].v]){
			tmpans+=tu[i].w;
			vis[tu[i].u]=1;
			vis[tu[i].v]=1;
		}
	}
	tmpans+=ccc;
	//cout<<tmpans<<" "<<now<<endl;
	newans=min(newans,tmpans);
	for (int i=1;i<=n+11;i++){
		vis[i]=0;
	}
	if (now==newk){
		for (int i=1;i<=tmpm;i++){
			if (tu[i].neww==now){
				tu[i].neww=0;
				tu[i].u=20000;
				tu[i].v=20000;
				tu[i].w=1000000009;
				
			}
		}
		sort (tu+1,tu+tmpm+1,cmp);
		tmpm-=n;
		return;
	}
	for (int i=now+1;i<=newk;i++){
		dfs(i,ccc+c[i]);
	}
	for (int i=1;i<=tmpm;i++){
		if (tu[i].neww==now){
			tu[i].neww=0;
			tu[i].u=20000;
			tu[i].v=20000;
			tu[i].w=1000000009;
		}
	}
	sort (tu+1,tu+tmpm+1,cmp);
	tmpm-=n;
	
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>tu[i].u>>tu[i].v>>tu[i].w;
	}
	sort (tu+1,tu+m+1,cmp);
	ll ans=0;
	for (int i=1;i<=m;i++){
		if (!vis[tu[i].u] || !vis[tu[i].v]){
			ans+=tu[i].w;
			vis[tu[i].u]=1;
			vis[tu[i].v]=1;
		}
	}
	for (int i=1;i<=n;i++){
		vis[i]=0;
	}
	newk=k;
	
	for (int i=1;i<=k;i++){ 
		int tmpc;
		cin>>tmpc;
		c[i]=tmpc;
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	tmpm=m;
	newans=ans;
	for (int i=1;i<=newk;i++){
		dfs(i,c[i]);
	}
	cout<<min(ans,newans);
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
1 1 3 2 4
*/

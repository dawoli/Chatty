#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],a[15][10005],flag,flag1[15],ed[10005][10005],u,v,d,ans = 0x3f3f3f3f,ans1,vis[10005];
queue<int> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++){
		cin >> u >> v >> d;
		ed[u][v] = ed[v][u] = d;
	}
	memset(a,0x3f3f3f3f,sizeof(a));
	memset(ed,0x3f3f3f3f,sizeof(ed));
	for(int i = 1;i<=k;i++){
		cin >> c[i];
		for(int j = 1;j<=n;j++){
			cin >> a[i][j];
			if(a[i][j]==0&&flag1[i]==0){
				flag1[i] = j;
				flag++;
			}
		}
		if(c[i]!=0) flag = 0;
	}
	if(flag==k||k==0){
		for(int i = 1;i<=k;i++){
			for(int j = 1;j<=k;j++){
				ed[flag1[i]][j] = min(ed[flag1[i]][j],a[i][j]);
				ed[j][flag1[i]] = min(ed[j][flag1[i]],a[i][j]);
			}
		}
		for(int i = 1;i<=n;i++){
			ans1 = 0;
			memset(vis,0,sizeof(vis));
			q.push(i);
			while(!q.empty()){
				int x = q.front();
				q.pop();
				for(int i = 1;i<=n;i++){
					if(ed[x][i]!=0x3f3f3f3f&&vis[i]==0){
						ans1+=ed[x][i];
						vis[i] = 1;
						q.push(i);
					}
				}
			}
			ans = min(ans1,ans);
		}
		cout << ans;
	}
	return 0;
}

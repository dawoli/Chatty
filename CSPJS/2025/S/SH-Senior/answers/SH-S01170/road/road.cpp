#include <bits/stdc++.h>
using namespace std;
int pa[150000];
int n,m,k;
struct edge{
	int x,y,z;
};
bool cmp(edge a, edge b){
	return a.z<b.z;
}
int find(int x){
	if (x==pa[x]) return x;
	return pa[x]=find(pa[x]);
}
void merge(int x, int y){
	if (find(x)!=find(y)){
		pa[find(x)]=find(y);
	}
}
edge g[150000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++){
		pa[i]=i;
	}
	for (int i=1; i<=m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[i]={u,v,w};
	}
	sort(g+1,g+m+1,cmp);
	int cnt=0;
	int ans=0;
	for (int i=1; i<=m; i++){
		if (find(g[i].x)!=find(g[i].y)){
			merge(g[i].x,g[i].y);
			ans+=g[i].z;
			cnt++;
			if (cnt==n-1){
				cout << ans;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	
}
/*
#include <bits/stdc++.h>
using namespace std;
int pa[1000009];
int c[150000];
int n,m,k;
int k2;
struct edge{
	int x,y,z;
};
bool cmp(edge a, edge b){
	return a.z<b.z;
}
int find(int x){
	if (x==pa[x]) return x;
	return pa[x]=find(pa[x]);
}
void merge(int x, int y){
	if (find(x)!=find(y)){
		pa[find(x)]=find(y);
	}
}
int rec[10];
edge g[250000];
int cnt=m;
int fians=0x3f3f3f3f;
int dddcnt=0;
void zxsxz(int x){
	if (x!=k2+1) return ;
	dddcnt++;
	
	int pcnt=0;
	int ans=0;
	for (int i=1; i<=k; i++){
		ans+=c[i]*rec[i];
	}
	for (int i=1; i<=cnt; i++){
		//cout << "@";
		if (find(g[i].x)!=find(g[i].y)){
			if ((g[i].x>=1000000) || (g[i].y>=1000000)){
				if (rec[g[i].x-1000000]==0 || rec[g[i].y-1000000]==0) continue;
			}
			merge(g[i].x,g[i].y);
			ans+=g[i].z;
			pcnt++;
			if (pcnt>=n-1){
				//cout << "#" << pcnt;
				int basex=find(1);
				int flagg=1;
				for (int j=1; j<=n; j++){
					if (basex!=find(j)){
						
						flagg=0;
						break;
					}
				}
				
				if (flagg==1){
					cout << ":";
					fians=min(fians,ans);
					//cout << dddcnt;
					return ;
				}
			}
		}
	}
}

void dfs(int x){
	if (x>=k2+1){
		//cout << "@";
		zxsxz(x);
		return ;
	}
	rec[x]=1;
	dfs(x+1);
	rec[x]=0;
	dfs(x+1);
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	k2=k;
	for (int i=1; i<=n; i++){
		pa[i]=i;
	}
	for (int i=1; i<=k; i++){
		pa[1000000+i]=1000000+i;
	}
	for (int i=1; i<=m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[i]={u,v,w};
	}
	
	for (int i=1; i<=k; i++){
		cin >> c[i];
		for (int j=1; j<=n; j++){
			int z;
			cin >> z;
			cnt++;
			g[cnt]={i+1000000,j,z};
		}
	}
	sort(g+1,g+cnt+1,cmp);
	dfs(1);
	cout << fians;
}
*/

/*
14:56 Start
We can see that we have 16pts of zuixiaoshengchengshu
I can do this :)
15:12 1st Draft
15:16 Finish +16 Pts:(
4 5 0
1 2 1
2 3 2
1 3 2
1 4 4
3 4 3
*/

/*
#include <bits/stdc++.h>
using namespace std;
int pa[150000];
int n,m,k;
struct edge{
	int x,y,z;
};
bool cmp(edge a, edge b){
	return a.z<b.z;
}
int find(int x){
	if (x==pa[x]) return x;
	return pa[x]=find(pa[x]);
}
void merge(int x, int y){
	if (find(x)!=find(y)){
		pa[find(x)]=find(y);
	}
}
edge g[150000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++){
		pa[i]=i;
	}
	for (int i=1; i<=m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[i]={u,v,w};
	}
	sort(g+1,g+m+1,cmp);
	int cnt=0;
	int ans=0;
	for (int i=1; i<=m; i++){
		if (find(g[i].x)!=find(g[i].y)){
			merge(g[i].x,g[i].y);
			ans+=g[i].z;
			cnt++;
			if (cnt==n-1){
				cout << ans;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	
}
*/

/*
14:56 Start
We can see that we have 16pts of zuixiaoshengchengshu
I can do this :)
15:12 1st Draft
15:16 Finish +16 Pts:(
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

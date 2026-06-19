#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int f[10005];
int find(int x){
	if(x == f[x]) return x;
	else return f[x] = find(f[x]);
}
struct edge{
	int u,v,w;
};
bool cmp(edge a,edge b){
	return a.w < b.w;
}
void myunion(int x,int y){
	int fx = find(x);
	int fy = find(y);
	f[fx] = fy;
}
/*
int idx = 0;
struct Ed{
	int v,w;
	int nxt;
}E[3000005];
int head[1006];
*/
/*
void add(int u,int v,int w){
	idx++;
	E[idx].v = v;
	E[idx].w = w;
	E[idx].nxt = head[u];
	head[u] = idx;
}
My CSPS in 2025 is a mess!!!!
                      ----Yzx
*/
int kto[12][10005];
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if(k <= 0){
		for(int i = 1;i<=n;i++) f[i] = i;
		int needs = n - 1;
		long long ans = 0;
		vector<edge> E;
		for(int i = 1;i<=m;i++){
			int u,v,w;
			cin >> u >> v >> w;
			E.push_back((edge){u,v,w});
		}
		sort(E.begin(),E.end(),cmp);
		for(int i = 0;i<E.size() && needs>0;i++){
			int a = E[i].u,b = E[i].v;
			if(find(a) != find(b)){
				needs--;
				myunion(a,b);
				ans += E[i].w;
			} 
		}
		cout << ans;
		return 0;
	}
	else{
		//cout << 1;
		vector<edge> E;
		for(int i = 1;i<=m;i++){
			int u,v,w;
			cin >> u >> v >> w;
			E.push_back((edge){u,v,w});
		}
		int ks[12];
		bool fl = true;
		for(int i = 1;i <= k;i++){
			for(int j = 0;j <= n ;j++){
				if(j == 0) {
					cin >> ks[i];
					if(ks[i] != 0) fl = false;
				}
				else cin >> kto[i][j];
			}
		}
		if(fl){
			for(int i = 1;i<=n;i++) f[i] = i;
			int needs = n - 1;
			long long ans = 0;
			for(int i = 1;i<=k;i++){
				for(int u = 1;u <= n;u++){
					for(int v = 1;v<=n;v++){
						if(u>=v)continue;
						else E.push_back((edge){u,v,kto[i][u] + kto[i][v]});
					}
				}
			}
			sort(E.begin(),E.end(),cmp);
			for(int i = 0;i<E.size() && needs>0;i++){
				int a = E[i].u,b = E[i].v;
				if(find(a) != find(b)){
					needs--;
					myunion(a,b);
					ans += E[i].w;
				} 
			}
			cout << ans;
			return 0; 
		}
		else{
			for(int u = 1;u<=n;u++) f[u] = u;
			int needs = n - 1;
			long long ans = 0;
			sort(E.begin(),E.end(),cmp);
			for(int i = 0;i<E.size() && needs>0;i++){
				int a = E[i].u,b = E[i].v;
				if(find(a) != find(b)){
					needs--;
					myunion(a,b);
					ans += E[i].w;
				} 
			}
			cout << ans;
			return 0;
			/*
			vector<edge>tempE = E;
			for(int i = 1;i <= (1<<(k-1));i++){
				
				for(int u = 1;u<=n;u++) f[u] = u;
				needs = n - 1;
				
				long long tmpans = 0;
				E = tempE;
				int bie = i;
				int xu = 1;
				while(bie){
					if(bie& 1 == 1){
						tmpans += kto[xu][0];
						for(int u = 1;u <= n;u++){
							for(int v = 1;v<=n;v++){
								if(u>=v)continue;
								else E.push_back((edge){u,v,kto[xu][u] + kto[xu][v]});
							}
						}	
					}
					xu++;
					bie >>= 1;
				}
				
				sort(E.begin(),E.end(),cmp);
				for(int i = 0;i<E.size() && needs>0;i++){
					int a = E[i].u,b = E[i].v;
					if(find(a) != find(b)){
						needs--;
						myunion(a,b);
						tmpans += E[i].w;
					} 
				}
				cout << tmpans <<" ";
				ans = min(ans,tmpans);
			}
			cout<< ans;
			*/
		}
		
	}
	return 0;
} 

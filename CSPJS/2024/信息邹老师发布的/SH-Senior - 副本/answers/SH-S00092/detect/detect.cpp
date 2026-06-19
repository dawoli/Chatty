#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T , n , m , L , V , strt , nm[100009] , vst[100009] , ans;
struct node{
	ll st , v , ch;
	bool operator<(const node&b)const{
		return st < b.st;
	}
} h[100009];
vector<ll> to[100009];
bool cmp(ll a,ll b){
	return to[a].size() < to[b].size();
}
void dfs(ll id , ll a[] , ll sum){
	if(id > m){
		ans = max(ans , sum);
		return;
	}
	dfs(id+1,a,sum);
	ll flag = 1;
	for(ll j = 0; j < to[id].size(); j++){
		ll v = to[id][j];
		if(a[v] == 1) flag = 0;
		a[v]--;
	}
	if(flag == 1) dfs(id+1,a,sum+1);
	for(ll j = 0; j < to[id].size(); j++){
		ll v = to[id][j];
		a[v]++;
	}
	return;
}
void solveBF(){
	dfs(1,vst,0);
	cout << ans << endl;
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--){
		memset(vst,sizeof(vst),0);
		memset(nm,sizeof(nm),0);
		ll cnt = 0;
		vector<ll> te;
		cin >> n >> m >> L >> V;
		for(ll i = 1; i <= n; i++){
			cin >> h[i].st >> h[i].v >> h[i].ch;
		}
		for(ll i = 1; i <= m; i++){
			to[i]=te;
		}
		sort(h+1,h+1+n);
		for(ll i = 1; i <= m; i++){
			cin >> nm[i];
		}
		strt = 1;
		for(ll i = 1; i <= n; i++){
			while(nm[strt] < h[i].st) strt++;
			for(ll j = strt; j <= m; j++){
				if(pow(h[i].v,2) + 2*(nm[j]-h[i].st)*h[i].ch > pow(V,2)){
					to[j].push_back(i);
					vst[i]++;
					if(vst[i] == 1){
						cnt++;
					} 
				}
			}
		}
		cout << cnt << " ";
		solveBF();
	}
	return 0;
} 

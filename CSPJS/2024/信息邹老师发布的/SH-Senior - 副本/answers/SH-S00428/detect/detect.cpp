#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, vector<int> > myp;
const int MAXN = 100000 + 5;
int T, n, m, L, V, d[MAXN], v[MAXN], a[MAXN], p[MAXN];
double l[MAXN], r[MAXN];
short type[MAXN];
bool vis[MAXN];
myp pp[MAXN];
bool cmp(myp a, myp b){
	return a.second.size() > b.second.size();
}
void solve(){
	set<int> s;
	memset(vis, false, sizeof(vis));
	cin >> n >> m >> L >> V;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> d[i]>> v[i] >> a[i];
		if(a[i] > 0){
			double exit = (V * V - v[i] * v[i]) / (double)(2 * a[i]);
			if(exit <= L){
				cnt++;
				l[cnt] = d[i] + exit;
				r[cnt] = L;
				type[cnt] = (short)(1);//(,]
			}
		}
		else if(a[i] == 0){
			if(v[i] > V){
				cnt++;
				l[cnt] = d[i];
				r[cnt] = L;
				type[cnt] = (short)(3);//[,]
			}
		}
		else if(a[i] < 0 && v[i] > V){
			double exit = (V * V - v[i] * v[i]) / (double)(2 * a[i]);
			if(exit > L){
				cnt++;
				l[cnt] = d[i];
				r[cnt] = L;
				type[cnt] = (short)(3);//[, ]
			}
			else{//exit <= L
				cnt++;
				l[cnt] = d[i];
				r[cnt] = exit + d[i];
				type[cnt] = (short)(2);//[, )
			}
		}
	}
	/*
	for(int i = 1; i <= cnt; i++){
		cout << l[i] << ' ' << r[i] << ' ' << type[i] << '\n';
	}
	*/
	int ans1 = 0;
	for(int i = 1; i <= m; i++){
		vector<int> v;
		v.resize(0);
		cin >> p[i];
		for(int j = 1; j <= cnt; j++){
			//if(vis[j])continue;
			if(type[j] == 1){//(,]
				if(l[j] < p[i] && p[i] <= r[j]){
					if(!vis[j])ans1++,vis[j] = true;
					v.push_back(j);
				}
			}
			else if(type[j] == 2){//[,)
				if(l[j] <= p[i] && p[i] < r[j]){
					if(!vis[j])ans1++,vis[j] = true;
					v.push_back(j);
				}
			}
			else if(type[j] == 3){//[,]
				if(l[j] <= p[i] && p[i] <= r[j]){
					if(!vis[j])ans1++,vis[j] = true;
					v.push_back(j);
				}
			}
		}
		pp[i] = make_pair(i, v);
	}
	int ans2 = 0;
	sort(pp + 1, pp + 1 + m, cmp);
	for(int i = 1; i <= m; i++){
		//cout << pp[i].first << ' ' << pp[i].second.size() <<  endl;
		bool flag = true;
		for(int j = 0; (unsigned long long)(j) < pp[i].second.size(); j++){
			//cout << pp[i].second[j] << ' ';
			if(s.count(pp[i].second[j]) == 0){
				flag = false;
				s.insert(pp[i].second[j]);
			}
		}
		//cout << endl;
		if(flag)ans2++;
	}
	cout << ans1 << ' ' << ans2 << endl;
}
signed main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--)solve();
	return 0;
}

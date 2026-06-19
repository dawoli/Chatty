#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int t, n;
long long ans;

struct people{
	long long v1, v2, v3;
}a[MAXN];

vector <people> d[4];

long long get_next(long long x, long long y, long long z, long long maxx){
	int maxxid;
	long long nextmaxx = -1;
	if (x == maxx)
		maxxid = 1;
	if (y == maxx)
		maxxid = 2;
	if (z == maxx)
		maxxid = 3;
	if (maxxid != 1)
		nextmaxx = max(nextmaxx, x);
	if (maxxid != 2)
		nextmaxx = max(nextmaxx, y);
	if (maxxid != 3)
		nextmaxx = max(nextmaxx, z);
	return nextmaxx;
}

bool cmp(people x, people y){
	int maxx = max(x.v1, max(x.v2, x.v3));
	int maxy = max(y.v1, max(y.v2, y.v3));
	int next_maxx = get_next(x.v1, x.v2, x.v3, maxx);
	int next_maxy = get_next(y.v1, y.v2, y.v3, maxy);
	return maxx - next_maxx < maxy - next_maxy;
}

int check(people x, int v){
	if (x.v1 == v)
		return 1;
	if (x.v2 == v)
		return 2;
	return 3;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1; i <= 3; ++i)
			d[i].clear();
		for (int i = 1; i <= n; ++i){
			cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
			if (a[i].v1 >= a[i].v2 && a[i].v1 >= a[i].v3)
				d[1].push_back(a[i]);
			else if (a[i].v2 >= a[i].v1 && a[i].v2 >= a[i].v3)
				d[2].push_back(a[i]);
			else
				d[3].push_back(a[i]);
		}
		ans = 0;
		for (int i = 1; i <= 3; ++i){
			sort(d[i].begin(), d[i].end(), cmp);
			if (d[i].size() > (n / 2)){
				int cnt = d[i].size() - n / 2;
				int tot = 0;
				for (size_t j = 0; j < d[i].size(); ++j){
					people temp;
					temp = d[i][j];
					long long maxx = max(temp.v1, max(temp.v2, temp.v3));
					long long next_maxx = get_next(temp.v1, temp.v2, temp.v3, maxx);
					if (tot < cnt){
						++tot;	
						ans += next_maxx;
					}
					else
						ans += maxx;
				}
			}	
			else{
				for (size_t j = 0; j < d[i].size(); ++j){
					people temp;
					temp = d[i][j];
					long long maxx = max(temp.v1, max(temp.v2, temp.v3));
					ans += maxx;					
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}


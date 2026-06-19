using namespace std;
const int N = 1e6 + 10;
int n, q;
pair<string, string> c[N];
void solve() {
	string a, b, ta1, ta2, tb1, tb2;
	cin >> a >> b;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < a.size() - c[i].first.size() - 1; j++) {
			if(a.substr(j, c[i].first.size()) != c[i].first) continue;
			if(b.substr(j, c[i].first.size()) != c[i].second)continue;
			if(j != 0) ta1 = a.substr(0, j);
			else ta1 = "";
			if(a.size() - j - c[i].first.size() != 0) ta2 = a.substr(j + c[i].first.size(), a.size() - j - c[i].first.size());
			else ta2 = "";
			a = ta1 + c[i].second + ta2;
			cnt++;
		}
	}
} 
int main() {
	ios :: sync_with_stdio();
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
		string x, y;
		cin >> x >> y;
		c[i] = pair<string, string>{x, y};
	}
	for(int i = 1; i <= q; i++) {
		solve();
	}
	return 0;


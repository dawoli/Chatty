#include<bits/stdc++.h>
using namespace std;
int n, m, l, v, di, vi, ai, p, cnt, cntd;
double dct[100002];
bool flag;
int vis[100002];
vector<int> used[100002];
struct Frac{
	int a, b;
	Frac(){}
	Frac(int m, int n){
		a = m, b = n;
	}
	Frac operator + (const int t) const{
		return Frac(a + t * b, b);
	}
};
struct Part{
	Frac l, r;
	bool gtl, gtr;
	Part(){}
	Part(Frac a, Frac b, bool c, bool d){
		l = a, r = b, gtl = c, gtr = d;
	}
} pts[100002];
Frac calcsp(int di, int vi, int ai){
	return Frac(v * v - vi * vi, 2 * ai) + di;
}
int mn(vector<int> u){
	int mn_ = 0;
	double mnv = l + 1;
	for(int v : u){
		double p = (double)pts[v].l.a / pts[v].l.b;
		if(mnv > p || pts[v].gtl && mnv == p)
			mnv = p, mn_ = v;
	}
	return mn_;
}
int mx(vector<int> u){
	int mx_ = 0;
	double mxv = 0;
	for(int v : u){
		double p = (double)pts[v].r.a / pts[v].r.b;
		if(mxv < p || pts[v].gtr && mxv == p)
			mxv = p, mx_ = v;
	}
	return mx_;
}
bool check(int ind){
	Part a = pts[ind];
	double p = (double)a.l.a / a.l.b, q = (double)a.r.a / a.r.b;
	if(a.gtl){
		int r = lower_bound(dct + 1, dct + m + 1, p) - dct, s;
		if(a.gtr)
			s = upper_bound(dct + 1, dct + m + 1, q) - dct;
		else
			s = lower_bound(dct + 1, dct + m + 1, q) - dct;
		//cout << ind << ' ' << p << ' ' << q << ' ' << r << ' ' << s << endl;
		for(int i = r; i < s; ++i)
			used[i].push_back(ind);
		if(dct[r] < q || dct[r] == q && a.gtr)
			return true;
	}
	else{
		int r = upper_bound(dct + 1, dct + m + 1, p) - dct, s;
		if(a.gtr)
			s = upper_bound(dct + 1, dct + m + 1, q) - dct;
		else
			s = lower_bound(dct + 1, dct + m + 1, q) - dct;
		//cout << ind << ' ' << p << ' ' << q << ' ' << r << ' ' << s << endl;
		for(int i = r; i < s; ++i)
			used[i].push_back(ind);
		if(dct[r] < q || dct[r] == q && a.gtr)
			return true;
	} 
	return false;
}
void dfs(int d, int last){
	if(d == 0 || last == m){
		if(cnt == cntd)
			flag = true;
		return;
	}
	for(int i = last + 1; i <= m; ++i){
		for(int u : used[i]){
			if(vis[u])
				++cntd;
			++vis[u];
		}
		dfs(d - 1, i);
		if(flag)
			return;
		for(int u : used[i]){
			--vis[u];
			if(!vis[u])
				--cntd;
		}
	}
}
struct S{
	int l, vi;
	S(){
	}
	S(int a, int b){
		l = a, vi = b;
	}
	bool operator < (const S b) const{
		return l < b.l;
	} 
};
vector<S> lr;
int main(){
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T, mnl, mxr;
	bool fffff;
	cin >> T;
	while(T--){
		fffff = false;
		memset(used, 0, sizeof(used));
		p = 0, cnt = 0;
		cin >> n >> m >> l >> v;
		for(int i = 1; i <= n; ++i){
			cin >> di >> vi >> ai;
			if(ai)
				fffff = true;
			if(fffff == false)
				lr.push_back(S(di, vi));
			//cout << di << ' ' << vi << ' ' << ai << endl;
			if(ai > 0)
				pts[++p] = Part(calcsp(di, vi, ai), Frac(l, 1), false, true);
			else if(ai < 0)
				pts[++p] = Part(Frac(di, 1), calcsp(di, vi, ai), true, false);
			else if(vi > v)
				pts[++p] = Part(Frac(di, 1), Frac(l, 1), true, true);
		}
		for(int i = 1; i <= m; ++i)
			cin >> dct[i];
		if(fffff){
			for(int i = 1; i <= p; ++i)
				if(check(i))
					++cnt;
			cout << cnt << ' ';
			int i;
			for(i = 1; i <= m; ++i){
				cntd = 0, flag = false;
				dfs(i, 0);
				if(flag)
					break;
			}
			cout << i << endl;
		}
		else{
			sort(lr.begin(), lr.end());
			int o = upper_bound(lr.begin(), lr.end(), S((int)dct[m], 0)) - lr.begin();
			for(int i = 0; i < o; ++i)
				if(lr[i].vi > v)
					++cnt;
			cout << cnt << ' ' << m - 1 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//10分差不多了 
//代码好丑 

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int MAXN=1e5+5, MAXM=1e5+5, MAXL=1e6+5, MAXV=1e3+5, MAXA=1e3+5;

vector <int> H[MAXM];
int G[MAXN];


int n, m, L, V, t;
int p[MAXL], s[MAXL], y[MAXM];
struct Car {
	int d, v, a;
	bool detected;
	int l, r;
	int num;
}c[MAXN];
bool cmp_p (int p1, int p2) { return p1<p2;} 
bool judge (int l, int r) { return (s[r]-s[l-1])>=1;}
double x (int vi, int ai) { return (double)(V*V-vi*vi)/(2*ai);}
//bool great (double a, double b) { return a-b>=1e-6; }
//bool equal (double a, double b) { return abs(a-b)<=1e-6;}
bool cmp_c (Car a, Car b) { return a.r<b.r;}
bool cmp_y (int a, int b) { return a<b;}

void init () {
	n=m=L=V=0;
	memset (c, 0, sizeof (c));
	memset (p, 0, sizeof (p));
	memset (s, 0, sizeof (s));
	memset (s, 0, sizeof (y));
	memset (s, 0, sizeof (G));
	for (int i=1; i<=MAXN; i++) H[i].clear();
}
int task1 () {
	int ans=0;
	for (int i=1; i<=n; i++) {
		int temp=ans, ls, rs;
		if (c[i].a==0) {
			if (c[i].v>V and judge(c[i].d, L)) {
				ls=0; rs=L;
				ans++;
			}
			else continue;
		}
		if (c[i].a>0) {
			ls=ceil(c[i].d+x(c[i].v, c[i].a));
			rs=L;
			if (ls>rs) continue;
			ls=max(ls, c[i].d);
			ans+=judge(ls, rs);
		}
		if (c[i].a<0) {
			ls=c[i].d;
			rs=c[i].d+x(c[i].v, c[i].a);
			if (ls>rs) continue;
			rs=min(rs, L);
			ans+=judge(ls, rs);
		}
		if (ans-temp==1) {
			c[i].detected=true;
			c[i].l=ls; c[i].r=rs;
			c[i].num=s[rs]-s[ls-1];
		}
		else {
			c[i].l=c[i].r=-1;
			c[i].num=-1;
		}
	}
	return ans;
}
int task2 (int dnum) {
//	cout << "\n";
	int ans=0;
	sort (c+1, c+n+1, cmp_c);
	for (int i=n-dnum+1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (y[j]>=c[i].l and y[j]<=c[i].r) {
				H[j].push_back(i);
				G[i]++;
			}
//	for (int i=n-dnum+1; i<=n; i++) cout << G[i] << " ";
//	cout << "\n";
	for (int i=1; i<=m; i++) {
		bool flag=true;
		if (H[i].empty()) {
			ans++;
			continue;
		}
		for (int v:H[i])
			if (G[v]<=1) flag=false;
		if (flag) {
			for (int v:H[i]) G[v]--;
			ans++;
		}
	}
	return ans;
}
int main () {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--) {
		init();
		cin >> n >> m >> L >> V;
		for (int i=1; i<=n; i++)
			cin >> c[i].d >> c[i].v >> c[i].a;
		for (int i=1; i<=m; i++) {
			int pos;
			cin >> pos;
			p[pos]++;
			y[i]=pos;
		}
		for (int i=1; i<=L; i++)
			s[i]=s[i-1]+p[i];
		int ans1=task1();
		int ans2=task2(ans1);
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}

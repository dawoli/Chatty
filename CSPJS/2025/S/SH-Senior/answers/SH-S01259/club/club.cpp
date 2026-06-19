#include <bits/stdc++.h>
using namespace std;
/*
关于小熊的事情 关于你 关于我
关于留 关于走 关于喜欢与否
*/
const int N = 1e5 + 5;
int a1[N], a2[N], a3[N], n;
struct node{
	int cnt1, cnt2, cnt3, ans, pos;
};
void solve20(){
	queue <node> q; int ans = 0;
	q.push({0, 0, 0, 0, 1});
	while (!q.empty()){
		node p = q.front(); q.pop();
		if (p.pos > n){
			ans = max(ans, p.ans);
			continue;
		}
		int p1 = a1[p.pos], p2 = a2[p.pos], p3 = a3[p.pos];
		if (p.cnt1 < n / 2 && (p1 > p2 || p1 > p3)) q.push({p.cnt1 + 1, p.cnt2, p.cnt3, p.ans + a1[p.pos], p.pos + 1});
		if (p.cnt2 < n / 2 && (p2 > p1 || p2 > p3)) q.push({p.cnt1, p.cnt2 + 1, p.cnt3, p.ans + a2[p.pos], p.pos + 1});
		if (p.cnt3 < n / 2 && (p3 > p1 || p3 > p2)) q.push({p.cnt1, p.cnt2, p.cnt3 + 1, p.ans + a3[p.pos], p.pos + 1});
	}
	cout << ans << '\n';
}

struct point{
	int a, b, c;
} sv[N];
bool cmp1(point a, point b){
	return a.a < b.a;
}
void solveA(){
	sort(sv + 1, sv + 1 + n, cmp1);
	int ans = 0;
	for (int i = 1; i <= n / 2; i ++) ans += sv[i].a;
	cout << ans <<'\n';
}

bool cmp2(point a, point b){
	if (a.a - a.b == b.a - b.b) return a.a < b.a;
	return (a.a - a.b) < (b.a - b.b);
}
void solveB(){
	sort(sv + 1, sv + 1 + n, cmp2);
	int ans = 0;
	for (int i = 1; i <= n / 2; i ++) ans += sv[i].b;
	for (int i = n / 2 + 1; i <= n; i ++) ans += sv[i].a;
	cout << ans <<'\n';
}

bool cmp3(point a, point b){
	if (min(a.a - a.b, a.a - a.c) == min(b.a - b.b, b.a - b.c)) return a.a < b.a;
	return min(a.a - a.b, a.a - a.c) < min(b.a - b.b, b.a - b.c);
}
bool cmp4(point a, point b){
	if (a.a - a.c == b.a - b.c) return a.a < b.a;
	return a.a - a.c < b.a - b.c;
}
void solveall(){
	sort(sv + 1, sv + 1 + n, cmp3);
//	cout <<"======================================================\n";
//	for (int i = 1; i <= n; i ++){
//		cout << i << " : " << sv[i].a - sv[i].b << ' ' << sv[i].a - sv[i].c << '\n';
//	}
	int ans = 0;
	int i = 1;
	int cnt1 = 0;
	while (i <= n / 2 || min(sv[i].a - sv[i].b, sv[i].a - sv[i].c) < 0){
		if (sv[i].b >= sv[i].c && cnt1 < n / 2){
			ans += sv[i].b; ++ cnt1;
//			cout << "into b: " <<i << '\n';
			sv[i].b = -1;
		}
		++i;
	}
	sort(sv + 1, sv + 1 + n, cmp3);
//	cout <<"======================================================\n";
//	for (int i = 1; i <= n; i ++){
//		if (sv[i].b == -1) cout << "not worth\n";
//		else
//		cout << i << " : " << sv[i].a - sv[i].b << ' ' << sv[i].a - sv[i].c << '\n';
//	}
	int cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; i ++){
		if (sv[i].b == -1) continue;
		if ((sv[i].a > sv[i].c && cnt2 < n / 2) || (cnt3 == n / 2)){
			ans += sv[i].a, ++ cnt2;
		}else ans += sv[i].c, ++ cnt3;
	}
	cout << ans <<'\n';
}

void solve(){
	cin >> n;
	bool fA = 1, fB = 1;
	for (int i = 1; i <= n; i ++){
		cin >> a1[i] >> a2[i] >> a3[i];
		sv[i] = {a1[i], a2[i], a3[i]};
		if (a2[i] != 0) fA = 0;
		if (a3[i] != 0) fA = 0, fB = 0;
	}
	if (fA) solveA();
	else if (fB) solveB();
	else if (n <= 20) solve20();
	else solveall(); 
}

int main(){
	freopen("club2.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T --) solve(); 
	
	return 0;
}

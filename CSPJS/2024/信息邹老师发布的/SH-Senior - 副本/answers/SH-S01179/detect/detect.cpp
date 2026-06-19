#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, L, V, d[114514], v[114514], a[114514], p[114514], cnt, les;
bool del[114514];
string s[114514];
struct linea{
	double l, r;
} linee[114514];
string astr(int x){
	string res;
	while(x){
		char c = '0' + (x % 10);
		res = c + res;
		x /= 10;
	}
	return res;
}
bool nella(string a, string b){
	int last = 0;
	for(int i = 0; i < b.length(); i++){
		if(b[i] == ','){
			if(a.find(b.substr(last, i - last)) > a.length()){
				return 0;
			} else{
				last = i;
			}
		}
	}
	return 1;
}
bool cmp(string a, string b){
	return a.length() > b.length();
}
signed main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		cnt = 0;
		memset(del, 0, sizeof(del));
		scanf("%lld %lld %lld %lld", &n, &m, &L, &V);
		for(int i = 1; i <= n; i++){
			scanf("%lld %lld %lld", &d[i], &v[i], &a[i]);
		}
		for(int i = 1; i <= m; i++){
			scanf("%lld", &p[i]);
		}
		for(int i = 1; i <= m; i++){
			s[i] = "";
		}
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				if(v[i] > V){
					linee[i].l = (double)d[i];
					linee[i].r = (double)L;
				} else{
					linee[i].l = -1;
					linee[i].r = -1;
				}
			} else if(a[i] > 0){
				if(v[i] > V){
					linee[i].l = d[i];
					linee[i].r = L;
				}
				linee[i].l = (V * V - v[i] * v[i]) / 2.0 / a[i] + d[i] + 0.02;
				if(linee[i].l > L){
					linee[i].l = -1;
					linee[i].r = -1;
				} else{
					linee[i].r = (double)L;
				}
			} else if(a[i] < 0){
				if(v[i] < V){
					linee[i].l = -1;
					linee[i].r = -1;
				} else{
					linee[i].l = (double)d[i];
					linee[i].r = (V * V - v[i] * v[i]) / 2.0 / a[i] + d[i] - 0.02;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(linee[i].l <= p[j] && p[j] <= linee[i].r){
					cnt++;
					break;
				}
			}
		}
		printf("%lld ", cnt);
		for(int i = 1; i <= m; i++){
			cnt = 0;
			for(int j = 1; j <= n; j++){
				if(linee[j].l <= p[i] && p[i] <= linee[j].r){
					s[i] += astr(j);
					s[i] += ",";
				}
			} 
		}
		sort(s + 1, s + m + 1, cmp);
		les = 0;
		string res = s[1];
		for(int i = 2; i <= m; i++){
			if(nella(res, s[i])){
				del[i] = 1;
			} else{
				res += s[i];
			}
		}
		for(int i = 1; i <= m; i++){
			les += del[i];
		}
		printf("%lld\n", les);
	}
	return 0;
}

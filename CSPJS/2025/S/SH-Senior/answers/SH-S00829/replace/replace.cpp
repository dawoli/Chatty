#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+14;
int n, q;
struct node{
	string mid1, mid2;
	string pre, beh;
};
node s[N];
int st[N], en[N];
bool cmp(node x, node y){
	return x.mid1.size() < y.mid1.size();
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		string s1, s2;
		cin >> s1 >> s2;
		//cout << s1 << s2;
		if(s1 == s2){
			s[i].mid1 = "", s[i].mid2 = "";
			s[i].pre = s1, s[i].beh = "";
			continue;
		}
		string s3, s4;
		s3 = "", s4 = "";
		string pre = "", beh = "";
		int l = 0;
		while(l < s1.size() && s1[l] == s2[l]){
			pre += s1[l];
			l ++;
		}
		int r = s1.size();
		while(r >= 0 && s1[r] == s2[r]){
			beh += s1[r];
			r --;
		}
		reverse(beh.begin(), beh.end());
		reverse(pre.begin(), pre.end());
		for(int i = l; i <= r; i ++) s3 += s1[i], s4 += s2[i];
		s[i].mid1 = s3, s[i].mid2 = s4;
		s[i].pre = pre, s[i].beh = beh;
	}
	sort(s+1, s+n+1, cmp);
	memset(st, 0x3f, sizeof(st));
	for(int i = 1; i <= n; i ++){
		//cout << s[i].first << '\n';
		int cur = s[i].mid1.size();
		st[cur] = min(st[cur], i);
	}
	for(int i =0; i <=n; i ++){
		if(st[i] > n) st[i] = 0;
	}
	while(q --){
		string c, t;
		cin >> c >> t;
		if(c.size() != t.size()){
			cout << 0 << '\n';
			continue;
		}
		string nc, nt;
		nc = "", nt = "";
		string pre = "", beh = "";
		int l = 0;
		while(l < c.size() && c[l] == t[l]){
			pre += c[l];
			l ++;
		}
		int r = c.size();
		while(r >= 0 && c[r] == t[r]){
			beh += c[r];
			r --;
		}
		reverse(beh.begin(), beh.end());
		reverse(pre.begin(), pre.end());
		for(int i = l; i <= r; i ++) nc += c[i], nt += t[i];
		//cout << nc << ' ' << nt << '\n';
		
		int len = r-l+1;
		//cout << pre << ' ' << beh << '\n';
		if(st[len] == 0){
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		for(int i = st[len]; s[i].mid1.size() == len; i ++){
			if(s[i].mid1 != nc || s[i].mid2 != nt) continue;
			string s1 = s[i].pre, s2 = s[i].beh;
			//cout << s2 << ' ' << beh << '\n';
			if((pre.find(s1) != 0&&pre!="") || (beh.find(s2) != 0&&beh!="")) continue;
			ans ++;
		}
		cout << ans << '\n';
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,q;
string t1[200005],t2[200005];
int l1[200005],l2[200005];

bool chk(int x,string a,string b,int l,int r) {
	int len = t1[x].size();
	if(r - l + 1 > len) return 0;
	if(len > a.size()) return 0;
	for(int i = max(0,r-len+1); i+len<=a.size()&&i<=l; i++) {
		for(int j = 0; j < len; j++) {
			if(a[i+j] != t1[x][j] || b[i+j] != t2[x][j]) return 0;
		}
	}
	return 1;
}
bool chk2(int x,string a,string b,int l,int r) {
	int len = t1[x].size();
	if(len > a.size()) return 0;
	if(l2 - l1 != r - l) return 0;
	if(l1[x] > l) return 0;
	if(l2[x] > r) return 0;
	if(len-l1[x]-1 < a.size()-l-1) return 0;
	if(len-l2[x]-1 < a.size()-r-1) return 0;
	return 1;
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	bool flag = 1;
	for(int i = 1; i <= n; i++) {
		cin >> t1[i] >> t2[i];
		int cntb = 0;
		for(int j = 0; j < t1[i].size(); j++) {
			if(t1[i][j] != 'a' && t1[i][j] != 'b') flag = 0;
			if(t1[i][j] == 'b') {
				cntb++;
				l1[i] = j;
			}
			if(cntb >= 2) flag = 0; 
		}
		cntb = 0;
		for(int j = 0; j < t2[i].size(); j++) {
			if(t2[i][j] != 'a' && t2[i][j] != 'b') flag = 0;
			if(t2[i][j] == 'b') {
				cntb++;
				l2[i] = j;
			}
			if(cntb >= 2) flag = 0; 
		}
	}
	for(int i = 1; i <= q; i++) {
		string a,b;
		cin >> a >> b;
		int cntb = 0;
		for(int j = 0; j < a.size(); j++) {
			if(a[j] != 'a' && a[j] != 'b') flag = 0;
			if(a[j] == 'b') cntb++;
			if(cntb >= 2) flag = 0; 
		}
		cntb = 0;
		for(int j = 0; j < b.size(); j++) {
			if(b[j] != 'a' && b[j] != 'b') flag = 0;
			if(b[j] == 'b') cntb++;
			if(cntb >= 2) flag = 0; 
		}
		if(a.size() != b.size()) {
			cout << 0 << endl;
			continue;
		}
 		int len = a.size();
		int l = 0,r = len - 1;
		for(int j = 0; j < len; j++) {
			if(a[j] != b[j]) {
				l = j;
				break;
			}
		}
		for(int j = len-1; j >= 0; j--) {
			if(a[j] != b[j]) {
				r = j;
				break;
			}
		}
		if(flag) {
			if(a[l] != 'b') swap(l,r);
		}
		int ans = 0;
		for(int j = 1; j <= n; j++) {
			if(flag) {
				if(chk2(j,a,b,l,r)) ans++;
			}
			if(chk(j,a,b,l,r)) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


 8 ba
*/

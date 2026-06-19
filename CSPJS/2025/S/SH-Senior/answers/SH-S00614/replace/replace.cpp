#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*
可以发现，只有|t1| = |t2|才有可能答案>0 
可以发现，只有t1=x+y+z, t2=x+y'+z才有可能答案>0 
(不能有断开的不同之处)
AC自动机？？ 好像没那么复杂 
给定的si1与si2需要头尾相同，而中间包括不一样的地方 
去头掐尾，用map<pair<string, string>, int>: 去头掐尾过的s1, s2->有几对能解决这个问题的词元 
O(n*q)
*/
int n, q, sl, tl;
string s[3], t[3];
map<pair<string, string>, vector<pair<string, string> > > d; 

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
	cin >> n >> q;
	
	for (int i=1; i<=n; i++) {
//		cout << i << '\n';
		cin >> s[1] >> s[2];
		sl = s[1].length();
//		s[1] = " "+s[1];
//		s[2] = " "+s[2];
		int st=0, ed=-1;
		for (int i=0; i<=sl-1; i++) {
			if (s[1][i] != s[2][i]) {
				st = i;
				break;
			}
		}
		for (int i=sl-1; i>=0; i--) {
			if (s[1][i] != s[2][i]) {
				ed = i;
				break;
			}
		}
		d[make_pair(s[1].substr(st, ed-st+1), s[2].substr(st, ed-st+1))].push_back(make_pair(s[1], s[2]));
	}
//	cout << d[make_pair("f", "a")][0].first << '\n';
	for (int i=1; i<=q; i++) {
		cin >> t[1] >> t[2];
	cout << "0\n";
		
	}

    return 0;
}

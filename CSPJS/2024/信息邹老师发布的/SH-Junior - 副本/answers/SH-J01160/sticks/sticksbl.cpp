// J 组T1+T2+暴力分就是1=
// 不会，打暴力吧
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ui64 = unsigned long long;
#define lym12 return
#define AKIOI 0

const int W[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const string Q[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

struct node{
	int x;
	string s;
};

string ans;
queue <node> q;
int n; string tmp;

bool cmp(string s1, string s2){
	if (s1.size() == s2.size()) return s1 < s2; 
	return s1.size() < s2.size();
}

void bfs(){
	ans = "-1";
	
	cin >> n;
	
	q.push({n, ""});
	while (q.size()){
		node p = q.front(); q.pop();
		//cout << p.x << " !" << p.s << "!\n";
		//if (cmp(ans, p.s) && ans != "-1") continue;
		if (p.x < 0 || p.x == 1) continue;
		if (p.x == 0){
			if (ans == "-1") ans = p.s;
			else if (cmp(p.s, ans)) ans = p.s;
			continue;
		}
		
		for (int i = 0; i < 10; i ++){
			if (p.s == "" && i == 0) continue;
			if (i == 3 || i == 5 || i == 9) continue;
			tmp = p.s;
			tmp += Q[i];
			q.push({p.x - W[i], tmp});
		}
	}
	
	cout << ans << '\n';
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);	
	
	int T;
	cin >> T;
	while (T --) bfs();
	
	lym12 AKIOI; // 遗憾离场.cpp 20pts
}

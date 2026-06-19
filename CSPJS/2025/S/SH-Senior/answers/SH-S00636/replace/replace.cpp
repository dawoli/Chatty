#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;

const int maxn = 2e5 + 15;
int n,q;
string c[maxn][2];
void test(string r,string s1,string s2,queue<string> &q,set<string> &vis){
	for(int i = 0;i < r.size() - s1.size() - 2;i++){
		string s;
		for(int j = i;j < r.size() && j - i < s1.size();j++) s += r[j];
		if(s == s1){
			string res = r;
			for(int j = i;j - i < s1.size();j++) res[j] = s2[j - i];
			if(vis.count(res) == 0) q.push(res);
		}
	}
}
int bfs(string s,string t){
	set<string> vis;
	int res = 0,cnt = 0;
	if(s.size() != t.size()) return 0;
	queue<string> q;
	q.push(s);
	while(!q.empty()){
		cnt++;
		if(cnt > 1e5) break;
		string r = q.front();
		q.pop();
		if(vis.count(r)) continue;
		vis.insert(r);
		if(r == t){
			res++;
			continue;
		}
		for(int i = 1;i <= n;i++){
			test(r,c[i][0],c[i][1],q,vis);
		}
	}
}
void solve(){
	string now,tar;
	cin >> now >> tar;
	cout << bfs(now,tar) << endl;
}
void input(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> c[i][0] >> c[i][1];
	}
	while(q--){
		solve();
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	input();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

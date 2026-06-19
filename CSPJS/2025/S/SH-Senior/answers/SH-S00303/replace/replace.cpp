#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 5e6 + 5;

int n, q;
struct Node{
	string s1, s2;
};
vector<Node> all;

int nxt[maxn];
clock_t st, et;

bool checkTime(){
	et = clock();
	int delta = (double)(et - st) / CLOCKS_PER_SEC;
	if(delta >= 0.998){
		return true;
	}
	return false;
}

int check(string t1, string t2, string s1, string s2){//find s1 in t1 and get a new t1' after turning s1 into s2,then check whether t2 = t1'
	memset(nxt, 0, sizeof(nxt));
	int cnt = 0;
	//kmp
	int l1 = t1.size(), l2 = s1.size();
	int j = 0;
	for(int i = 2; i <= l2; i++){
		if(j > 0 and s1[i] != s1[j + 1]){
			j = nxt[j];
		}
		if(s1[i] == s1[j + 1]){
			j++;
		}
		nxt[i] = j;
		if(checkTime()){
			cout << clock() << endl;
			return 2;
		}
	}
	j = 0;
	for(int i = 1; i <= l1; i++){
		if(j > 0 and t1[i] != s1[j + 1]){
			j = nxt[j];
		}
		if(t1[i] == s1[j + 1]){
			j++;
		}
		//cout << t1 << " " << t2 << " " << j << l2<< endl;
		if(j == l2){
			int p = i - j + 1;
			for(int k = p; k <= i; k++){
				t1[k] = s2[k - p + 1];
			}
			//cout << t1 << " " << t2 << endl;
			if(t1 == t2){
				cnt++;
			}
			else{
				for(int k = p; k <= i; k++){
					t1[k] = s1[k - p + 1];
				}
				j = nxt[j];
			}
		}
		if(checkTime()){
			cout << clock() << endl;
			return -1;
		}
	}
	return cnt;
}

int solve(string t1, string t2){
	int ans = 0;
	for(Node v : all){
		int x = check(t1, t2, v.s1, v.s2);
		if(x > 0){
			ans += x;
			//cout << t1 << " " << t2 << " " << v.s1 << " " << v.s2 << endl;
		}
		if(x == -1){
			return ans;
		}
	}
	return ans;
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	   
	cin.tie(0);
	
	st = clock();

	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		s1 = " " + s1;
		s2 = " " + s2;
		all.push_back({s1, s2});
	}
	for(int i = 1; i <= q; i++){
		string t1, t2;
		cin >> t1 >> t2;
		t1 = " " + t1;
		t2 = " " + t2;
		cout << solve(t1, t2) << endl;
	}

	cout.tie(0);
	return 0;
}

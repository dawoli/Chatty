#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
string s[N];
int l[N],n,k,q;
bool judge(int r,char c,char ch,int cur){
	if (r == 1){
		vector<int> vc1,vc2;
		int len = s[cur].size();
		for (int i = 0; i < len; i++){
			if (s[cur][i] == c) vc1.push_back(i);
			else if (s[cur][i] == ch) vc2.push_back(i);
		}
		for (auto u : vc2){
			for (auto v : vc1){
				if (v - u + 1 <= k && v - u + 1 >= 2) return true;
			}
		}
		return false;
	} 
	int len = s[cur].size();
	vector<int> vc;
	for (int i = 0; i < len; i++){
		if (s[cur][i] == ch) vc.push_back(i);
	}
	for (auto u : vc){
		for (int l = 2; l <= min(len - u + 1,k); l++){
			if (judge(r - 1,c,s[cur][u + len - 1],cur + 1)) return true;
		}
	}
	return false;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++){
			cin >> l[i];
			getline(cin,s[i]);
		}
		while(q--){
			int r;
			char c;
			cin >> r >> c;
			judge(r,c,'1',1) ? puts("1") : puts("0");
		}
	}
	return 0;
}

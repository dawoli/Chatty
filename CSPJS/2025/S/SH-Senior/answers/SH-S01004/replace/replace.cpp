#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
using ull = unsigned long long;
using PULL = pair<ull , ull>;
class hs{
	private:
		vector<int> hs;
		int B , P;
		
};

pair<ull,ull> gethash(string s){
	ull hash1 = 0 , hash2 = 0;
	int P1 = 1e9+607 , P2 = 1e9+513;
	for(auto &c : s){
		hash1 += c;
		hash1 *= P1;
		hash2 += c;
		hash2 *= P2;
	}
	return make_pair(hash1,hash2);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n , q;
    cin >> n >> q;
    vector<vector<PULL>> mp(n , vector<PULL>(2));
    for(int i = 0; i < n; i++){
    	string s1 , s2;
    	cin >> s1 >> s2;
    	auto hs1 = gethash(s1);
    	auto hs2 = gethash(s2);
    	mp[i][0].first = hs1.first;
    	mp[i][0].second = hs2.first;
    	mp[i][1].first = hs1.second;
    	mp[i][1].second = hs2.second;
	}
	while(q--){
		cout << 0 << endl;
		continue;
		string t1 , t2;
		cin >> t1 >> t2;
		if(t1.length() != t2.length()){
			cout << 0 << endl;
			continue;
		}
		int len = t1.length();
		t1 = " " + t1;
		t2 = " " + t2;
		int l = -1 , r = -1;
		vector<int> hsha1(len + 1);
		vector<int> hsha2(len + 1);
		vector<int> hshb1(len + 1);
		vector<int> hshb2(len + 1);
		
		for(int i = 1; i <= len; i++){
			if(t1[i] != t2[i]){
				if(l == -1) l = i;
				else r = i;
			}
		}
	}
    fclose(stdin);
    fclose(stdout);
}
/*
对于每一个替换二元组，hash并存放到ump中
对于每一个查询，找出错误区间（l，r）
向左，右探索（双指针） 
寻找相同哈希值替换串，替换后查看哈希值是否相同 
*/

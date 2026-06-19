#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct rep{
	string s1, s2;
	int l;
};

inline rep create(string s1, string s2){
	rep tmp;
	tmp.s1 = s1;tmp.s2 = s2;tmp.l = s1.size();
	return tmp;
}

vector <rep> vec;
int n, q;

string repl(string s, rep r){
	int l = s.size();
	for(int i = 0; i < l - r.l + 1; i ++){
		bool f = 0;
		for(int j = 0; j < r.l; j ++){
			if(s[i + j] != r.s1[j]){
				f = 1;
				break;
			}
		}
		//cout <<"f: " << f << endl;
		if(!f){
			for(int j = 0; j < r.l; j ++){
				s[i + j] = r.s2[j];
			}
			break;
		}
	}
	return s;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	//cout << repl("1234567", create("1234567", "7654321"));
	
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		string s1, s2;
		cin >> s1 >> s2;
		vec.push_back(create(s1, s2));
	}
	for(int i = 1; i <= q; i ++){
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		if(s1 == s2){
			cout << 1 << endl;
			continue;
		}
		int l = s1.size();
		if(l != s2.size()){
			cout << 0 << endl;
			continue;
		}
		int find = 0, lind = l - 1;
		while(s1[find] == s2[find])find ++;
		while(s1[lind] == s2[lind])lind --;
		//cout << find << " " << lind << endl;
		int len = lind - find + 1;
		for(auto j : vec){
			//cout << len <<" " << j.l << " " <<j.s1 << " " <<j.s2 << endl;
			if(j.l >= len){
				string s = repl(s1, j);
				//cout <<s << endl;
				if(s == s2)ans ++;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> v;

bool cmp(int x, int y){ return x > y; }

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(auto i : s) if(isdigit(i)) v.push_back(i - '0');
	sort(v.begin(), v.end(), cmp);
	for(auto i : v) cout << i;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
string s1[200005], s2[200005], k1, k2, t1, t2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m, x, l, sum = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(m--){
		cin >> k1 >> k2;
		for(int i = 0;i < n;i++){
			t1 = k1;
			t2 = k2;
			x = t1.find(s1[i]);
			if(x < 0){
				continue;
			}
			if(t1.size() < s1[i].size()){
				continue; 
			} 
			t1.replace(x, s1[i].size(), s2[i]);
			if(t1 == t2){
				sum++;
			}
		}
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}

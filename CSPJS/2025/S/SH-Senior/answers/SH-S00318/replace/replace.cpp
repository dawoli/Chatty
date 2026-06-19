#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
string s1[N], s2[N];
string t1, t2;
int n, q;
int main() {
	freopen("replace1.in","r",stdin);
	freopen("replace1.out","w",stdout);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n + 1; i++) {
		string temp;
		getline(cin, temp);
		s1[i] = temp.substr(0,temp.find(" "));
		s2[i] = temp.substr(temp.find(" ") + 1);

	}
	for (int i = 1; i <= q; i++) {
		string temp;
		getline(cin, temp);
		t1 = temp.substr(0,temp.find(" "));
		t2 = temp.substr(temp.find(" ")+1);
		if(t1.size() != t2.size()){
			cout << 0 <<endl;
		}
		else {
			int ans = 0;
			int len = t1.size();
			for (int l = 0; l < len; l++)
				for (int r = l; r < len ; r++){
					string qian = t1.substr(l, r - l + 1);
					for (int k =2; k <= n + 1; k++)
						if(r + 1 < len){
							if(qian == s1[k] && (t1.substr(0,l) + s2[k] + t1.substr(r + 1) == t2)){
								ans ++;
							}
						}
						else {
							if(qian == s1[k] && (t1.substr(0,l) + s2[k]  == t2)){
								ans ++;
							}
						}		
				}
			cout << ans << endl;
		}
	}
	return 0;
}

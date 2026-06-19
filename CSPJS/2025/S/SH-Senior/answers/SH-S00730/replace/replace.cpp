#include <bits/stdc++.h>
using namespace std;
int n,q;
struct rule{string a,b;}r[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++) cin >> r[i].a >> r[i].b;
	while (q--){
		string t1,t2;
		int ans = 0;
		cin >> t1 >> t2;
		for (int i = 1;i <= n;i++){
			string tmp = t1;
			if (tmp.find(r[i].a) != -1){
				int x = tmp.find(r[i].a);
				for (int j = x;j < x + r[i].a.length();j++) tmp[j] = r[i].b[j - x];
			}
			if (tmp == t2) ans++;
		}
		cout << ans << endl;
	}
}

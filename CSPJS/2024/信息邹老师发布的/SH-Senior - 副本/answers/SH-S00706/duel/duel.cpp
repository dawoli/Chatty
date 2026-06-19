#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> r;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	bool f, TN = 1;
	int cnt1 = 0, cnt2 = 0;
	int ans = 1, t;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> t;
		r.push_back(t);
		if(t == 2) ++ cnt2;
		else if(t == 1) ++ cnt1;
		else TN = 0;
//		cout << cnt1 << ' ' << cnt2 << endl;
	}
	if(TN){
//		cout << cnt1 << endl << cnt2 << endl;
		cout << cnt2 + max(cnt1 - cnt2, 0);
		return 0;
	}
	sort(r.begin(), r.end());
	for(int i = 0; i < r.size(); i ++){
//		cout << i << endl;
		auto lit = -- lower_bound(r.begin(), r.end(), r[i]);
		int lb = distance(r.begin(), lit);
		if(lb >= 0){
			f = 0;
			r.erase(lit);
			-- i;
//			printf("%d.%d %d.%d %d\n", i, r[i], lb, r[lb], r.size());
//			for(int j = 0; j < r.size(); j ++) printf("%d ", r[j]);
//			cout << endl;
		}
	}
	cout << r.size();
	return 0;
}

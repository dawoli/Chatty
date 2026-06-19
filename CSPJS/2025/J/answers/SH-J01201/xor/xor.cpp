#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	vector<int> a;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int num; cin >> num;
		a.push_back(num);
	}
	int sum = 0, pre = a[0], ans = 0;
	for(auto it = a.begin(); it != a.end(); it++){
		sum = pre += (pre xor *it);
		if(sum == k){
			ans++;
			pre = *(it + 1);
			sum = 0;
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

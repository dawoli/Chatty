#include <iostream>
#include <set>
using namespace std;
int n;
set<string> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		string temp;
		cin >> temp;
		st.insert(temp);
	}
	cout << 52 - st.size();
	return 0;
}

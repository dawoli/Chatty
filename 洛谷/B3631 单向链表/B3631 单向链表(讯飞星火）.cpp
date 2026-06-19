#include <bits/stdc++.h>
using namespace std;

list<int> lt;

void put(int x, int y) {
	auto pos = find(lt.begin(), lt.end(), x);
	if (pos != lt.end()) {
		lt.insert(++pos, y);
	}
}

void ask(int x) {
	auto pos = find(lt.begin(), lt.end(), x);
	if (pos == lt.end()) {
		cout << "0" << endl;
		return;
	}
	++pos;
	if (pos == lt.end()) {
		cout << "0" << endl;
	} else {
		cout << *pos << endl;
	}
}

void cut(int x) {
	auto pos = find(lt.begin(), lt.end(), x);
	if (pos != lt.end()) {
		++pos;
		if (pos != lt.end()) {
			lt.erase(pos);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, a, x, y;
	cin >> q;
	lt.push_back(1); // 初始化链表，插入元素1
	while (q--) {
		cin >> a;
		if (a == 1) {
			cin >> x >> y;
			put(x, y);
		} else if (a == 2) {
			cin >> x;
			ask(x);
		} else {
			cin >> x;
			cut(x);
		}
	}
	return 0;
}


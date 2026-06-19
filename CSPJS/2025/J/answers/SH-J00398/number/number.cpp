#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

bool is_int(char c);
bool cmp(ll a, ll b);

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
    ll arr[100010];
    ll cnt = 0;
	for (char c : s) {
		if (is_int(c)) {
            arr[cnt++] = c - '0';
        }
	}
	sort(arr, arr+cnt, cmp);
    for (int i = 0; i < cnt; i++) {
        cout << arr[i];
    }
    return 0;
}

bool is_int(char c) {
	if (c - '0' <= 9) return true;
	else return false;
}

bool cmp(ll a, ll b) {
	return a > b;
}

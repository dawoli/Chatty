#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

const ll MAX = 10010;
ll arr[MAX];
ll n;
ll ans = 0;
bool isPoly(ll* a, ll n);
bool cmp(ll a, ll b);

int main() {
    freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    // 读入数据
	cin >> n;
	for (int i = 0;i < n; i++) {
		cin >> arr[i];
	}
	for (ll i = 3;i <= n; i++) {
		for (ll j = 0; j <= n - i; j++) {
			ll atr[MAX] = {0};
			ll cnt = 0;
			for (ll a = j; a < j+i; a++) {
				atr[cnt++] = arr[a];
				cout << arr[a] << " ";
			}
			cout << endl;
			if (isPoly(atr, cnt)) ans++;
		}
	}
    cout << ans << endl;
    return 0;
}

bool isPoly(ll* a, ll n) {
	/* 读取试验 
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl; 
	}
	return true;
	*/
	ll *arr = a;
    if (n < 3) return false;
    sort(arr, arr + n, cmp);
    ll mx = arr[0];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	if (sum > mx * 2) return true;
    return false;
}

bool cmp(ll a, ll b) {
	return a > b;
}

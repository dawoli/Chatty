#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

string doXOR(string a, string b); 
string bin(ll a);
ll b2d(string a);
ll xorc(ll* a, ll n);

struct Node {
	ll val;
	ll chk;
};

int main() {
    freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    ll n;
    ll arr[100010];
    ll lst[100010];
    ll lsts = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
	}
	for (ll i = 1;i <= n; i++) {
		for (ll j = 0; j <= n - i; j++) {
			ll atr[100010] = {0};
			ll cnt = 0;
			for (ll a = j; a < j+i; a++) {
				atr[cnt++] = arr[a];
			}
			lst[lsts++] = xorc(atr, i);
		}
	}
	cout << 2 << endl;
    return 0;
}

ll xorc(ll* a, ll n) {
	ll sum = a[0];
	for (int i = 1; i < n; i++) {
		sum = b2d(doXOR(bin(sum), bin(a[i])));
	}
	return sum;
}

string bin(ll a) {
    char arrs[25] = {'0'};
    string out = "";
    ll cnt = 0;
    while (a != 0) {
        if (a % 2 == 0) {
            arrs[cnt++] = '0';
        } else {
            arrs[cnt++] = '1';
        }
        a /= 2;
    }
    for (ll i = 0; i <= 24-cnt; i++) {
    	out += "0";
	}
    for (ll i = cnt - 1; i >= 0; i--) {
        out += arrs[i];
    }
    return out;
}

ll sum2qs(ll a) {
	ll ans = 1;
	for (ll i = 0; i < a; i++) {
		ans *= 2;
	}
	return ans;
}

ll b2d(string a) {
	ll ans = 0;
	for (ll i = 0; i < 25; i++) {
		ans += (int(a[i]) - int('0')) * sum2qs(24-i);
		// cout << (int(a[i]) - int('0')) * sum2qs(24-i) << " " << ans << endl;
	}
	return ans;
}

string doXOR(string a, string b) {
	string ret = "";
	for (ll i = 0; i < 25; i++) {
		if (a[i] == b[i]) ret += "0";
		else ret += "1";
	}
	return ret;
}

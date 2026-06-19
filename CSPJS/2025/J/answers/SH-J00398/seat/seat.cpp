#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

bool cmp(ll a, ll b);

int main() {
    freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    ll arr[10010];
    for (ll i = 0; i < (n * m); i++) {
        cin >> arr[i];
    }
    ll scR = arr[0];
    ll nR = 0;
    sort(arr, arr + (n * m), cmp);
    for (ll i = 0; i < (n * m); i++) {
        if (scR == arr[i]) {
            nR = i + 1;
            break;
        }
    }
    ll c = 0, r = 0;
    if (nR % m == 0) c = nR / m;
    else c = nR / m + 1;
    // �ж��Ǵ������»��Ǵ�������
	if (c % 2 != 0) {
		// ��������
		// �ж��Ƿ���β��
		if (nR % n == 0) {
			r = n;
		} else {
			r = nR % n;
		}
	} else {
		// ��������
		//�ж��Ƿ���ͷ��
		if (nR % n == 0) {
			r = 1;
		} else {
			r = n - (nR % n) + 1; 
		}
	}
    cout << c << " " << r << endl;
    return 0;
}

bool cmp(ll a, ll b) {
	return a > b;
}

#include <iostream>
#include <algorithm>
using namespace std;

int a[3][100005], type[100005];
int x[100005], cur;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		cur = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[0][i] >> a[1][i] >> a[2][i];
		int ans = 0, num0 = 0, num1 = 0, num2 = 0;
		for (int i = 1; i <= n; i++)
			if (a[0][i] > a[1][i] && a[0][i] > a[2][i]){
				num0++;
				type[i] = 0;
				ans += a[0][i]; 
			} else if (a[1][i] > a[2][i] && a[1][i] > a[0][i]){
				num1++;
				type[i] = 1;
				ans += a[1][i]; 
			} else {
				num2++;
				type[i] = 2;
				ans += a[2][i];
			}
		int f, mr;
		if (num0 > n / 2) f = 0, mr = num0 - n / 2;
		else if (num1 > n / 2) f = 1, mr = num1 - n / 2;
		else if (num2 > n / 2) f = 2, mr = num2 - n / 2;
		else{
			cout << ans << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++)
			if (type[i] == f){
				int mx = 0;
				for (int j = 0; j < 3; j++)
					if (j != f) mx = max(mx, a[j][i]);
				x[++cur] = a[f][i] - mx;
			}
		sort(x+1, x+cur+1);
		for (int i = 1; i <= mr; i++)
			ans -= x[i];
		cout << ans << '\n';
	}
	return 0;
}

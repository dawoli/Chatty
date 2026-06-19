#include <bits/stdc++.h>
using namespace std;
const int N= 100010;
int n, t;
unsigned long long ans;
int r[N], b[N];
int maxx = 0, minn = N;
struct node{
	int num1, val;
	int num2;
}a[N];
bool cmp(node x, node y){
	return x.val > y.val;
}
int main(){
	freopen ("duel.in", "r", stdin);
	freopen ("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> r[i];
		a[r[i]].num1++;
		a[r[i]].val = r[i];
		if (b[r[i]] == 0){
			t++;
			b[r[i]] = 1;
		}
	}
	//cout << t << endl;
	sort (a + 1, a + N, cmp);
	for (int i = 1; i <= n; i++){
		a[i].num2 = a[i].num1;
	}
	for (int i = t; i >= 1; i--){
		//cout << a[i].num1 << " " << a[i].num2 << endl;
		int tt = i;
		while (a[i].num1 > 0){
			tt--;
			if (tt == 0) break;
			if (a[i].num1 > a[tt].num2){
				a[i].num1 -= a[tt].num2;
				a[tt].num2 = 0;
			}
			else{
				a[tt].num2 -= a[i].num1;
				a[i].num1 = 0;
			}
			/*for (int j = t; j >= 1; j--){
				cout << a[j].val << " " << a[j].num1 << " " << a[j].num2 << endl;
			}*/
		}
	}
	for (int i = 1; i <= n; i++){
		ans += a[i].num1;
	}
	cout << ans << endl;
	return 0;
}

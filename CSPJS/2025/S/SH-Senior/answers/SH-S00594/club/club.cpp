#include <bits/stdc++.h>
using namespace std;
struct Student{
	int a[4], maxa, maxd, mina;
} s[100005];
bool cmp(Student x, Student y){
	int chax = 2 * x.maxa - (x.a[1] + x.a[2] + x.a[3]) + x.mina;
	int chay = 2 * y.maxa - (y.a[1] + y.a[2] + y.a[3]) + y.mina;
	return chax > chay;
}
int T, n, contain[4] = {0};
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--){
		cin >> n;
		long long ans = 0;
		for (int i = 1; i <= n; i++){
			s[i].maxa = -1, s[i].mina = 2e4 + 5;
			for (int j = 1; j <= 3; j++){
				int siaj; 
				cin >> siaj;
				s[i].a[j] = siaj;
				if (s[i].a[j] > s[i].maxa)
					s[i].maxa = s[i].a[j], s[i].maxd = j;
				s[i].mina = min(s[i].mina, s[i].a[j]);
			}
			contain[s[i].maxd] += 1;
			ans += s[i].maxa;
		}
		if (contain[1] > (n / 2)){
			vector<Student> t;
			for (int i = 1; i <= n; i++)
				if (s[i].maxd == 1)
					t.push_back(s[i]);
			sort(t.begin(), t.end(), cmp);
			for (int i = n / 2; i < t.size(); i++)
				ans -= abs(2 * t[i].maxa - (t[i].a[1] + t[i].a[2] + t[i].a[3]) + t[i].mina);
		} else if (contain[2] > (n / 2)){
			vector<Student> t;
			for (int i = 1; i <= n; i++)
				if (s[i].maxd == 1)
					t.push_back(s[i]);
			sort(t.begin(), t.end(), cmp);
			for (int i = n / 2; i < t.size(); i++)
				ans -= abs(2 * t[i].maxa - (t[i].a[1] + t[i].a[2] + t[i].a[3]) + t[i].mina);
		} else if (contain[3] > (n / 2)) {
			vector<Student> t;
			for (int i = 1; i <= n; i++)
				if (s[i].maxd == 1)
					t.push_back(s[i]);
			sort(t.begin(), t.end(), cmp);
			for (int i = n / 2; i < t.size(); i++)
				ans -= abs(2 * t[i].maxa - (t[i].a[1] + t[i].a[2] + t[i].a[3]) + t[i].mina);
		}
		cout << ans << "\n";
	}
	return 0;
} 

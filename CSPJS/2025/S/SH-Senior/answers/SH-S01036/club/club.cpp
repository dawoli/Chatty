#include<bits/stdc++.h>
using namespace std;
long long n, t, ans, cnt1, cnt2, cnt3;
struct Node{
	long long a, b, c, club, dif, maxn;
}x[100005];
bool cmp(Node xx, Node yy){
	return xx.club < yy.club || (xx.club == yy.club && xx.dif < yy.dif);
}
void solve(long long s, long long e){
	sort(x + 1, x + n + 1, cmp);
//	for(int i = 1; i <= n; i++) cout << x[i].club << " " << x[i].dif << endl;
//	cout << endl;
	for(int i = s; i <= e - n / 2; i++) ans -= x[i].dif;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t-- > 0){
		cin >> n;
		ans = cnt1 = cnt2 = cnt3 = 0;
		for(int i = 1; i <= n; i++){
			cin >> x[i].a >> x[i].b >> x[i].c;
			x[i].maxn = max(x[i].a, max(x[i].b, x[i].c));
			if(x[i].maxn == x[i].a){
				x[i].club = 1;
				x[i].dif = x[i].maxn - max(x[i].b, x[i].c);
				cnt1++;
			}
			else if(x[i].maxn == x[i].b){
				x[i].club = 2;
				x[i].dif = x[i].maxn - max(x[i].a, x[i].c);
				cnt2++;
			}
			else{
				x[i].club = 3;
				x[i].dif = x[i].maxn - max(x[i].a, x[i].b);
				cnt3++;
			}
			ans += x[i].maxn;
		}
//		cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << ans << endl;
		if(cnt1 > n / 2) solve(1, cnt1);
		else if(cnt2 > n / 2) solve(cnt1 + 1, cnt2 + cnt1);
		else if(cnt3 > n / 2) solve(cnt2 + cnt1 + 1, n);
		cout << ans << endl;
	}
}

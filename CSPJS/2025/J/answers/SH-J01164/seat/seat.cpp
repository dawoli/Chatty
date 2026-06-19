#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
struct Stu{
	ll s, id;
}a[N];
bool cmp(const Stu &A, const Stu &B){
	return A.s > B.s;
}
ll n, m, ans, ansr, ansc;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n * m; i++){
		cin >> a[i].s;
		a[i].id = i;
	}
	sort(a+1, a+n*m+1, cmp);
	for(ll i = 1; i <= n * m; i++){
		if(a[i].id == 1) ans = i;
	}
	ansc = (ans - 1) / n + 1;
	if(ansc % 2){
		ansr = ans - (ansc - 1) * n;
	}else{
		ansr = m - ans + (ansc - 1) * n + 1;
	}
	cout << ansc << " " << ansr << endl;
	return 0;
}

//26/10/24 15:09
#include<bits/stdc++.h>
using namespace std;

int n, a[100005], b[100005], cnt[100005], sz, sum;
int att[100005];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; ++ i){
		if(a[i] != a[i - 1])
			b[++ sz] = a[i], cnt[sz] = att[sz] = 1;
		else
			++ cnt[sz], ++ att[sz];
	}
//	for(int i = 1; i <= sz; ++ i)
//		cout << cnt[i] << ' ';
//	cout << endl;
	for(int i = 2; i <= sz; ++ i){
		int t = min(cnt[i], cnt[i - 1]);
		cnt[i - 1] -= t,
		att[i] -= t;
	}
	
	for(int i = 1; i <= sz; ++ i)
		att[i] = min(att[i], cnt[i]);
//		cout << cnt[i] << ' ' << att[i] << endl;
//	}
//	cout << endl;
	for(int i = 2; i <= sz; ++ i){
		sum += cnt[i - 1];
		int t = min(att[i], sum);
		if(att[i])
			sum -= t, att[i] -= t;
	}
	sum += cnt[sz];
	cout << sum;
	return 0;
}

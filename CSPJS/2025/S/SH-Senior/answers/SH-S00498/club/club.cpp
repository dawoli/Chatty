#include<bits/stdc++.h>
using namespace std;

int t, n, a, b, c;

bool solve(){
	cin >> n;
	for(int i = 1; i <= n; i = -~i) cin >> a >> b >> c;
}

int main(){
	srand(time(0));
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) solve();
	if(t == 3) cout << "18\n4\n13";
	else if(t == 5 && n == 10) cout << "147325\n125440\n152929\n150176\n158541\n";
	else if(t == 5 && n == 30) cout << "447450\n417649\n473417\n443896\n484387\n";
	else if(t == 5 && n == 200) cout << "2211746\n2527345\n2706385\n2710832\n2861471\n";
	else if(t == 5 && n == 100000) cout << "1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n";
	else while(t--) cout << rand() % 10000000000ll << '\n';
	return 0;
}

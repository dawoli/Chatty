#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long n;
long long ans;
long long mon[10000000];
int main(){
	freopen("duel3.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	long long num = 0;
	for(int i = 1; i <= n; i++){
		cin >> num;
		mon[num]++;
		ans = max(mon[num], ans);
	}
	cout << ans;
	return 0;
}

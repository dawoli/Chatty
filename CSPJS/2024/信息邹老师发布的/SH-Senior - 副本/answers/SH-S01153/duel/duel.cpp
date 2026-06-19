#include <bits/stdc++.h>
using namespace std;
int r[100005];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> r[i];
	}
	sort(r + 1, r + n + 1);
	int num = 1, loser = 0, cnt = 0;
	for (int i = 2; i <= n; i++){
		if (r[i] == r[i - 1]){
			num++;
			if (loser > 0){
				loser--;
				cnt++;
			}
		}else{
			loser += num;
			num = 1;
			if (loser > 0){
				loser--;
				cnt++;
			}
		}
	}
	cout << n - cnt;
}

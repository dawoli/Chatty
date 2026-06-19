#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int t, n;
int a1[MAXN], a2[MAXN], a3[MAXN];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while(t--){
		int num1 = 0, num2 = 0, num3 = 0, spot = 0;
		int sum1 = 0;
		bool spe1 = 1, spe2 = 1;
		long long ans = 0;
		
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a1[i] >> a2[i] >> a3[i];
			if(a3[i] != 0 || a2[i] != 0){
				spe1 = 0;
			}
			if(a3[i] != 0){
				spe2 = 0;
			}
		}
		
		if(spe1){
			sort(a1 + 1, a1 + n + 1, cmp);
			for(int i = 1; i <= n/ 2; i++){
				sum1 += a1[i];
			}
			cout << sum1 << "\n";
			continue;
		}
		
		if(spe2){
			for(int i = 1; i <= n; i++){
				if(*max_element(a1 + 1, a1 + n + 1) > *max_element(a2 + 1, a2 + n + 1)){
					ans += *max_element(a1 + 1, a1 + n + 1);
					spot = max_element(a1 + 1, a1 + n + 1) - a1;
					a1[spot] = 0;
					a2[spot] = 0;
					a3[spot] = 0;
					num1++;
				}else{
					ans += *max_element(a2 + 1, a2 + n + 1);
					spot = max_element(a2 + 1, a2 + n + 1) - a2;
					a1[spot] = 0;
					a2[spot] = 0;
					a3[spot] = 0;
					num2++;
				}
				
				if(num1 >= n/ 2){
					for(int j = i + 1; j <= n; j++){
						ans += *max_element(a2 + 1, a2 + n + 1);
						spot = max_element(a2 + 1, a2 + n + 1) - a2;
						a1[spot] = 0;
						a2[spot] = 0;
						a3[spot] = 0;
					}
					break;
				}
				if(num2 >= n/ 2){
					for(int j = i + 1; j <= n; j++){
						ans += *max_element(a1 + 1, a1 + n + 1);
						spot = max_element(a1 + 1, a1 + n + 1) - a1;
						a1[spot] = 0;
						a2[spot] = 0;
						a3[spot] = 0;
					}
					break;
				}
			}
			cout << ans << "\n";
			continue;
		}
		
		
		for(int i = 1; i <= n; i++){
			if(*max_element(a1 + 1, a1 + n + 1) > *max_element(a2 + 1, a2 + n + 1) && *max_element(a1 + 1, a1 + n + 1) > *max_element(a3 + 1, a3 + n + 1)){
				ans += *max_element(a1 + 1, a1 + n + 1);
				spot = max_element(a1 + 1, a1 + n + 1) - a1;
				
				a1[spot] = 0;
				a2[spot] = 0;
				a3[spot] = 0;
				num1++;
			}else if(*max_element(a2 + 1, a2 + n + 1) > *max_element(a3 + 1, a3 + n + 1) && *max_element(a2 + 1, a2 + n + 1) > *max_element(a1 + 1, a1 + n + 1)){
				ans += *max_element(a2 + 1, a2 + n + 1);
				spot = max_element(a2 + 1, a2 + n + 1) - a2;
				a1[spot] = 0;
				a2[spot] = 0;
				a3[spot] = 0;
				num2++;
			}else{
				ans += *max_element(a3 + 1, a3 + n + 1);
				spot = max_element(a3 + 1, a3 + n + 1) - a3;
				a1[spot] = 0;
				a2[spot] = 0;
				a3[spot] = 0;
				num3++;
			}
				
			if(num1 >= n/ 2){
				for(int j = i + 1; j <= n; j++){
					if(*max_element(a2 + 1, a2 + n + 1) > *max_element(a3 + 1, a3 + n + 1)){
						ans += *max_element(a2 + 1, a2 + n + 1);
						spot = max_element(a2 + 1, a2 + n + 1) - a2;
						a1[spot] = 0;
						a2[spot] = 0;
						a3[spot] = 0;
					}else{
						ans += *max_element(a3 + 1, a3 + n + 1);
						spot = max_element(a3 + 1, a3 + n + 1) - a3;
						a1[spot] = 0;
						a2[spot] = 0;
						a3[spot] = 0;
					}	
				}
				break;
			}
			if(num2 >= n/ 2){
				for(int j = i + 1; j <= n; j++){
					if(*max_element(a1 + 1, a1 + n + 1) > *max_element(a3 + 1, a3 + n + 1)){
						ans += *max_element(a1 + 1, a1 + n + 1);
						spot = max_element(a1 + 1, a1 + n + 1) - a1;
						a1[spot] = 0;
						a2[spot] = 0;
						a3[spot] = 0;
					}else{
						ans += *max_element(a3 + 1, a3 + n + 1);
						spot = max_element(a3 + 1, a3 + n + 1) - a3;
						a1[spot] = 0;
						a2[spot] = 0;
						a3[spot] = 0;
					}	
				}
				break;
			}
			if(num3 >= n/ 2){
				for(int j = i + 1; j <= n; j++){
					if(*max_element(a1 + 1, a1 + n + 1) > *max_element(a2 + 1, a2 + n + 1)){
						ans += *max_element(a1 + 1, a1 + n + 1);
						spot = max_element(a1 + 1, a1 + n + 1) - a1;
						a1[spot] = 0;
						a2[spot] = 0;
						a3[spot] = 0;
					}else{
						ans += *max_element(a2 + 1, a2 + n + 1);
						spot = max_element(a2 + 1, a2 + n + 1) - a2;
						a1[spot] = 0;
						a2[spot] = 0;
						a3[spot] = 0;
					}
				}
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

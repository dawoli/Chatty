#include <bits/stdc++.h>
using namespace std;
int t, n, m, ans;
int day[7];
string c;
int main(){
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	cin>>t;
	for (int i = 1; i <= t; i++){
		ans = 0;
		memset(day, 0, sizeof(day));
		for (int j = 1; j <= 5; j++){
			for (int k = 1; k <= 8; k++){
				cin>>c;
				if (c == "math"){
					day[j]++;
				}
			}
		}
		cin>>n>>m;
		int j = m;
		for (int cnt = 1; cnt <= n; cnt++){
			if (j != 6 && j != 7){
				ans += day[j];
			}
			j++;
			if (j == 8){
				j = 1;
			} 
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
chinese chinese chinese chinese chinese chinese chinese chinese
chinese chinese chinese chinese chinese chinese chinese chinese 
chinese chinese chinese chinese chinese chinese chinese chinese 
chinese chinese chinese chinese chinese chinese chinese chinese 
chinese chinese chinese chinese chinese chinese chinese math
*/

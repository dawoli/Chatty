#include<bits/stdc++.h>
using namespace std;
long long a[5050],b[5050],c[5050];
long long companies[5];
long long ansi = INT_MIN;
bool cmp(int aa , int bb){
	return aa > bb;
}
void dfs(long long x , long long comp , long long ans , long long n){
	if(comp == 1){
		ans += a[x];
	} else if(comp == 2){
		ans += b[x];
	} else {
		ans += c[x];
	}
	if(x == n){
		ansi = max(ansi , ans);
		return;
	}
	if(companies[1] < n / 2){
		companies[1]++;
		dfs(x + 1 , 1 , ans , n);
		companies[1]--;
	}
	if(companies[2] < n / 2){
		companies[2]++;
		dfs(x + 1 , 2 , ans , n);
		companies[2]--;
	}
	if(companies[3] < n / 2){
		companies[3]++;
		dfs(x + 1 , 3 , ans , n);
		companies[3]--;
	}
}
void dfs2(long long x , long long comp , long long ans , long long n){
	if(comp == 1){
		ans += a[x];
	} else if(comp == 2){
		ans += b[x];
	}
	if(x == n){
		ansi = max(ansi , ans);
		return;
	}
	if(companies[1] < n / 2){
		companies[1]++;
		dfs(x + 1 , 1 , ans , n);
		companies[1]--;
	}
	if(companies[2] < n / 2){
		companies[2]++;
		dfs(x + 1 , 2 , ans , n);
		companies[2]--;
	}
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w", stdout);
	int t;
	cin >> t;
	while(t--){
		long long n , b_i = 0 , c_i = 0;
		cin >> n;
		ansi = INT_MIN;
		memset(companies , 0 , sizeof(companies));
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] == 0){
				b_i++;
			}
			if(c[i] == 0){
				c_i++;
			}
		}
		if(n <= 15){
			companies[1]++;
			dfs(1 , 1 , 0 , n);
			memset(companies , 0 , sizeof(companies));
			companies[2]++;
			dfs(1 , 2 , 0 , n);
			memset(companies , 0 , sizeof(companies));
			companies[3]++;
			dfs(1 , 3 , 0 , n);
			cout << ansi << endl;
		} else {
			if(b_i == n and c_i == n){
				sort(a + 1 , a + n + 1 , cmp);
				long long ans = 0;
				for(int i = 1; i <= n / 2; i++){
					ans += a[i]; 
				}
				cout << ans << endl;
			} else if(c_i == n){
				companies[1]++;
				dfs(1 , 1 , 0 , n);
				memset(companies , 0 , sizeof(companies));
				companies[2]++;
				dfs(1 , 2 , 0 , n);
				memset(companies , 0 , sizeof(companies));
				cout << ansi << endl;
			}

		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
bool choose[5005];

long long sum = 0;
void dfs(int step){
	if (step == n+1){
		int m = 0;
		int cnt = 0;
		int maxx = 0;
		for (int i = 1; i <= n; i++){
			if (choose[i] == 1){
				m++;
				cnt += a[i];
				maxx = max(maxx,a[i]);
			}
		}
		if (m >= 3 && cnt > 2*maxx){
			sum++;
		}
		return;
	}
	choose[step] = true;
	dfs(step + 1);
	choose[step] = false;
	dfs(step + 1);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1);
	cout << sum %  998244353;
	return 0; 
}

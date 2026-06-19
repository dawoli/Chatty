#include<bits/stdc++.h>
using namespace std;

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // 需要的木棒数

int T, n;
long long ans;

void dfs(int k, int sum, long long last){
	if(last > ans) return; // 剪枝 
	if(sum < 0) return;
//	printf("%d %d %lld\n", k, sum, last);
	if(sum == 0){
		ans = min(ans, last);
	}
	for(int i=0; i<=9; i++){
		if(k == 1 && i == 0) continue;
		dfs(k+1, sum - num[i], last * 10 + i);
	}
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n <= 50){
			ans = 1e18+5;
			dfs(1, n, 0);
			if(ans == 1e18+5) cout<<-1<<endl;
			else cout<<ans<<endl;
		} else if(n % 7 == 0){
			for(int i=1; i<=(n/7); i++){
				cout<<8;
			} cout<<endl;
		} else if(n % 7 == 1){
			cout<<10;
			for(int i=1; i<=(n/7 - 1); i++){
				cout<<8;
			} cout<<endl;
		} else {
			cout<<"orz"<<endl;
		}
	}
	return 0;
}

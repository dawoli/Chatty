#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int a[N];
bool vis[N];
long long cnt = 0;
void dfs(int sum , int s , int e , int b){
	if(s > e){
		if(sum > 2 * b){
			cnt++;
		}
		return;
	}
	vis[s] = true;
	dfs(sum + a[s] , s + 1 , e , b);
	vis[s] = false;
	dfs(sum , s + 1 , e , b);
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	long long sum = 0;
	for(int i = n; i >= 1; i--){
		cnt = 0;
		dfs(a[i] , 1 , i - 1 , a[i]);
		sum += cnt % 998244353;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

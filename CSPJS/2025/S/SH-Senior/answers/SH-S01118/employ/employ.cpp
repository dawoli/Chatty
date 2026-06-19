#include<bits/stdc++.h>
using namespace std;
struct str{
	int s, c;
}a[505];
int n, m, countOne, used[505], countChaoxiong = 0;
string s;
long long ans;
bool cmp(str x, str y){
	return x.c < y.c;
}
void dfs(int day, int sum, int mad){
	if(sum >= m){
		long long tans = 1;
//		cout<<day<<" ";
		for(int i = n-day+1;i > 1;i--){
			tans  = (tans*i)%(998244353l);
		}
		ans += tans;
		ans %= 998244353;
		return;
	}
	int ifMad = 0;
	if(s[day-1] == '0') ifMad = 1;
	for(int i = 1;i <= n;i++){
		if(used[i]) continue;
		used[i] = 1;
		if(ifMad || mad >= a[i].c){
			dfs(day+1, sum, mad+1);
		}else{
			dfs(day+1, sum+1, mad);
		}
		used[i] = 0;
	}
	if(day > n) return;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 0;i < n;i++){
		countOne += (s[i] == '1');
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i].c;
		if(a[i].c == 0) countChaoxiong++;
//		cout<<a[i].c<<" ";
	}
	sort(a+1, a+n+1, cmp);
	if(m == n){
		cout<<0;
		return 0;
	}
	if(n <= 18){
		dfs(1, 0, 0);
		cout<<ans;
	}else if(countOne){
		ans = 1;
		for(int i = n-countChaoxiong;i > 1;i--){
			ans  = (ans*i)%(998244353l);
//			cout<<ans<<endl;
		}
		cout<<ans;
	}
	return 0;
} 


#include<iostream>
using namespace std;
bool is[505];
int a[505];
long long mod = 998244353, res = 0;
bool book[505];
int tmp[505];
void check(int n, int m){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		int j = tmp[i];
		if(is[i]==0||cnt>=a[j]){
			cnt++;
		}
	}
	if(cnt<=n-m)res++;	
}
void work(int u, int n, int m){
	if(u>n){
		check(n, m);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!book[i]){
			tmp[u] = i;
			book[i] = 1;
			work(u+1, n, m);
			book[i] = 0;
			tmp[u] = 0;
		}
	}
} 
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	int n, m;
	cin >> n >> m;
	if(n<=10){
		for(int i = 1; i <= n; i++){
			char c;
			cin >> c;
			if(c=='1')is[i] = 1;
		}
		for(int i = 1; i <= n; i++)cin >> a[i];
		work(1, n, m);
	}
	cout << res << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

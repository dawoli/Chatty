#include<bits/stdc++.h>

using namespace std;

int X_now = 1, Y_now = 1;
int n, m, a[101]; 
int ans;
bool flag = 0;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; ++i){
		cin >> a[i];
	}
	ans = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 1;
	while(1){
		if(a[cnt] == ans){
			cout << Y_now << " " << X_now;
			return 0;
		}
		if(flag == 0 && X_now == n){
			Y_now++;
			flag = 1;
		}
		else if(X_now == 1 && flag == 1){
			Y_now++;
			flag = 0;
		}
		else{
			if(flag == 0){
				X_now++;
			}
			else{
				X_now--;
			}
		}
		cnt++;
	}
	return 0;
}

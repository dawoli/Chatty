#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int ans[105][105][105];
bool flag[105][105][105];
int f(int now, int prevred, int prevblue){
	if(now == n){
		if(a[now] == prevred){
			return prevred;
		}
		if(a[now] == prevblue){
			return prevblue;
		}
		return 0;
	}
	if(flag[now][prevred][prevblue]){
		return ans[now][prevred][prevblue];
	}
	else{
		if(a[now] == prevred && a[now] != prevblue){
			ans[now][prevred][prevblue] = max(f(now + 1, a[now], prevblue) + a[now], f(now + 1, prevred, a[now]));
		}
		if(a[now] == prevred && a[now] == prevblue){
			ans[now][prevred][prevblue] = max(f(now + 1, a[now], prevblue) + a[now], f(now + 1, prevred, a[now]) + a[now]);
		}
		if(a[now] != prevred && a[now] != prevblue){
			ans[now][prevred][prevblue] = max(f(now + 1, a[now], prevblue), f(now + 1, prevred, a[now]));
		}
		if(a[now] != prevred && a[now] == prevblue){
			ans[now][prevred][prevblue] = max(f(now + 1, a[now], prevblue), f(now + 1, prevred, a[now]) + a[now]);
		}
		flag[now][prevred][prevblue] = 1;
		return ans[now][prevred][prevblue];
	}
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout); 
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++){
		cin >> n;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
		}
		cout << f(2, a[1], 0) << endl;
	}
}

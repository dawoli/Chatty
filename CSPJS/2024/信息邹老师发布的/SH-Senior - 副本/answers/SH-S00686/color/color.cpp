#include<bits/stdc++.h>
using namespace std;

int T;
int n;
int a[200010];
bool r[200010];
int ans;

void check() {
	int temp = 0;
	for(int i = 2; i <= n; i++) {
		for(int j = i - 1; j > 0; j--) {
			if(r[i] == r[j]) {
				if(a[i] == a[j]) temp += a[i];
				break;
			}
		}
	}
	ans = max(temp , ans);
	return;
}

void dfs(int cur , int c) {
	r[cur] = c;
	if(cur == n){
		check();
		return;
	}
	dfs(cur + 1 , c);
	dfs(cur + 1 , !c);
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T--) {
		ans = 0;
		cin >> n;
		memset(a,0,sizeof(a));
		memset(r,0,sizeof(r));
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		dfs(1 , 0);//0表示红色 
		dfs(1 , 1);//1表示蓝色 
		
		cout << ans << endl;
	}
	
	return 0;
}

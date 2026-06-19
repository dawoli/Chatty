//TLE
//20pts
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

int T, ans, a[N];
int c[N]; //0表红色,1表蓝色 
vector<int> res;

void dfs(int depth, int n){
	if(depth == n){ //涂完所有色了
		int ac = 0;
		for(int i = 1; i <= n ; i ++ ){
			for(int j = i - 1; j >= 1; j -- ){
				if(c[i] != c[j]){
					if(a[i] == a[j]) ac += a[i];
				}
			}
		}
		ans = max(ans, ac);
		return;
	}
	dfs(depth + 1, n); //染红
	c[depth + 1] = 1; //染蓝
	dfs(depth + 1, n);
	c[depth + 1] = 0; //恢复现场 
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while(T -- ){
		ans = -114514;
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++ ){
			cin >> a[i];
		}
		dfs(0, n);
		res.push_back(ans);
	}
	for(int i = 0; i < res.size(); i ++ ){
		cout << res[i] << endl; 
	}
	return 0;
}

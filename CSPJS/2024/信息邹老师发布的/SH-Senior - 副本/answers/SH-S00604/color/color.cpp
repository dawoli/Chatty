#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int t,n,a[N],c[N],cnt,ans;
vector<string> path;
string xxx[2] = {"ºìÉ«","À¶É«"};
void dfs(int now){
	if(now == n){
		c[0] = 0;
		for (int i = 1 ; i < n ; i ++ ) {
			bool flag = 1;
			for (int j = 0 ; j < i ; j ++ ) {
				if (path[i] != path[j])	flag = 0;
				else{
					if (a[i] != a[j])	c[i] = 0;
					else c[i] = a[i];
					flag = 1;
				}
			}
			if(flag == 0)	c[i] = 0;
		}
		for (int i = 0 ; i < n ; i ++ )	cnt += c[i];
		ans = max(ans,cnt);
		return ;
	}
	path.push_back(xxx[0]);
	dfs(now + 1);
	path.pop_back();
	path.push_back(xxx[1]);
	dfs(now + 1);
	path.pop_back();
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while (t -- ) {
		int cnt = 0,ans = -0x3f3f3f3f;
		cin >> n;
		for (int i = 0 ; i < n ; i ++ )	cin >> a[i];
		dfs(1);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

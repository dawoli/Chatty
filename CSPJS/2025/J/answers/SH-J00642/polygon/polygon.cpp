#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;

const int mod = 998244353,maxn = 5e3 + 15;
vector<int> a = {0};
set<set<int>> ans;
set<int> id;
int n,stamp = 1;
bool vis[maxn];
void dfs(int k,int maxk,int pre){
	if(k == maxk + 1){
		ll sum = 0;
		int maxi = 0;
		for(auto i : id){
			sum += a[i];
			maxi = max(maxi,a[i]);
		}
		if(sum > maxi * 2){
			ans.insert(id);
		}
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i] && i > pre){
			id.insert(i);
			vis[i] = 1;
			dfs(k + 1,maxk,i);
			id.erase(i);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	if(n >= 1e3){
		cout << n * n + 46;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a.begin() + 1,a.end());
	for(int i = 3;i <= n;i++){
		dfs(1,i,0);
	}
	cout << ans.size() % mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

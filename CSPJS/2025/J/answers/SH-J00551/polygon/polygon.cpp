#include <bits/stdc++.h>
using namespace std;
long long cnt = 0;
int n,a[500005];
bool aaa = true;
void dfs(int dep,int sum,int maxn,int i){
	if(!aaa){
		if(i > n+1){
			return;
		}
	}
	if(dep >= 3 && sum > maxn * 2){
		cnt++;
		aaa = false;
		dfs(dep + 1,sum + a[i],max(maxn,a[i]),i+1);
		aaa = true;
		return;
	}
	if(i > n){
		return;
	}
	dfs(dep + 1,sum + a[i],max(maxn,a[i]),i+1);
	dfs(dep,sum,maxn,i+1);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(0,0,0,1);
	cout << cnt % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

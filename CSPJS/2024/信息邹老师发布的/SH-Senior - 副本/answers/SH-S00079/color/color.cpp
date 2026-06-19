#include <iostream>
#include <cstdio>
using namespace std;
int T,N,a[25],maxn,k[25];
void dfs(int step,int last1,int last2,int ans1,int ans2){
	if(step == N + 1){
		maxn = max(maxn,ans1 + ans2);
		return;
	}
	int x = 0,y = 0;
	if(a[step] == a[last1]) x = a[step];
	dfs(step + 1,step,last2,ans1 + x,ans2);
	if(a[step] == a[last2]) y = a[step];
	dfs(step + 1,last1,step,ans1,ans2 + y);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> T;
	while(T--){
		maxn = 0;
		cin >> N;
		for(int i = 1;i <= N;i++)
			cin >> a[i];
		k[1] = 1;
		dfs(2,1,0,0,0);
		k[1] = 2;
		dfs(2,0,1,0,0);
		cout << maxn << endl;
	}
	return 0;
}

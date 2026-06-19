#include <bits/stdc++.h>
using namespace std;
int ans=0,n=0,nn=0,j1=0,j2=0,j3=0;
int a[100010][4];
void dfs(int dep,int anw){
	if(dep > n)
		if(anw > ans){
			ans = anw;
			return;
		}
	if(j1 > nn || j2 > nn || j3 > nn) return;
	j1++;
	dfs(dep+1,anw+a[dep][1]);
	j1--;
	
	j2++;
	dfs(dep+1,anw+a[dep][2]);
	j2--;
	
	j3++;
	dfs(dep+1,anw+a[dep][3]);
	j3--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin >> t;
	for(int T=0;T < t;T++){
		cin >> n;
		nn = n/2;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1,0);
		cout << ans;
		ans = 0;
		for(int i = 0;i < n;i++){
			a[i][1] = 0;
			a[i][2] = 0;
			a[i][3] = 0;
		}
	}
	return 0;
}

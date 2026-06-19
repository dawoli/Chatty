#include <bits/stdc++.h>
using namespace std;
int nn=0;
long long anns=0;
int l[5010]={0};
int dis[5010][5010];
void dfs(int he,int r,int mx,int mi,int num){
	if(r > nn){
		return;
	}
	if(num == 1){
		mi = mx;
	}
	if(num >= 3 && he > 2 * l[mx]){
		anns++;
		dis[mi][mx] = 1;
		anns %= 998244353;
	}
	r++;
	dfs(he + l[r],r,r,mi,num+1);
	dfs(he,r,mx,mi,num);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> nn;
	for(int i = 1;i <= nn;i++) cin >> l[i];
	sort(l+1,l+nn+1);
	dfs(0,0,1,1,0);
	cout << anns - 2;
	return 0;
}

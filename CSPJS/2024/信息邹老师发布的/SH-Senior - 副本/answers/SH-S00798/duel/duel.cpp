#include<bits/stdc++.h>
using namespace std;
int n, num[100002], mx, rem, tmp;
int main(){
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> tmp;
		num[tmp]++, mx = max(mx, tmp);
	}
	for(int i = 1; i <= mx; ++i)
		if(num[i])
			rem = max(rem, num[i]);
	cout << rem << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//这不就是众数个数吗。。。 
//最简单的一集 

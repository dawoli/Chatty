#include <bits/stdc++.h>
using namespace std;
int st[5005];
int stqzh[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> st[i];
		stqzh[i] = stqzh[i-1] + st[i];
	}
	int ffs = 0;
	sort(st+1,st+n+1);
	    for (int i = 1;i <= n;i++){
		    int l = i,r = l;
		for (int j = r;j <=n;j++){
		   int zcd = stqzh[j] -stqzh[l-1];
		   int maxcd = st[j];
		   if (zcd >maxcd*2) ffs++;
	    }
	}
	bool ad = 1;
	for (int i = 1;i <= n;i++){
		if (st[i] != 1) ad =0;
	}
	int ans2 = 0,ans3 = 0;
	for (int i = 3;i <=n ;i++){
		int ans = 1;
		for (int j = 1;j<= n;j++){
			ans *= j;
		}
		ans2 = ans;
		ans = 1;
		for (int j = 1; j<= i;j++){
			ans *= j;
		}
		ans2 /= ans;
		ans3 += ans2;
	}
	if(!ad) cout << ffs;
	else cout << ans3;
	return 0;
}

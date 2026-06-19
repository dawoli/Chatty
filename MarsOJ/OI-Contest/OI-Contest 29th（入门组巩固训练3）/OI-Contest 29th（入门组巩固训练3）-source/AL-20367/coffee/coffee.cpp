#include <bits/stdc++.h>
using namespace std;
int a[6],sum[6];
int main(){
//	freopen("coffee.in","r",stdin);
//	freopen("coffee.out","w",stdout);
	string t;
	int q;
	cin >> q;
	while(q --){
		memset(a,0,sizeof(a));
		sum[0] = 0;
		int s = 0;
		for(int i = 1;i <= 5;i ++){
			int ans = 0;
			for(int j = 0;j < 8;j ++){
				cin >> t;
				if(t == "math"){
					ans ++;
				}
			}
			a[i] = ans;
			s += ans;
			sum[i] = sum[i - 1] + a[i];
		}	
		int n,m;
		cin >> n >> m;
		if(m == 6) n --;
		if(m == 7) n -= 2;
		if(m == 6 || m == 7) m = 1;
		int ans = s * n / 7 + sum[m - 1];
		cout << ans << endl;
	}
	return 0;
}











#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n, a[200001], dp[200001][2], red[200001][2], blue[200001][2];
int main() {
	freopen ("color.in", "r", stdin);
	freopen ("color.out", "w", stdout);
	cin >> t;
	for (ll o = 1; o <= t; o++) {
		cin >> n;
		for (ll j = 1; j <= n; j++) {
			cin >> a[j];
		}
		
		dp[1][0] = 0; dp[1][1] = 0; 
		red[1][0] = a[1]; red[1][1] = 0;
		blue[1][0] = 0; blue[1][1] = a[1];
		
		for (ll i = 2; i <= n; i++) {
			ll x1 = dp[i-1][0], x2 = dp[i-1][1];
			//ll y1 = dp[i-1][1], y2 = dp[i-1][1]; //x1为i&i-1都取红时， x2为i取红,i-1取蓝时，y1为i取蓝,i-1取红时，y2为i&i-1都取蓝时 
			/*
			if(a[i] == red[i-1][0]) x1 += red[i-1][0];
			if(a[i] == blue[i-1][0]) x2 += blue[i-1][0]; 
			if(a[i] == red[i-1][1]) y1 += red[i-1][1];
			if(a[i] == blue[i-1][1]) y2 += blue[i-1][1];
			cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << endl;
			
			dp[i][0] = max(x1, x2);
			red[i][0] = a[i];
			if (x1>=x2) red[i][1] = red[i-1][1];
			else red[i][1] = a[i-1];
			
			dp[i][1] = max(y1, y2);
			blue[i][1] = a[i];
			if (y1>y2) blue[i][0] = a[i-1];
			else blue[i][0] = blue[i-1][0];
			*/
			ll ansr1=0, ansr2=0, ansb1=0, ansb2=0;
			
			red[i][1] = red[i-1][1];
			blue[i][0] = red[i-1][0];
			if (a[i] == red[i][1]) ansr1 = x1+red[i][1];
			if (a[i] == blue[i][0]) ansb1 = x2+blue[i][0];

			red[i][1] = blue[i-1][1];
			blue[i][0] = blue[i-1][0];
			if (a[i] == red[i][1]) ansr2 = x1+red[i][1];
			if (a[i] == blue[i][0]) ansb2 = x2+blue[i][0];
			
			dp[i][0] = max(ansr1, ansr2);
			dp[i][1] = max(ansb1, ansb2);
			//
			if (ansr1 > ansr2) red[i][1] = red[i-1][1];
			if (ansb1 > ansb2) blue[i][0] = red[i-1][0];
			
			//test
			//cout << "dp: " << dp[i][0] << ' ' << dp[i][1] << " red: " << red[i][0] << ' ' << red[i][1] << " blue: " << blue[i][0] << ' ' << blue[i][1] << endl; 
		}
		cout << max(dp[n][0], dp[n][1]) << endl;
	}
	return 0;
}

/*  a[i] i是什么数 
	dp[i][0/1]: 当第i个数为红色/蓝色时最大的值
	red[i][0/1]: 0时为i取红最大值时最近涂红的（即i）,1时为i取红最大值是最近涂蓝的； blue[i][0/1]同理 
	ll x1 = x2 = dp[i-1][0], y1 = y2 = dp[i-1][1]; //x1为i&i-1都取红时， x2为i取红,i-1取蓝时，y1为i取蓝,i-1取红时，y2为i&i-1都取蓝时 
	
	if(a[i] == red[i-1][0]) x1 += red[i-1][0];
	if(a[i] == blue[i-1][0]) x2 += blue[i-1][0]; 
	if(a[i] == red[i-1][1]) y1 += red[i-1][1];
	if(a[i] == blue[i-1][1]) y2 += blue[i-1][1];
	
	dp[i][0] = max(x1, x2);
	red[i][0] = a[i];
	if (x1>=x2) red[i][1] = red[i-1][1];
	else red[i][1] = a[i-1];
	
	dp[i][1] = max(y1, y2);
	blue[i][1] = a[i];
	if (y1>y2) blue[i][0] = a[i-1];
	else blue[i][0] = blue[i-1][0]; 
	
	
	边界:dp[1][0] = 0; dp[1][1] = 0; 
		 red[1][0] = a[1]; red[1][1] = 0;
		 blue[1][0] = 0; blue[1][1] = a[i];
		 
		 
*/	
